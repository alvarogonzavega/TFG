/*-
 *
 * esh
 * Eshell C source
 *
 */

#include <stddef.h>            /* NULL */
#include <stdio.h>            /* setbuf, printf */
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include "suggestions.h"
#include "tutorial.h"
#include "parser.h"

#define SIZE 1024

char *commands[] = {"pwd","ls","cd","mkdir","rmdir","lsblk","mount","df",
"uname","ps","kill","service","batch","shutdown","touch","cat","head",
"tail","cp","mv","comm","less","ln","cmp","dd","alias","cal","fortune",
"history","yes","banner","rev","wget","iptables","traceroute","curl",
"find","which","locate","grep","sed","clear","echo","sort","sudo",
"chmod","chown","man","tar","whatis"};


typedef struct{

	char ***argv;
	int pipes;
	char *filev[3];
	int bg;

}Command;

#define freeC(c) { if(c){ free(c); c=NULL; }}
//To free the space allocated in the memory


void reinitialize(char ***argv, int pipes, char *filev[3], int bg){

	//Whenever we pass a new command we need to free all the space allocated
	// and put all the variables to 0
	freeC(argv);
	freeC(filev[0]);
	freeC(filev[1]);
	freeC(filev[2]);
	bg = 0;
	pipes=0;

}


void exitFunc(){
 /*   free_command(&cmd); */
    printf("\nGoodbye!\n");
    exit(0);
}


int main(void) {

		Command cmd;
		setbuf(stdout, NULL);            /* Unbuffered */
    setbuf(stdin, NULL);

    while (1) {

				reinitialize(cmd.argv, cmd.pipes, cmd.filev, cmd.bg);
				fprintf(stderr, "%s", "esh> ");    /* Prompt */
				get_order(cmd.argv, cmd.pipes, cmd.filev, cmd.bg);
        int pfds[2*MAX_N_PIPES];
      	if(pipe(pfds) == -1) exit(-1);
        if(strcmp(cmd.argv[0][0],"exit")==0) exitFunc();
				if(strcmp(cmd.argv[0][0], "tutorial")==0) tutorial(cmd.argv[0][1], commands);

        /*We make sure there are no zombie processes waiting for PID=-1*/
        waitpid((pid_t)-1, 0, WNOHANG);
				pid_t pid;
				for(int i=0; i<MAX_N_PIPES; i++){

					pid=fork();
					if(pid==-1) exit(-1);
					else if(pid==0){

						dup2(pfds[i*2+1], STDOUT_FILENO);
						close(pfds[i*2]);
						if(cmd.filev[0]!=NULL && i==0){

							close(STDIN_FILENO);
							open(cmd.filev[0], O_RDONLY);

						}

						if(cmd.filev[2]!=NULL){

							close(STDERR_FILENO);
							open(cmd.filev[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);

						}

						if(execvp(cmd.argv[i][0], cmd.argv[i])==-1) levenshtein(cmd.argv[i][0], commands);


					}else{

						if(cmd.bg==0) waitpid(pid, 0, 0); //If not run in background
						dup2(pfds[i*2], STDIN_FILENO);
						close(pfds[i*2+1]);
						if(cmd.filev[1]!=NULL && i==(MAX_N_PIPES-1)){

							close(STDOUT_FILENO);
							open(cmd.filev[0], O_CREAT | O_TRUNC | O_WRONLY, 0666);

						}

						if(cmd.filev[2]!=NULL){

							close(STDERR_FILENO);
							open(cmd.filev[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);

						}

						if(execvp(cmd.argv[i][0], cmd.argv[i])==-1) levenshtein(cmd.argv[i][0], commands);

					}

				}


			}

		}
