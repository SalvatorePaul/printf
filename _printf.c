#include "main.h"

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
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	va_list list;

	if (format == NULL)
	return (-1);

	va_start(list, format);

	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
	{
		printed = handle_print(format, &i)
		if (printed == -1)
				return (-1);
			printed_chars += printed;
	}
	}
	va_end(list);

	return (printed_chars);
}
