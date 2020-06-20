#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <suggestions.h>

int distance(char *s1, char *s2){

  int sl1, sl2;
  sl1 = strlen(s1);
  sl2 = strlen(s2);
  int d[sl1+1][sl2+1];
  d[0][0] = 0;
  for(int i=1; i<sl1, i++){ d[i][0] = d[i-1][0]+1; }
  for(int i=1; i<sl2; i++){ d[0][i] = d[0][i-1]+1; }
  for(int i=1; i<sl1; i++){

    for(int j=1; j<sl2; j++){

      d[i][j] = MIN3(d[i-1][j]+1, d[i][j-1] + 1, d[i-1][j-1] + (s1[i-1] == s2[j-1] ? 0 : 1));

    }

  }

  return d[sl1][sl2];

}

char levenshtein(char *cf, char **list){

  sl=strlen(cf);
  int a=0;
  int min=10000;
  char *corrected="";
  for(int i=0; i<50; i++){

    int c = sl-strlen(list[i]);
    if(c<-1 || c>1) a=0;
    else{

      a=distance(cf, list[i]);
      if(a<=THRESHOLD && a<min){

        min=a;
        corrected=list[i];

      }

    }

  }

  return corrected;

}
