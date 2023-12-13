#include "monty.h"

int execute(char *line, stack_t **stack, unsigned int count)
{

    /*char *command, *arg;*/
    instruction_t func[] =
    {
        {"push", push}, {"pall", pall},
        {"pint", pint}, {"pop", pop},
        {"swap", swap}, {"add", add},
        {"sub", sub}, {"f_div", f_div},
        {"mul", mul}, {"mod", mod},
        {"#", nop}, {"nop", nop},
        {NULL, NULL}
    };
    char *command = strtok(line, " \n\t");
    char *arg;
    int i = 0;
    if (command == NULL)
        return (0);
    arg = strtok(NULL, " \n\t");
    bus.arg = arg;
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
        fprintf(stderr, "L%d: unknown instruction %s", count, command);
        free_stack(*stack);
        cleanup_and_exit();
    }
    return (0);
}