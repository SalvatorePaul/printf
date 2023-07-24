#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * printf - a function that produces output according to a format
 * @format: The format string containing the text and format specifiers
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 *
 * You don’t have to reproduce the buffer handling of the C library printf function
 * You don’t have to handle the flag characters
 * You don’t have to handle field width
 * You don’t have to handle precision
 * You don’t have to handle the length modifiers
 * Authors: Paul and Rhoderick
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list lists;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lists, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, lists);
			precision = get_precision(format, &i, lists);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, lists, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(lists);

	return (printed_chars);
}

/**
 * print_buffer - prints out the content of the buffer if it exists
 * @buffer: Array of char in the buffer
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
