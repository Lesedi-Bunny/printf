#include "main.h"

/**
 * is_printable -this function evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)    /* checks if the ASCII value of the character c is greater than or equal to 32 and less than 127*/
		return (1);   /*If the character c falls within the ASCII range of printable characters (32 to 126 inclusive), the function returns 1, indicating that the character is a printable character*/

	return (0);   /*If the character c does not fall within this range, the function returns 0, indicating that it is not a printable character.*/
}

/**
 * append_hexa_code -this function appends ascii in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";   /*stores the hexadecimal digits' characters from 0 to F, which will be used for converting the ASCII code to its hexadecimal representation*/

	if (ascii_code < 0)
		ascii_code *= -1;    /*ensures that the code works with positive values by converting negative ASCII codes to their positive equivalents*/

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];    /*assign the hexadecimal representation of the ASCII code to the buffer*/

	return (3);   /* indicates that it has converted the ASCII code to its hexadecimal representation and stored it in the buffer, consisting of three characters*/
}

/**
 * is_digit -this function verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')   /* checks if the character c falls within the ASCII range of numeric characters */
		return (1);   /*If c is between '0' and '9' (inclusive), the function returns 1, indicating that the character is a numeric digit*/

	return (0);  /*If c is not in this range, the function returns 0*/
}

/**
 * convert_size_number -this function casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);   /*If size equals S_LONG, it returns num as is without any type conversion, assuming it's already of the desired type*/
	else if (size == S_SHORT)
		return ((short)num);   /*If size equals S_SHORT, it performs a type cast on num to a short data type and returns the result*/

	return ((int)num);  /*If neither S_LONG nor S_SHORT is the value of size, it defaults to returning num typecasted as an int*/
}

/**
 * convert_size_unsgnd -this function casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
