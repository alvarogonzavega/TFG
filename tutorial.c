#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "tutorial.h"

void tutorial(char *c, char **list){

  if(strcmp(c, list[0])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "pwd [-L | -P]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It prints the working directory you are currently in.\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, greater than 0 if not\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "pwd\n");

  }

  else if(strcmp(c, list[1])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "ls [OPTION][FILE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It prints the list of contents that you have in your current directory\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, greater than 0 if not\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "ls -ltrh\n");

  }

  else if(strcmp(c, list[2])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "cd [-L | -P][dir]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It changes the directory you are currently for the one you've asked.\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, distinct than 0 if not\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "cd ~/Documents\n");

  }

  else if(strcmp(c, list[3])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "mkdir [-pv][-m mode][dir]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It creates a new directory with the name you've specified\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, -1 if there is an error\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "mkdir -p '~dir1/test1'\n");

  }

  else if(strcmp(c, list[4])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "rmdir [-p][dir]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It removes the directory you've specified\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, -1 if there is an error\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Create a directory with the following command 'mkdir p', then to remove it:\n",
    ANSI_COLOR_RESET, "rmdir p\n");

  }

  else if(strcmp(c, list[5])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "lsblk [OPTIONS][DEVICE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It list all the information about the blocks of the system\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, distinct than 0 if there is an error\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "lsblk -f\n");

  }

  else if(strcmp(c, list[6])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "mount [-adfruvw][-o][-t lfs][special | mount_type]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It's used to mount the filesystem on a tree structre, rooted at '/'\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Mount a dev partition on the Documents directory\n",
    ANSI_COLOR_RESET, "sudo mount /dev/sda1 ~/Documents\n");

  }

  else if(strcmp(c, list[7])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "df [OPTIONS][FILE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It shows the amount of disk space used\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "df -alh\n");

  }

  else if(strcmp(c, list[8])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "uname [OPTIONS]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It prints the system information. Machine arquitecture and kernel version\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "uname -a\n");

  }

  else if(strcmp(c, list[9])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "ps [OPTIONS]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It displays information of the current processes running\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Prints information of all the processes that a user is executing\n",
    ANSI_COLOR_RESET, "ps -u $USER\n");

  }

  else if(strcmp(c, list[10])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "kill [SIGNALS][PID]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It sends a signal to a process\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Sends a signal to finish all the possible processes\n",
    ANSI_COLOR_RESET, "kill -9 -l\n");

  }

  else if(strcmp(c, list[11])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "service [SCRIPT-NAME][COMMAND]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It lets you run a System V init script.\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Shows the status of all the services\n",
    ANSI_COLOR_RESET, "service --status-all\n");

  }

  else if(strcmp(c, list[12])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "batch [OPTIONS]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It reads commands from the standard input or an specified file\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Print hello world on a batch\n",
    ANSI_COLOR_RESET, "batch | echo hello world\n");

  }

  else if(strcmp(c, list[13])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "shutdown [OPTIONS][-t TIME]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It makes the system shutdown on a safe way\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Shutdown the system in 10 seconds (If you wanna cancel that, you should type afterwards the following: 'shutdown -a')\n",
    ANSI_COLOR_RESET, "shutdown -s -t 10\n");

  }

  else if(strcmp(c, list[14])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "touch [OPTIONS][FILE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It allows you change the timestamp on a file.\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Change the acces and modification time for the file test.txt to the following date (Year 2999, month 12, day 31, hour 23, minutes 59, seconds 59)\n",
    ANSI_COLOR_RESET, "touch -c -t 299912312359.59 test.txt\n");

  }

  else if(strcmp(c, list[15])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "cat [-benstuv][file]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It allows you to concatenate strings and read from a file.\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "cat test.txt\n");

  }

  else if(strcmp(c, list[16])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "head [-n count | -c bytes][file]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It displays the first n count lines or the first c bytes of a file.\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, distinct than 0 if there is an error\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Prints the first 6 lines of the file test.txt\n",
    ANSI_COLOR_RESET, "head -c 6 test.txt\n");

  }

  else if(strcmp(c, list[17])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "tail [-F | -f | -r] [-q] [-b number | -c number | -n number][file]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It displays the end of a file.\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, distinct than 0 if there is an error\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Prints the last 20 lines of the file log.txt and follows it (keeps checking for updates)\n",
    ANSI_COLOR_RESET, "tail -F -n 20 log.txt\n");

  }

  else if(strcmp(c, list[18])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "cp [-R [-H | -L | -P]] [-fi | -n] [-apvX] [SOURCE] [TARGET]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It copies the content of a file (source) in other directory (target).\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, greater than 0 if there is an error\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Copies the file test.txt in the Desktop\n",
    ANSI_COLOR_RESET, "cp ~/Documents/test.txt ~/Desktop\n");

  }

  else if(strcmp(c, list[19])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "mv [-f | -i | -n] [-v] [SOURCE] [TARGET]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It moves the content of a file (source) into other directory (target).\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, greater than 0 if there is an error\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Moves the file test.txt in the Desktop\n",
    ANSI_COLOR_RESET, "mv ~/Documents/test.txt ~/Desktop/test.txt\n");

  }

  else if(strcmp(c, list[20])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "comm [-123i] [FILE1] [FILE2]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It identifies the common lines between two files\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's correct, greater than 0 if there is an error\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#It outputs the common lines of two files\n",
    ANSI_COLOR_RESET, "comm -3 file1.txt file2.txt\n");

  }

  else if(strcmp(c, list[21])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "less [OPTIONS][FILE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It allows you to move in a file, forward and backward to read it\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "less test.txt\n");

  }

  else if(strcmp(c, list[22])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "ln [-Ffhinsv][SOURCE][TARGET]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It creates a link between two files. It can be hard (physical: Sharing the same inode) or soft (logical: not in the same inode)\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Create a soft link (logical: a -> b) between two files\n",
    ANSI_COLOR_RESET, "ln -s a.txt b.txt\n");

  }

  else if(strcmp(c, list[23])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "cmp [OPTIONS] [FILE1] [FILE2 [SKIP1 [SKIP2]]]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It compares byte per byte two files\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "cmp file1.txt file2.txt\n");

  }

  else if(strcmp(c, list[24])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "dd [if=SOURCE][of=TARGET][OPERANDS]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It copies and converts data from a file\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Copy the content of the RAM memory into a file\n",
    ANSI_COLOR_RESET, "dd if=/dev/mem of=myRAM bs=1024\n");

  }

  else if(strcmp(c, list[25])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "alias [-p] [NAME[=value] ... ]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It defines aliases where you can save variables\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Everytime you use rm, it will include the flag i\n",
    ANSI_COLOR_RESET, "alias rm='rm -i'\n");

  }

  else if(strcmp(c, list[26])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "cal [OPTIONS]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It displays the calendar of the current month\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Displays your current month and the next 2\n",
    ANSI_COLOR_RESET, "cal -A 2\n");

  }

  else if(strcmp(c, list[27])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "fortune [-acefilsw] [-n length] [ -m pattern]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It outputs a random epigram\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "fortune\n");

  }

  else if(strcmp(c, list[28])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "history [OPTIONS]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It displays the history of commands you've typed\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#It shows the most used commands\n",
    ANSI_COLOR_RESET, "history | awk '{a[$2]++}END{for(i in a){print a[i] " " i}}' | sort -rn | head\n");

  }

  else if(strcmp(c, list[29])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "yes [WORD]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It outputs the word you want indefinitely\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "yes yes\n");

  }

  else if(strcmp(c, list[30])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "banner [-d] [-t] [-w width][MESSAGE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It outputs a large banner with the message you want\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "banner -w 72 I'm the best\n");

  }

  else if(strcmp(c, list[31])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "rev [FILE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It reverses the text of a file\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Reverse the content from test.txt\n",
    ANSI_COLOR_RESET, "rev test.txt\n");

  }

  else if(strcmp(c, list[32])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "wget [OPTIONS][TARGET][URL]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It downloads the contents of files on the web. It supports HTTP, HTML and FTP\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Download the content from Google main page into a file\n",
    ANSI_COLOR_RESET, "wget -O a.txt www.google.es\n");

  }

  else if(strcmp(c, list[33])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "iptables [-t table][OPTIONS]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It's used to display, add and maintain the tables of IP packages.\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Print all the IP Tables\n",
    ANSI_COLOR_RESET, "iptables -L -n -v\n");

  }

  else if(strcmp(c, list[34])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "traceroute [-adeFISdNnrvx][-A|-g|-f|-i|-M|-m|-P|-p|-q|-s|-t|-w|-z][HOST]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It's used to show the routes (IPs) a package needs to follow to arrive at the desired IP\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Look the route from your computer to Google\n",
    ANSI_COLOR_RESET, "traceroute google.es\n");

  }

  else if(strcmp(c, list[35])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "curl [OPTIONS][URL]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It's used to transfer data from or to a server.\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Tweet from the shell\n",
    ANSI_COLOR_RESET, "curl -u USER:PASSWORD -d status:'Hi there!!' https://twitter.com/compose/tweet\n");

  }

  else if(strcmp(c, list[36])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "find [-H | -L | -P] [-EXdsx] [-f path][EXPRESSION]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It's used to search and locate the list of files and directories based on conditions you specify for files that match the arguments.\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Find all the zip files\n",
    ANSI_COLOR_RESET, "find . -name '*.zip'\n");

  }

  else if(strcmp(c, list[37])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "which [-as][PROGRAM]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It's used to find the path of the executable you've asked.\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXIT OF THE FUNCTION:\n",
    ANSI_COLOR_RESET, "0 if it's found, greater than 0 if we have errors\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Find the path to eShell\n",
    ANSI_COLOR_RESET, "which esh\n");

  }

  else if(strcmp(c, list[38])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "locate [-0Scims][-l|-d][PATTERN]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It's used to find the path of files that contain the pattern you've requested.\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Find the path to files that contain '2020' in their name\n",
    ANSI_COLOR_RESET, "locate 2020\n");

  }

  else if(strcmp(c, list[39])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "grep [-abcdDEFGHhIiJLlmnOopqRSsUVvwxZ][PATTERN][FILE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It's used to find lines on files you've asked, that match the pattern given.\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Find the lines that contains 'ANSI' in tutorial.c\n",
    ANSI_COLOR_RESET, "grep ANSI tutorial.c\n");

  }

  else if(strcmp(c, list[40])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "sed [-Ealn][COMMAND][FILE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It's used to edit files with the commands you use.\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Replace all 'dog' with 'cat' in file.txt, and keep the original in file.txt.orig\n",
    ANSI_COLOR_RESET, "sed -i.orig s/dog/cat/g file.txt\n");

  }

  else if(strcmp(c, list[41])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "clear\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It's used to clear away the screen.\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RESET, "clear\n");

  }

  else if(strcmp(c, list[42])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "echo [-n][STRING]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It's used to output the string you passed\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Output the variable username\n",
    ANSI_COLOR_RESET, "echo $USER\n");

  }

  else if(strcmp(c, list[43])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "sort [-bcCdfghiRMmnrsuVz][-k|-S|-t|-T][FILE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It's used to sort text in a file.\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Sort your history alphabetically (skipping the numbers)\n",
    ANSI_COLOR_RESET, "history | sort -k 2\n");

  }

  else if(strcmp(c, list[44])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "sudo [OPTIONS]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "Allows the user to execute commands as a superuser or administrator\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Switch to root user (CAREFUL)\n",
    ANSI_COLOR_RESET, "sudo su\n");

  }

  else if(strcmp(c, list[45])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "chmod [-fv] [-R [-H | -L | -P]]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "Modifies the file mode and the Acces Control List\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Allow the user (u) to execute (x) the esh\n",
    ANSI_COLOR_RESET, "chmod u+x esh\n");

  }

  else if(strcmp(c, list[46])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "chwon [-cfhvR][USER][FILE]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "Changes the owner of a file\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#New owner of the esh is root\n",
    ANSI_COLOR_RESET, "chown root esh\n");

  }

  else if(strcmp(c, list[47])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "man [OPTIONS]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "Manual pages of UNIX. Gives you the section you requested\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Manual for the command rm\n",
    ANSI_COLOR_RESET, "man rm\n");

  }

  else if(strcmp(c, list[48])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "tar [OPTIONS]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "It's used to compress files in a tar extension.\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Compress various files in one tar file\n",
    ANSI_COLOR_RESET, "tar -cf prueba.tar file1.txt file2.txt file3.txt\n");

  }

  else if(strcmp(c, list[49])==0){

    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNTAXIS:\n",
    ANSI_COLOR_RESET, "whatis [OPTIONS]\n");
    fprintf(stdout, "%s%s%s%s", ANSI_COLOR_GREEN, "SYNOPSIS:\n",
    ANSI_COLOR_RESET, "Searches for the manual pages names and shows the manual pages descriptions\n");
    fprintf(stdout, "%s%s%s%s%s%s", ANSI_COLOR_GREEN, "EXAMPLE FOR YOU TO TRY:\n",
    ANSI_COLOR_RED, "#Description of the command rm\n",
    ANSI_COLOR_RESET, "whatis -l rm\n");

  }

  else printf("Sorry!! That command is not listed in our guide. Follow for more updates :)");

}
