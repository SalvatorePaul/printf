#include "main.h"

/**
 * Authors: Paul and Rhoderick
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: inventory of arguments to be printed.
 * @list: inventory of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
/**
 * The width is specified by a number(e.g. %4d)
 * and it can also be an asterisk (*) indicating that the width is passed
 * as an argument to the function.
 * The function iterates through the format string starting from the current
 * index (i) and checks each character to determine the width.
 * If the character is a digit (0-9),
 * the width is multiplied by 10 and added to the digit value.
 * If the character is an asterisk,
 * the width is extracted from the argument list.
 * If the character is not a digit or an asterisk,
 * the loop breaks, and the final width value is returned.
 */
