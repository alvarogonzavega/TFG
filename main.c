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

          int pfds[2];
          int pfds2[2];
          int stdin_copy = dup(0);
          int stdout_copy = dup(1);


          if (pipe(pfds) == -1) {
              perror("Error during pipe() function.");
              exit(-1);
            }

            if (strcmp(cmd.argv[0][0],"exit")==0) exitFunc();
						if(strcmp(cmd.argv[0][0], "tutorial")==0) tutorial(cmd.argv[0][1], commands);


        /*We make sure there are no zombie processes waiting for PID=-1*/
          waitpid(-1, NULL, WNOHANG);
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
                   if (1 == 3) {
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
				                            if(cmd.filev[0] != NULL){
					                                 close(STDIN_FILENO);
					                                 open(cmd.filev[0], O_RDONLY);
			                              } /*We redirect the standard input*/
				                            if(cmd.filev[2] != NULL){
					                                 close(STDERR_FILENO);
					                                 open(cmd.filev[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
			                               } /*We redirect the standard error*/

                                     if(execvp(cmd.argv[0][0], cmd.argv[0])==-1) levenshtein(cmd.argv[0][0], commands);
                                     default:
                                    /*Parent process*/
                                    DoublePipe = waitpid(DoublePipe, NULL,0);
                                    /*Receive data from pipe*/
                                    dup2(pfds2[0], STDIN_FILENO);
                                    dup2(pfds[1], STDOUT_FILENO);
                                    close(pfds2[0]);
                                    close(pfds2[1]);
				                            if(cmd.filev[2] != NULL){
					                                 close(STDERR_FILENO);
					                                 open(cmd.filev[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
			    	                        }
                                    if(execvp(cmd.argv[1][0], cmd.argv[1])==-1) levenshtein(cmd.argv[1][0], commands);
                            }
                        default:
                            childSimplePipe = waitpid(childSimplePipe, NULL,0);
                            dup2(pfds[0], STDIN_FILENO);
                            close(pfds[0]);
                            close(pfds[1]);
		                        if(cmd.filev[1] != NULL){
				                          close(STDOUT_FILENO);
				                          open(cmd.filev[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
			                      } /*We redirect the standard output*/
                            if(cmd.filev[2] != NULL){
				                          close(STDERR_FILENO);
				                          open(cmd.filev[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
			                      }
                            if(execvp(cmd.argv[2][0], cmd.argv[2])==-1) levenshtein(cmd.argv[2][0], commands);
                          }
                        }
                if (1 == 2) {
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
			                      if(cmd.filev[0] != NULL){
				                          close(STDIN_FILENO);
				                          open(cmd.filev[0], O_RDONLY);
			                      }
                            if(cmd.filev[2] != NULL){
				                          close(STDERR_FILENO);
				                          open(cmd.filev[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
			                      }
                            if(execvp(cmd.argv[0][0], cmd.argv[0])==-1) levenshtein(cmd.argv[0][0], commands);
                        default:
                            /*Parent process*/
                            childSimplePipe = waitpid(childSimplePipe, NULL,0);
                            /*Receive data from pipe*/
                            dup2(pfds[0], STDIN_FILENO);
                            close(pfds[1]);
			                      if(cmd.filev[1] != NULL){
				                          close(STDOUT_FILENO);
				                          open(cmd.filev[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
			                      }
                            if(cmd.filev[2] != NULL){
				                          close(STDERR_FILENO);
				                          open(cmd.filev[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
			                      }
                            if(execvp(cmd.argv[1][0], cmd.argv[1])==-1) levenshtein(cmd.argv[1][0], commands);
                    }
                }
                if (1 == 1) {
                    if(cmd.filev[0] != NULL){
			                   close(STDIN_FILENO);
			                   open(cmd.filev[0], O_RDONLY);
		                }
		                if(cmd.filev[1] != NULL){
			                   close(STDOUT_FILENO);
			                   open(cmd.filev[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
		                }
                    if(cmd.filev[2] != NULL){
			                   close(STDERR_FILENO);
			                   open(cmd.filev[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
		                }
                    if(execvp(cmd.argv[0][0], cmd.argv[0])==-1) levenshtein(cmd.argv[0][0], commands);
                    exit(0);
                }
            default:
                /*Parent process*/
                if (!cmd.bg) {
                    if (1 == 2) {
                        close(pfds[0]);
                        close(pfds[1]);
                    }
                    if (1 == 3) {
                        close(pfds[0]);
                        close(pfds[1]);
                    }
                    childPid = waitpid(childPid, NULL,0);
                    printf("Wait child %d\n", childPid);
                } else {
                    if (1 == 2) {
                        close(pfds[0]);
                        close(pfds[1]);
                    }
                    if (1 == 3) {
                        close(pfds[0]);
                        close(pfds[1]);
                        close(pfds2[0]);
                        close(pfds2[1]);
                    }
                    printf("[%d]\n", childPid);
                }



    } /*fin while*/


  } /*end main*/

  return 0;

}
