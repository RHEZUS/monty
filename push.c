#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    int n, j = 0, flag = 0;

    if (bus.arg != NULL)
    {
        if (bus.arg[0] == '-')
            j++;
        for (; bus.arg[j] != '\0'; j++)
        {
            if (bus.arg[j] > 57 || bus.arg[j] < 48)
                flag = 1; }
        if (flag == 1)
        {   
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            fclose(bus.file);
            free(bus.line);
            /*free_stack(stack)*/
            exit(EXIT_FAILURE); 
        }
    }
    else
    { 
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(bus.file);
        free(bus.line);
        exit(EXIT_FAILURE); 
    }
    n = atoi(bus.arg);
    if (bus.is_stack == 0)
        add_node(stack, n);
    else
        printf("It is a que");
        /*add_queue(stack, n);*/

}