#include "header.h"
#include <stdlib.h>

char **read_file(const char *file_path)
{
    char *commands[MAX_COMMAND];
    FILE *command_file;
    char *line = NULL;
    size_t len = 0;
    int i = 0;
    __ssize_t read;

    command_file = fopen(file_path, "r");
    if (command_file == NULL)
    {
        fprintf(stderr,"Error: Can't open file <%s>", file_path);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, command_file)) != -1)
    {
        commands[i] = line;
        i++;
    }

    if (read == -1)
    {
        fprintf(stderr, "Error: Can't open file <%s>", file_path);
        exit(EXIT_FAILURE);
    }
    commands[i++] = NULL;
    fclose(command_file);
    if (line)
        free(line);
    return (commands);
}