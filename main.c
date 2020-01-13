/*-
 * wsh
 *
 * Wshell C source
 * Show how to use "obtain_order" input interface function
 *
 * THIS FILE IS TO BE MODIFIED
 */

#include <stddef.h>            /* NULL */
#include <stdio.h>            /* setbuf, printf */
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#define MAX_VALUE 20

time_t start_t;
extern int get_order();        /* See parser.c for description */

struct command {
    /* Store the number of commands in argvv */
    int num_commands;
    /* Store the number of arguments of each command */
    int *args;
    /* Store the commands */
    char ***argvv;
    /* Store the I/O redirection */
    char *filev[3];
    /* Store if the command is executed in background or foreground */
    int bg;
};

void store_command(char ***argvv, char *filev[3], int bg, struct command *cmd, int c) {
    if(c==MAX_VALUE){
	for(int i=0; i<(MAX_VALUE-1); i++){ /* We move the structure one position backwards */
	   int w = i+1;
	   cmd[i].num_commands = cmd[w].num_commands;
	   cmd[i].bg = cmd[w].bg;
	   for(int a=0;a<3;a++){
		cmd[i].filev[a] = cmd[w].filev[a];
	   }
	   cmd[i].argvv = cmd[w].argvv;
	   cmd[i].args = cmd[w].args;
	   for(int y=0; y<cmd[w].num_commands; y++){
		cmd[i].args[y] = cmd[w].args[y];
		cmd[i].argvv[y] = cmd[w].argvv[y];
		for(int x=0; x<cmd[w].args[y]; x++){
		    cmd[i].argvv[y][x] = cmd[w].argvv[y][x];
		}
	   }
	}
	c--;
    }
    int num_commands = 0;
    while (argvv[num_commands] != NULL) {
        num_commands++;
    }
    int f;
    for(f=0; f<3; f++){
	if(filev[f]!=NULL){
        	cmd[c].filev[f] = (char *) calloc(strlen(filev[f]),sizeof(char));
        	strcpy(cmd[c].filev[f], filev[f]);
    }else{
		cmd[c].filev[f] ="\0"; /* To have al the filev elements pointing to accesible memory*/
	}
}
    cmd[c].bg = bg;
    cmd[c].num_commands = num_commands;
    cmd[c].argvv = (char ***) calloc((num_commands + 1),sizeof(char **));
    cmd[c].args = (int *) calloc(num_commands,sizeof(int));
    int i;
    for (i = 0; i < num_commands; i++) {
        int args = 0;
        while (argvv[i][args] != NULL) {
            args++;
        }
        cmd[c].args[i] = args;
        cmd[c].argvv[i] = (char **) calloc((args + 1), sizeof(char *));
        int j;
        for (j = 0; j < args; j++) {
            cmd[c].argvv[i][j] = (char *) calloc(strlen(argvv[i][j]), sizeof(char));
            strcpy(cmd[c].argvv[i][j], argvv[i][j]);
        }
    }
}


void print_command(int ** c){

  for(int i=0; i<c[0]; i++){

    for(int j=0; j<c[1]; j++){

  //    printf("%s\n", argvv[i][j]);

    }

    printf("\nPIPE\n");

  }

}


int main(void) {
    char ***argvv;
    int command_counter = 0;
    int num_commands;
    int args_counter;
    char *filev[3];
    int bg;
    int ret;
    struct command cmd[MAX_VALUE];
    int c=0;

    setbuf(stdout, NULL);            /* Unbuffered */
    setbuf(stdin, NULL);

    while (1) {
        fprintf(stderr, "%s", "wsh> ");    /* Prompt */
        ret = get_order(&argvv, filev, &bg);
        print_command(ret);
	if(argvv!=NULL) store_command(argvv, filev, bg, cmd, c);
        if (ret == 0) break;        /* EOF */
        if (ret == -1) continue;    /* Syntax error */
        num_commands = ret - 1;        /* Line */
        if (num_commands == 0) continue;   /* Empty line */
        int pfds[2];
        int pfds2[2];
        int stdin_copy = dup(0);
        int stdout_copy = dup(1);


        if (pipe(pfds) == -1) {
            perror("Error during pipe() function.");
            exit(-1);
        }



        /*We make sure there are no zombie processes waiting for PID=-1*/
        waitpid(-1, NULL, WNOHANG);
        int usedPipe = num_commands - command_counter;
        pid_t childPid, childSimplePipe, DoublePipe;
        childPid = fork();
        switch (childPid) {
            case -1:
                /*Error in fork*/
                perror("Error during fork() function.");
                exit(-1);
            case 0:
                /*Child process*/
	        printf("child %d\n", getpid());
                if (num_commands == 3) {
                    childSimplePipe = fork();
                    switch (childSimplePipe) {
                        case -1:
                            /*Error in fork*/
                            perror("Error during fork() function.");
                            exit(-1);
                        case 0:
                            if (pipe(pfds2) == -1) {
                                perror("Error during pipe() function.");
                                exit(-1);
                            }
                            DoublePipe = fork();
                            switch (DoublePipe) {
                                case -1:
                                    /*Error in fork*/
                                    perror("Error during fork() function.");
                                    exit(-1);
                                case 0:
                                    /*Child process*/
                                    /*Prepare pipe*/
                                    dup2(pfds2[1], STDOUT_FILENO);
                                    close(pfds2[0]);
                                    close(pfds2[1]);
				    if(filev[0] != NULL){
					close(STDIN_FILENO);
					open(filev[0], O_RDONLY);
			            } /*We redirect the standard input*/
				    if(filev[2] != NULL){
					close(STDERR_FILENO);
					open(filev[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
			            } /*We redirect the standard error*/

                                    execvp(argvv[0][0], argvv[0]);
                                default:
                                    /*Parent process*/
                                    DoublePipe = waitpid(DoublePipe, NULL,0);
                                    /*Receive data from pipe*/
                                    dup2(pfds2[0], STDIN_FILENO);
                                    dup2(pfds[1], STDOUT_FILENO);
                                    close(pfds2[0]);
                                    close(pfds2[1]);
				    if(filev[2] != NULL){
					close(STDERR_FILENO);
					open(filev[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
			    	    }
                                    execvp(argvv[1][0], argvv[1]);
                            }
                        default:
                            childSimplePipe = waitpid(childSimplePipe, NULL,0);
                            dup2(pfds[0], STDIN_FILENO);
                            close(pfds[0]);
                            close(pfds[1]);
		            if(filev[1] != NULL){
				close(STDOUT_FILENO);
				open(filev[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
			    } /*We redirect the standard output*/
                            if(filev[2] != NULL){
				close(STDERR_FILENO);
				open(filev[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
			    }
                            execvp(argvv[2][0], argvv[2]);
                    }
                }
                if (num_commands == 2) {
                    /*If we have a simple pipe*/
                    pid_t childSimplePipe = fork();
                    switch (childSimplePipe) {
                        case -1:
                            /*Error in fork*/
                            perror("Error during fork() function.");
                            exit(-1);
                        case 0:
                            /*Child process*/
                            /*Prepare pipe*/
                            dup2(pfds[1], STDOUT_FILENO);
                            close(pfds[0]);
			    if(filev[0] != NULL){
				close(STDIN_FILENO);
				open(filev[0], O_RDONLY);
			    }
                            if(filev[2] != NULL){
				close(STDERR_FILENO);
				open(filev[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
			    }
                            execvp(argvv[0][0], argvv[0]);
                        default:
                            /*Parent process*/
                            childSimplePipe = waitpid(childSimplePipe, NULL,0);
                            /*Receive data from pipe*/
                            dup2(pfds[0], STDIN_FILENO);
                            close(pfds[1]);
			    if(filev[1] != NULL){
				close(STDOUT_FILENO);
				open(filev[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
			    }
                            if(filev[2] != NULL){
				close(STDERR_FILENO);
				open(filev[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
			    }
                            execvp(argvv[1][0], argvv[1]);
                    }
                }
                if (num_commands == 1) {
                    if(filev[0] != NULL){
			close(STDIN_FILENO);
			open(filev[0], O_RDONLY);
		    }
		    if(filev[1] != NULL){
			close(STDOUT_FILENO);
			open(filev[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
		    }
                    if(filev[2] != NULL){
			close(STDERR_FILENO);
			open(filev[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
		    }
                    execvp(argvv[0][0], argvv[0]);
                    exit(0);
                }
            default:
                /*Parent process*/
                if (!bg) {
                    if (num_commands == 2) {
                        close(pfds[0]);
                        close(pfds[1]);
                    }
                    if (num_commands == 3) {
                        close(pfds[0]);
                        close(pfds[1]);
                    }
                    childPid = waitpid(childPid, NULL,0);
		    if(c<MAX_VALUE) c++;
                    printf("Wait child %d\n", childPid);
                } else {
                    if (num_commands == 2) {
                        close(pfds[0]);
                        close(pfds[1]);
                    }
                    if (num_commands == 3) {
                        close(pfds[0]);
                        close(pfds[1]);
                        close(pfds2[0]);
                        close(pfds2[1]);
                    }
		    if(c<MAX_VALUE) c++;
                    printf("[%d]\n", childPid);
                }


        }
    } /*fin while*/

    return 0;

} /*end main*/
