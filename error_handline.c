#include "monty.h"
/**
 * Error_Handle- Handle errors.
 * @code: error codes:
 */
void Error_Handle(int code, ...)
{
	va_list arg;
	char *ptr;
	int line_number;

va_start(arg, code);

    if (code == 1)
    {
        fprintf(stderr, "USAGE: monty file\n");
    }
    else if (code == 2)
    {
        fprintf(stderr, "Error: Can't open file %s\n", va_arg(arg, char *));
    }
    else if (code == 3)
    {
        line_number = va_arg(arg, int);
        ptr = va_arg(arg, char *);
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, ptr);
    }
    else if (code == 4)
    {
        fprintf(stderr, "Error: malloc failed\n");
    }
    else if (code == 5)
    {
        fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
    }
    va_end(arg);
	freeNodes();
	exit(EXIT_FAILURE);
}
