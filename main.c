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
#define PIPE "|"
#define BG '&'
#define IN '<'
#define OUT '>'
#define MULT ";"

char ****argv;
int argcc;
int argvc;
int argc;
char *filev[3];
int bg;
int pos;
int **args;
int *x;


char* getLine(void){

	//We reserve 500 bytes of chars in the memory
	char *arg = malloc(500 * sizeof(char));
	pos = 0; //Counter of bytes
	int c;
	if(!arg){

		//If we don´t have enough space on the memory
		fprintf(stderr, "wsh: Error in the allocation!!");
		exit(-1);

	}

	while(1){

		//Infinite loop
		c = getchar(); //We get the character
		if(c == EOF || c == '\n'){

			//If we reach the end of the command
			arg[pos] = '\n';
			//We add the new line character at the end of the char and we return it
			return arg;

		}else{

			//We add the character in the position
			arg[pos] = c;

		}

		pos++; //We increment the counter
		if(pos>500){

			//If the command is longer than 500 bytes
			fprintf(stderr, "wsh: Command too long!!");
			exit(-1);

		}

	}

}


#define freeC(c) { if(c){ free(c); c=NULL; }}
//To free the space allocated in the memory



void reinitialize(){

	//Whenever we pass a new command we need to free all the space allocated
	// and put all the variables to 0
  freeC(argv);
	freeC(filev[0]);
	freeC(filev[1]);
	freeC(filev[2]);
  freeC(args);
  freeC(x);
	bg = 0;
	argvc=0;
	argc=0;
	pos=0;

}



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
	argv[argcc][argvc][argc] = malloc(sizeof(char)*500);
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
			argv[argcc][argvc][argc] = malloc(sizeof(char)*250);
			//We reserve 250 bytes of memory to allocate the command
			y=arg[c+1];
			//We are going to read the next character
			c++;
			//We increment the counter
			goto Start;
			//We go to the start tag to start reading the next character

		}

		argv[argcc][argvc][argc][a] = y;
		//We store the character on the argv
End:
		//End tag, we go here after a redirection occurs
		c++;
		a++;
		//We increment both counters

	}

  int t=0;
  for(int h=0; h<argc; h++){

    while((argv[argcc][argvc][h]) && strcmp(argv[argcc][argvc][h],"")>0){

      t++;
      h++;

    }if(argv[argcc][argvc][h]=="") freeC(argv[argcc][argvc][h]);

  }

  args[argcc][argvc] = t;


}


void searchForPipe(char * arg){

	//When we find a pipeline we separate the char*
	char ** tok = malloc(sizeof(char) * 500);
	//We reserve 500 bytes to store the command
	char * argvv = arg;
	//We save the char* we get on a arg we start here
	int * n = malloc(3 * sizeof(int));
	//We can only have 3 pipelines
	int i=0;
	while((tok[i] = strtok_r(argvv, PIPE, &argvv))){

		//We tokenize all the elements we have after a pipeline
		n[i] = getNewC(tok[i]);
		//We update the position
		i++;

	}

	args[argcc] = malloc(sizeof(int)*i);
  x[argcc] = i;
	//We save the number of pipelines we have

	for(; argvc<i; argvc++){

		//argvc is the counter of pipelines
		argc = 0;
		//The counter of tokens after a blank space is set to 0
		if(argvc+1==i) pos=n[argvc]-1;
		//If we are on the last token it means we are in the end of the char*
		// so we reduce the pos counter as the last char is the new line character
		else pos=n[argvc];
		argv[argcc][argvc] = malloc(sizeof(char**));
		command(tok[argvc]);

	}

}

void separate(char *arg){


	char ** tok = malloc(sizeof(char) * 500);
	int * num = malloc(10 * sizeof(int));
	x = malloc(sizeof(int*)*10);
	//We can only have 10 multiple commands
	char * argvv=arg;
	int i=0;
	argv = malloc(sizeof(char***));
	while((tok[i] = strtok_r(argvv, MULT, &argvv))){

		num[i] = getNewC(tok[i]);
		i++;

	}

  args = malloc(sizeof(int*)*i);
  x = malloc(sizeof(int)*i);

	for(; argcc<i; argcc++){

		//argcc is the counter of multiple commands (;)
		argc = 0;
		argvc = 0;
		//The counters for blanks and pipelines are set to 0
		pos=num[argcc];
		argv[argcc] = malloc(sizeof(char**)*500);
		searchForPipe(tok[argcc]);
		//We look for pipelines in each token

	}

}


void get_order(){

 //This is the function where we read & parse
	reinitialize();
	//First we free all the space
	char * line= getLine();
	//Then we read the full command
	separate(line);
	//We look for multiple commands, pipelines and parse the command

}

void exitFunc(){
 /*   free_command(&cmd); */
    printf("\nGoodbye!\n");
    exit(0);
}


int main(void) {

    setbuf(stdout, NULL);            /* Unbuffered */
    setbuf(stdin, NULL);

    while (1) {
        fprintf(stderr, "%s", "wsh> ");    /* Prompt */
        get_order();
        int c=0;
        while(c<argcc){

          int pfds[2];
          int pfds2[2];
          int stdin_copy = dup(0);
          int stdout_copy = dup(1);


          if (pipe(pfds) == -1) {
              perror("Error during pipe() function.");
              exit(-1);
            }

            if (strcmp(argv[c][0][0],"exit")==0) exitFunc();



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
                   if (x[c] == 3) {
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

                                     execvp(argv[c][0][0], argv[c][0]);
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
                                    execvp(argv[c][1][0], argv[c][1]);
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
                            execvp(argv[c][2][0], argv[c][2]);
                          }
                        }
                if (x[c] == 2) {
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
                            execvp(argv[c][0][0], argv[c][0]);
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
                            execvp(argv[c][1][0], argv[c][1]);
                    }
                }
                if (x[c] == 1) {
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
                    execvp(argv[c][0][0], argv[c][0]);
                    exit(0);
                }
            default:
                /*Parent process*/
                if (!bg) {
                    if (x[c] == 2) {
                        close(pfds[0]);
                        close(pfds[1]);
                    }
                    if (x[c] == 3) {
                        close(pfds[0]);
                        close(pfds[1]);
                    }
                    childPid = waitpid(childPid, NULL,0);
                    printf("Wait child %d\n", childPid);
                } else {
                    if (x[c] == 2) {
                        close(pfds[0]);
                        close(pfds[1]);
                    }
                    if (x[c] == 3) {
                        close(pfds[0]);
                        close(pfds[1]);
                        close(pfds2[0]);
                        close(pfds2[1]);
                    }
                    printf("[%d]\n", childPid);
                }


        }
	
	c++;
		
    } /*fin while*/

  } /*end main*/

  return 0;

}
