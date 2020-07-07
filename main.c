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
#include <sys/types.h>
#include <sys/wait.h>
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

void execute(Command cmd){

	waitpid(-1, 0, WNOHANG);
	for(int i=0; i<cmd.pipes; i++){

		int j=0;
		while(cmd.argv[i][j]!=NULL){

			 if(strlen(cmd.argv[i][j])==0)
			  cmd.argv[i][j] = NULL;
			 j++;

		 }

	 }

	if(cmd.pipes>1){

		int pfd[2];
		if(pipe(pfd)<0) exit(-1);

	}

	for(int i=0; i<cmd.pipes; i++){

		pid_t pid;
		pid=fork();
		if(pid<0) exit(-1);
		else if(pid==0){

			//close(pfd[0]);
			//dup2(pfd[1], STDOUT_FILENO);
			//close(pfd[1]);
			if(cmd.filev[0]!=NULL && i==0){

				close(STDIN_FILENO);
				//open(filev[0], )

			}

		}

	}

}


int main(void) {

		setbuf(stdout, NULL);            /* Unbuffered */
  	setbuf(stdin, NULL);

    while (1) {

			int special=0;
			Command cmd;
			for(int i=0; i<3; i++) cmd.filev[i] = malloc(100);
			//reinitialize(cmd.argv, cmd.pipes, cmd.filev, cmd.bg);
			fprintf(stdout, "%s", "esh> ");    /* Prompt */
			getLine();
			cmd=get_order(line, cmd);
      if(strcmp(cmd.argv[0][0],"exit")==0) exitFunc();
			if(strcmp(cmd.argv[0][0], "tutorial")==0){ tutorial(cmd.argv[0][1], commands); special=1; }
			if(special==0) execute(cmd);


			}

		}
