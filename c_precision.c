#include "main.h"

/**
 * get_precision -this function calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++) /*initializes curr_i to a value and iterates through the format string until it encounters the null terminator '\0'*/
	{
		if (is_digit(format[curr_i]))  /*If the current character in the format string is a digit, it updates the precision value*/
		{
			precision *= 10;   /*multiplies the existing precision value by 10 to shift its digits to the left.*/
			precision += format[curr_i] - '0';   /* adds the numerical value of the character in the format string to the precision value. The subtraction of '0' from format[curr_i] converts the character to its numeric value*/
		}
		else if (format[curr_i] == '*')     /*If the character is an asterisk, it increments curr_i, expecting the next argument in the variable argument list.*/
		{
			curr_i++;
			precision = va_arg(list, int);    /*It retrieves an integer argument from the variable argument list using va_arg(list, int) and assigns it to the precision variable*/
			break;   /*After this operation, it breaks out of the loop.*/
		}
		else
			break;   /**/If neither a digit nor an asterisk is encountered, it breaks out of the loop.
	}

	*i = curr_i - 1;

	return (precision);
}
