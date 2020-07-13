#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define THRESHOLD 2

int min3(int a, int b, int c);
int distance(char *s, int ls, char *t, int lt);
void *levenshtein(char **cf, char **list);
