/*
** PERSONAL PROJECT, 2019
** 2_pow_computer
** File description:
** 2 powers computer help free
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/2pow.h"
#include "../include/my.h"

void freer(set_t *settings)
{
    if (settings->start)
        free(settings->start);
    if (settings->end)
        free(settings->end);
    free(settings);
}

static void help2(void)
{
    printf(" the powers of 2 until the \033[4mNUM\033[0mth power.\n\n\t"
    "\033[1m-E\033[0m \033[4mNUM\033[0m, \033[1m--end\033[0m=\033[4mNUM\033[0m"
    "\n\t\tCompute the powers of 2 while the result is less than \033[4mNUM"
    "\033[0m.\n\n\t\033[1m-F\033[0m \033[4mNUM\033[0m, \033[1m--find\033[0m="
    "\033[4mNUM\033[0m\n\t\tFind and print the \033[4mNUM\033[0mth power of 2."
    "  Using this will deny\n\t\tall other parameter.\n\n\t\033[1m-S"
    "\033[0m \033[4mNUM\033[0m, \033[1m--start\033[0m=\033[4mNUM\033[0m\n\t\t"
    "Start computing the powers of 2 at \033[4mNUM\033[0m.\n\n\tAn invalid par"
    "ameter will automatically  set the associated option to\n\tdefault. You c"
    "an quit the program by hitting CTRL+C.\n\n   "
    "\033[1mExit status\033[0m:\033[0m\n\t0\tif everything went as exp"
    "ected,\n\t84\tif an invalid argument was passed to the program.\n\n "
    "\033[1mPRINTING FORMAT\033[0m\n\t$>  2^\033[4mn\033[0m:          \033[4m"
    "value\033[0m\n\n \033[1mAUTHOR\033[0m\n\tWritten by Quentin di Meo.\n\n "
    "\033[1mREPORTING BUGS\033[0m\n\tReport any bug or "
    "functioning error to <quentin.di-meo@epitech.eu>\n\n");
}

int help(void)
{
    printf("\n\tWelcome to 2_pow_computer.\n\n \033[1mUSAGE\033[0m\n\t"
    "./2_pow_computer [\033[4mOPTION\033[0m]\n\n \033[1mDESCRIPTION\033[0m\n\t"
    "This program's purpose is to infinitely calculate the powers of 2; no\n\t"
    "less, no more, what can I say in addition?\n\n\t\033[1m-d\033[0m \033[4m"
    "DIG\033[0m, \033[1m--digits\033[0m=\033[4mDIG\033[0m\n\t\tCompute the pow"
    "ers of 2 until the result is \033[4mDIG\033[0m-digits long.\n\n\t\033[1m"
    "-h\033[0m, \033[1m--help\033[0m\n\t\tDisplay this help.\n\n\t\033[1m--sil"
    "ent\033[0m\n\t\tMake it so that the program doesn't display what it finds"
    ".\n\n\t\033[1m--slow\033[0m=\033[4mMS\033[0m\n\t\tSlow down the program b"
    "y  waiting  \033[4mMS\033[0m  milliseconds  after\n\t\tevery iteration. "
    "I'm suggesting 250, the limit is 100,000.\n\n\t\033[1m--store\033[0m\n\t"
    "\tMake the program store the results it  finds  in  a  file,\n\t\t\033[3m"
    "calculations_2pow.txt\033[0m,allowing you to read all of the last\n\t\tre"
    "quested results. Be careful, it grows exponentially fast\n\t\tin size (15"
    "9KB for results from 0 to 1,000).\n\n\t\033[1m-u\033[0m \033[4mNUM\033[0m"
    ", \033[1m--until\033[0m=\033[4mNUM\033[0m\n\t\tCompute");
    help2();
    return (SUCCESS);
}
