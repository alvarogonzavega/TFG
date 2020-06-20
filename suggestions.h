#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define THRESHOLD 2
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int distance(char *s1, char *s2);
char *levenshtein(char *cf, char **list);
