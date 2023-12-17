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
/**
 * more_err - handles errors.
 * @code: The error codes are the following:
 */
void more_err(int code, ...)
{
	va_list arg;
	char *ptr;
	int line_number;

va_start(arg, code);

    if (code == 6)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(arg, int));
    }
    else if (code == 7)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(arg, int));
    }
    else if (code == 8)
    {
        line_number = va_arg(arg, unsigned int);
        ptr = va_arg(arg, char *);
        fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, ptr);
    }
    else if (code == 9)
    {
        fprintf(stderr, "L%d: division by zero\n", va_arg(arg, unsigned int));
    }
    va_end(arg);
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void string_err(int code, ...)
{
	va_list arg;
	int line_number;

va_start(arg, code);
    line_number = va_arg(arg, int);

    if (code == 10)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
    }
    else if (code == 11)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
    }
    va_end(arg);
	freeNodes();
	exit(EXIT_FAILURE);
}
