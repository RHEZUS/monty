#include "header.h"

/**
 * main - entry point
 * @argc: the number of arguments
 * @argv: the files containing the command
 * Return: always 0 
 */
int main(int argc, char const *argv[])
{
    /*UNUSED(argv);*/
    int i = 0;
    char *commands[MAX_COMMAND];
    if (argc != 3)
    {
        fprintf(stderr,  "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    commands = read_file(argv[1]);

    for (i = 0; commands[i] != NULL; i++)
    {
        printf(commands[i]);
    }
    return 0;
}
