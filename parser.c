#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

char ***argv;
int argvc;
int argc;
char *filev[3];
int bg;
int pos;


int getNewC(char *arg){

	//To count all the chars whenever we separate the char (pipeline or ;)
	int y =0;
	while(arg[y]){

		y++;

	}

	return y;

}



char *getRedir(char *arg, int y){

	//If we get an std symbol (>, <, >&) we need to get the filep
	// where we wanna redirect
	char *redir = malloc(100*sizeof(char));
	int z=0;
	// We reserve 100 bytes to store the redirection
	for(;y<pos; y++){

		//We start to read after we found the redirect symbol
		if(arg[y]!=' ' && arg[y]!='\n' && arg[y]!=BG){

			//We do not wanna store the bg sign, blank spaces
			// or new line chars (as they indicate the end of the char*)
			redir[z]=arg[y];
			z++;

			}

	}

	return redir;

}


void command(char *arg){

	int c = 0; int a=0;
	char y;
	argv[argvc][argc] = malloc(sizeof(char)*500);
	//We reserve 500 bytes of memory to sore the command
	if(arg[0]==' ') c++;
	if(arg[pos]==' ') pos--;
	//If we get a blank space at the start or the end we eliminate them
	while(c<pos){

		//While we get chars to read
		y = arg[c];
Start:
		//Start tag, we go here after a blank space (as we don´t store blanks)
		if(y==BG && arg[c-1] != OUT){ bg=1; goto End; }
		//We have a bg symbol (&). We will execute the command on the background
		if(y==IN){

			//We have an input redirection(<)
			filev[0] = getRedir(arg, c+1);
			//We pass the char* and the position inmediatly after the symbol
			c+=strlen(filev[0]);
			//We add al the chars to the counter as we don´t wanna store it
			goto End;
			//We go to the End tag to read the next char

		}

		if(y==OUT && arg[c+1] != BG){

			//We have an output redirection(>) and the next position is not &
			// as that is the error redirection
			filev[1] = getRedir(arg, c+1);
			c+=strlen(filev[1]);
			goto End;

			}

		if(y==BG && arg[c-1] == OUT){

			//We have the ampersand(&) and the previous char is the >
			// this is the error redirection
			filev[2] = getRedir(arg, c+1);
			c+=strlen(filev[2]);
			goto End;

		}

		if(y==' '){

			//When we find a blank space
			argc++;
			//We increment the args number
			a=0;
			//We use a as counter after a blank space, so when we find a blank
			// we put it back to 0
			argv[argvc][argc] = malloc(sizeof(char)*250);
			//We reserve 250 bytes of memory to allocate the command
			y=arg[c+1];
			//We are going to read the next character
			c++;
			//We increment the counter
			goto Start;
			//We go to the start tag to start reading the next character

		}

		argv[argvc][argc][a] = y;
		//We store the character on the argv
End:
		//End tag, we go here after a redirection occurs
		c++;
		a++;
		//We increment both counters

	}


}


void searchForPipe(char * arg){

	//When we find a pipeline we separate the char*
	char ** tok = malloc(sizeof(char) * 500);
	//We reserve 500 bytes to store the command
	char * argvv = arg;
	//We save the char* we get on a arg we start here
	int * n = malloc(MAX_N_PIPES * sizeof(int));
	//We can only have 3 pipelines
	int i=0;
	while((tok[i] = strtok_r(argvv, PIPE, &argvv))){

		//We tokenize all the elements we have after a pipeline
		n[i] = getNewC(tok[i]);
		//We update the position
		i++;

	}

	for(; argvc<i; argvc++){

		//argvc is the counter of pipelines
		argc = 0;
		//The counter of tokens after a blank space is set to 0
		if(argvc+1==i) pos=n[argvc]-1;
		//If we are on the last token it means we are in the end of the char*
		// so we reduce the pos counter as the last char is the new line character
		else pos=n[argvc];
		argv[argvc] = malloc(sizeof(char**));
		command(tok[argvc]);

	}

}

Command get_order(char * line, Command cmd){

	pos=strlen(line)-1;
	argv = malloc(1000);
	searchForPipe(line);
	cmd.argv = argv;
	cmd.pipes = argvc;
	for(int i=0; i<3; i++) cmd.filev[i] = filev[i];
	cmd.bg = bg;
	return cmd;

}
