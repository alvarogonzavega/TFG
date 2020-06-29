#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define PIPE "|"
#define BG '&'
#define IN '<'
#define OUT '>'

char *getLine(void);
int getNewC(char *arg);
char *getRedir(char *arg, int y);
void command(char *arg);
void searchForPipe(char *arg);
void get_order(char ***argvv, int pipe, char *filep[3], int b);
