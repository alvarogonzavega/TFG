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

char * line;

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
	freeC(line);

}

char* getLine(void){

	//We reserve 500 bytes of chars in the memory
	line = malloc(500 * sizeof(char));
	int pos = 0; //Counter of bytes
	int c;
	if(!line){

		//If we don´t have enough space on the memory
		fprintf(stderr, "esh: Error in the allocation!!");
		exit(-1);

	}

	while(1){

		//Infinite loop
		c = getchar(); //We get the character
		if(c == EOF || c == '\n'){

			//If we reach the end of the command
			line[pos] = '\n';
			//We add the new line character at the end of the char and we return it
			return line;

		}else{

			//We add the character in the position
			line[pos] = c;

		}

		pos++; //We increment the counter
		if(pos>500){

			//If the command is longer than 500 bytes
			fprintf(stderr, "esh: Command too long!!");
			exit(-1);

		}

	}

}


void exitFunc(){
 /*   free_command(&cmd); */
    printf("\nGoodbye!\n");
    exit(0);
}


int main(void) {

		Command cmd;
		for(int i=0; i<3; i++) cmd.filev[i] = malloc(100);
		setbuf(stdout, NULL);            /* Unbuffered */
  	setbuf(stdin, NULL);

    while (1) {

			int special=0;
			reinitialize(cmd.argv, cmd.pipes, cmd.filev, cmd.bg);
			fprintf(stdout, "%s", "esh> ");    /* Prompt */
			getLine();
			cmd=get_order(line, cmd);
      int pfds[2*MAX_N_PIPES];
      if(pipe(pfds) == -1) exit(-1);
      if(strcmp(cmd.argv[0][0],"exit")==0) exitFunc();
			if(strcmp(cmd.argv[0][0], "tutorial")==0){ tutorial(cmd.argv[0][1], commands); special=1; }
			if(special==0){

        /*We make sure there are no zombie processes waiting for PID=-1*/
				waitpid(-1, 0, WNOHANG);
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

		}
