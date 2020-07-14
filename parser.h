#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define PIPE "|"
#define BG '&'
#define IN '<'
#define OUT '>'
#define MAX_N_PIPES 3

typedef struct{

	char ***argv;
	int pipes;
	char *filev[3];
	int bg;

}Command;

int getNewC(char *arg);
char *getRedir(char *arg, int y);
void command(char *arg);
void searchForPipe(char *arg);
void clean();
Command get_order(char * line, Command cmd);
