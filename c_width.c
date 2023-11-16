#include "main.h"

/**
 * get_width -this function calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++) /*initializes curr_i to the value pointed to by i plus 1 and iterates through the format string until it reaches the null terminator '\0'*/
	{
		if (is_digit(format[curr_i])) /*If the character at the current position in the format string is a digit, it updates the width value*/
		{
			width *= 10; /* multiplies the existing width value by 10 to shift its digits to the left*/
			width += format[curr_i] - '0'; /*adds the numerical value of the character in the format string to the width. The subtraction of '0' from format[curr_i] converts the character to its numeric value*/
		}
		else if (format[curr_i] == '*') /*If the character is an asterisk (*), it increments curr_i, expecting the next argument in the variable argument list to be an integer that will define the width*/
		{
			curr_i++;
			width = va_arg(list, int); /*retrieves an integer argument from the variable argument list using va_arg(list, int) and assigns it to the width variable*/
			break; /*after the operation, it breaks out of the loop*/
		}
		else
			break; /*If neither a digit nor an asterisk is encountered, it breaks out of the loop*/
	}

	*i = curr_i - 1;

	return (width);
}
