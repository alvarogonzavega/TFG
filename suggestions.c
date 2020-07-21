#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "suggestions.h"

int min3(int a, int b, int c){

  if(a<b && a<c) return a;
  if(b<c && b<a) return b;
  else return c;

}

int distance(char *s, int ls, char *t, int lt){

  int a, b, c;

        /* if either string is empty, difference is inserting all chars
         * from the other
         */
        if (!ls) return lt;
        if (!lt) return ls;

        /* if last letters are the same, the difference is whatever is
         * required to edit the rest of the strings
         */
        if (s[ls - 1] == t[lt - 1])
                return distance(s, ls - 1, t, lt - 1);

        /* else try:
         *      changing last letter of s to that of t; or
         *      remove last letter of s; or
         *      remove last letter of t,
         * any of which is 1 edit plus editing the rest of the strings
         */
        a = distance(s, ls - 1, t, lt - 1);
        b = distance(s, ls,     t, lt - 1);
        c = distance(s, ls - 1, t, lt    );
        a = min3(a,b,c);

        return a + 1;
  }

int *levenshtein(char **cf, char **list){

  int sl=strlen(cf[0]);
  int a=0;
  int min=10000;
  char *corrected="";
  for(int i=0; i<50; i++){

    int c = sl-strlen(list[i]);
    if(c<-1 || c>1) a=0;
    else{

      a=distance(cf[0], strlen(cf[0]), list[i], strlen(list[i]));
      if(a<=THRESHOLD && a<min){

        min=a;
        corrected=list[i];

      }

    }

  }

  int i=1;
  while(cf[i]!=NULL){ i++; }

  if(strlen(corrected)>0){

    printf("Maybe you wanted to type this: %s", corrected);
    for(int j=1; j<i; j++){

      printf(" %s", cf[j]);

    }

  }

  printf("\n");
  return 0;

}
