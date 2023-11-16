#include "main.h"

/**
 * get_flags - this function calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int a, curr_q;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_q = *i + 1; format[curr_q] != '\0'; curr_q++) /*OUTER LOOP: curr_q is initialized to the value pointed to by i plus 1. It seems to iterate through the format string until it encounters the null terminator '\0'*/
	{
		for (a = 0; FLAGS_CH[a] != '\0'; a++) /*INNER LOOP: It initializes a to 0 and continues looping until it encounters the null terminator '\0'. If a match is found, it sets certain bits in the flags variable using bitwise*/
			if (format[curr_q] == FLAGS_CH[a]) /*Checks if the inner loop completed without finding a matching flag character. If so, it breaks out of the outer loop*/
			{
				flags |= FLAGS_ARR[a];
				break;
			}

		if (FLAGS_CH[a] == 0)
			break;
	}

	*i = curr_q - 1;

	return (flags);
}
