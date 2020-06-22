#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "tutorial.h"

void tutorial(char *c, char **list){

  if(strcmp(c, list[0])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "pwd [-L | -P]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It prints the working directory you are currently in.\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, greater than 0 if not\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "pwd\n");

  }

  else if(strcmp(c, list[1])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "ls [OPTION][FILE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It prints the list of contents that you have in your current directory\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, greater than 0 if not\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "ls -ltrh\n");

  }

  else if(strcmp(c, list[2])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "cd [-L | -P][dir]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It changes the directory you are currently for the one you've asked.\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, distinct than 0 if not\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "cd ~/Documents\n");

  }

  else if(strcmp(c, list[3])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "mkdir [-pv][-m mode][dir]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It creates a new directory with the name you've specified\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, -1 if there is an error\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "mkdir -p '~dir1/test1'\n");

  }

  else if(strcmp(c, list[4])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "rmdir [-p][dir]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It removes the directory you've specified\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, -1 if there is an error\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Create a directory with the following command 'mkdir p', then to remove it:\n",
    ANSI_COLOR_RESET, "rmdir p\n");

  }

  else if(strcmp(c, list[5])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "lsblk [OPTIONS][DEVICE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It list all the information about the blocks of the system\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, distinct than 0 if there is an error\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "lsblk -f\n");

  }

  else if(strcmp(c, list[6])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "rmdir [-p][dir]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It removes the directory you've specified\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, -1 if there is an error\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Create a directory with the following command 'mkdir p', then to remove it:\n",
    ANSI_COLOR_RESET, "rmdir p\n");

  }

}
