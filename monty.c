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
    char *commands[MAX_COMMAND];
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    int i = 0;
    ssize_t read;

    if (argc != 2)
    {
        fprintf(stderr,  "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr,"Error: Can't open file <%s>", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        commands[i] = line;
        i++;
    }

    commands[i] = NULL;
    fclose(file);

    for (i = 0; commands[i] != NULL; i++)
    {
        printf("%s", commands[i]);
    }

    if (line)
        free(line);
    return 0;
}
