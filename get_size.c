#include "main.h"

/**
 * get_size -this function calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int c_i = *i + 1;
	int size = 0;

	if (format[c_i] == 'l') /*checks if the character in the format string at position c_i is 'l'*/
		size = S_LONG;
	else if (format[c_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = c_i - 1; /*If size remains 0 after the checks, it sets the value pointed to by i to c_i - 1*/
	else
		*i = c_i; /*Otherwise, it sets i to c_i*/

	return (size); /*the function returns the value of size, which indicates the size specifier found*/
}
