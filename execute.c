#include "monty.h"

int execute(char *line, stack_t **stack, unsigned int count)
{

    /*char *command, *arg;*/
    instruction_t func[] =
    {
        {"push", push}, {"pall", pall},
        {"pin", pin}, {"pop", pop},
        {"swap", swap}, {NULL, NULL}
    };
    char *command = strtok(line, " \n\t");
    char *arg;
    int i = 0;

    if (!command)
        return (0);
    arg = strtok(NULL, " \n\t");
    UNUSED (arg);
    while (func[i].opcode)
    {
        if (strcmp(func[i].opcode, command) == 0)
        {
            func[i].f(stack, count);
            return (0);
        }
        i++;
    }

    if (func[i].opcode == NULL)
    {
        fprintf(stderr, "Line %d: Unknown function %s", count, command);
        free(bus.file);
        free(line);
        exit(EXIT_FAILURE);
    }
    
    return (0);
}