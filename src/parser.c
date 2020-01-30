#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

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
int **x;


char* getLine(void){

	char *arg = malloc(1000 * sizeof(char));
	pos = 0;
	int c;
	if(!arg){

		fprintf(stderr, "wsh: Error in the allocation!!");
		exit(-1);

	}

	while(1){

		c = getchar();
		if(c == EOF || c == '\n'){

			arg[pos] = '\n';
			return arg;

		}else{

			arg[pos] = c;

		}

		pos++;
		if(pos>1000){

			fprintf(stderr, "wsh: Command too long!!");
			exit(-1);

		}

	}

}


#define freeC(c) { if(c){ free(c); c=NULL; }}



void reinitialize(){

	freeC(argv);
	freeC(filev[0]);
	freeC(filev[1]);
	freeC(filev[2]);
	bg = 0;
	argvc=0;
	argc=0;

}



int getNewC(char *arg){

	int y =0;
	while(arg[y]){

		y++;

	}

	return y;

}



char *getRedir(char *arg, int y){

	char *redir = malloc(1000*sizeof(char));
	int x = 0;
	for(;y<pos; y++){

		if(arg[y]!=' ' && arg[y]!='\n' && arg[y]!=BG){

			redir[x]=arg[y];
			x++;

			}

	}

	return redir;

}


void command(char *arg){

	int c = 0; int a=0;
	char y;
	argv[argcc][argvc][argc] = malloc(sizeof(char)*1000);
	if(arg[0]==' ') c++;
	if(arg[pos]==' ') pos--;
	x[argcc][argvc]=1;
	while(c<pos){

		y = arg[c];
Start:
		if(y==BG && arg[c-1] != OUT){ bg=1; goto End; }
		if(y==IN){

			filev[0] = getRedir(arg, c+1);
			c+=strlen(filev[0]);
			goto End;

		}

		if(y==OUT && arg[c+1] != BG){

			filev[1] = getRedir(arg, c+1);
			c+=strlen(filev[1]);
			goto End;

			}

		if(y==BG && arg[c-1] == OUT){

			filev[2] = getRedir(arg, c+1);
			c+=strlen(filev[2]);
			goto End;

		}

		if(y==' '){

			if(c==pos) goto End;
			x[argcc][argvc]++;
			argc++;
			a=0;
			argv[argcc][argvc][argc] = malloc(sizeof(char)*1000);
			y=arg[c+1];
			c++;
			goto Start;

		}

		argv[argcc][argvc][argc][a] = y;
End:
		c++;
		a++;

	}


}


void pipe(char * arg){

	char ** tok = malloc(sizeof(char) * 1000);
	char * argvv = arg;
	int * n = malloc(10 * sizeof(int));
	int i=0;
	while((tok[i] = strtok_r(argvv, PIPE, &argvv))){

		n[i] = getNewC(tok[i]);
		i++;

	}

	for(; argvc<i; argvc++){

		argc = 0;
		if(argvc+1==i) pos=n[argvc]-1;
		else pos=n[argvc];
		x[argcc][argvc] = malloc(sizeof(int));
		argv[argcc][argvc] = malloc(sizeof(char**)*1000);
		command(tok[argvc]);

	}

}

void separate(char *arg){

	char ** tok = malloc(sizeof(char) * 1000);
	int * num = malloc(10 * sizeof(int));
	x = malloc(sizeof(int**)*1000);
	char * argvv=arg;
	int i=0;
	argv = malloc(sizeof(char***) * 1000);
	while((tok[i] = strtok_r(argvv, MULT, &argvv))){

		num[i] = getNewC(tok[i]);
		i++;

	}

	for(; argcc<i; argcc++){

		argc = 0;
		argvc = 0;
		if(argcc+1==i) pos=num[argcc]-1;
		else pos=num[argcc];
		x[argcc] = malloc(sizeof(int*)*3);
		argv[argcc] = malloc(sizeof(char**)*1000);
		pipe(tok[argcc]);

	}

}



int* get_order(char ****argvv, char *filep[3], int *bgp){

	reinitialize();
	char * line= getLine();
	separate(line);
	filep[0] = filev[0];
	filep[1] = filev[1];
	filep[2] = filev[2];
	*bgp = bg;
	for(int i=0; i<argcc; i++){

		*argvv = argv[i];
		return x[i];

	}

}

