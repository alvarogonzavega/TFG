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
    ANSI_COLOR_RESET, "mount [-adfruvw][-o][-t lfs][special | mount_type]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It's used to mount the filesystem on a tree structre, rooted at '/'\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Mount a dev partition on the Documents directory\n",
    ANSI_COLOR_RESET, "sudo mount /dev/sda1 ~/Documents\n");

  }

  else if(strcmp(c, list[7])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "df [OPTIONS][FILE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It shows the amount of disk space used\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "df -alh\n");

  }

  else if(strcmp(c, list[8])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "uname [OPTIONS]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It prints the system information. Machine arquitecture and kernel version\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "uname -a\n");

  }

  else if(strcmp(c, list[9])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "ps [OPTIONS]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It displays information of the current processes running\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Prints information of all the processes that a user is executing\n",
    ANSI_COLOR_RESET, "ps -u $USER\n");

  }

  else if(strcmp(c, list[10])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "kill [SIGNALS][PID]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It sends a signal to a process\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Sends a signal to finish all the possible processes\n",
    ANSI_COLOR_RESET, "kill -9 -l\n");

  }

  else if(strcmp(c, list[11])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "service [SCRIPT-NAME][COMMAND]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It lets you run a System V init script.\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Shows the status of all the services\n",
    ANSI_COLOR_RESET, "service --status-all\n");

  }

  else if(strcmp(c, list[12])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "batch [OPTIONS]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It reads commands from the standard input or an specified file\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Print hello world on a batch\n",
    ANSI_COLOR_RESET, "batch | echo hello world\n");

  }

  else if(strcmp(c, list[13])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "shutdown [OPTIONS][-t TIME]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It makes the system shutdown on a safe way\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Shutdown the system in 10 seconds (If you wanna cancel that, you should type afterwards the following: 'shutdown -a')\n",
    ANSI_COLOR_RESET, "shutdown -s -t 10\n");

  }

  else if(strcmp(c, list[14])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "touch [OPTIONS][FILE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It allows you change the timestamp on a file.\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Change the acces and modification time for the file test.txt to the following date (Year 2999, month 12, day 31, hour 23, minutes 59, seconds 59)\n",
    ANSI_COLOR_RESET, "touch -c -t 299912312359.59 test.txt\n");

  }

  else if(strcmp(c, list[15])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "cat [-benstuv][file]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It allows you to concatenate strings and read from a file.\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "cat test.txt\n");

  }

  else if(strcmp(c, list[16])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "head [-n count | -c bytes][file]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It displays the first n count lines or the first c bytes of a file.\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, distinct than 0 if there is an error\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Prints the first 6 lines of the file test.txt\n",
    ANSI_COLOR_RESET, "head -c 6 test.txt\n");

  }

  else if(strcmp(c, list[17])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "tail [-F | -f | -r] [-q] [-b number | -c number | -n number][file]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It displays the end of a file.\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, distinct than 0 if there is an error\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Prints the last 20 lines of the file log.txt and follows it (keeps checking for updates)\n",
    ANSI_COLOR_RESET, "tail -F -n 20 log.txt\n");

  }

  else if(strcmp(c, list[18])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "cp [-R [-H | -L | -P]] [-fi | -n] [-apvX] [SOURCE] [TARGET]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It copies the content of a file (source) in other directory (target).\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, greater than 0 if there is an error\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Copies the file test.txt in the Desktop\n",
    ANSI_COLOR_RESET, "cp ~/Documents/test.txt ~/Desktop\n");

  }

  else if(strcmp(c, list[19])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "mv [-f | -i | -n] [-v] [SOURCE] [TARGET]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It moves the content of a file (source) into other directory (target).\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, greater than 0 if there is an error\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Moves the file test.txt in the Desktop\n",
    ANSI_COLOR_RESET, "mv ~/Documents/test.txt ~/Desktop/test.txt\n");

  }

  else if(strcmp(c, list[20])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "comm [-123i] [FILE1] [FILE2]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It identifies the common lines between two files\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, greater than 0 if there is an error\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#It outputs the common lines of two files\n",
    ANSI_COLOR_RESET, "comm -3 file1.txt file2.txt\n");

  }

  else if(strcmp(c, list[21])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "less [OPTIONS][FILE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It allows you to move in a file, forward and backward to read it\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "less test.txt\n");

  }

  else if(strcmp(c, list[22])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "ln [-Ffhinsv][SOURCE][TARGET]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It creates a link between two files. It can be hard (physical: Sharing the same inode) or soft (logical: not in the same inode)\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Create a soft link (logical: a -> b) between two files\n",
    ANSI_COLOR_RESET, "ln -s a.txt b.txt\n");

  }

  else if(strcmp(c, list[23])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "cmp [OPTIONS] [FILE1] [FILE2 [SKIP1 [SKIP2]]]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It compares byte per byte two files\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "cmp file1.txt file2.txt\n");

  }

  else if(strcmp(c, list[24])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "dd [if=SOURCE][of=TARGET][OPERANDS]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_BLUE, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It copies and converts data from a file\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_BLUE, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Copy the content of the RAM memory into a file\n",
    ANSI_COLOR_RESET, "dd if=/dev/mem of=myRAM bs=1024\n");

  }

}
