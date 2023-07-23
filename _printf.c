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
int _printf(cont char *format, ...)
{
	va_list parameters;
    int characters_printed = 0;
    char c;
    char ch;
    const char *str;

    va_start(parameters, format);

    while ((c = *format)) {
        if (c == '%') {
            // Handle conversion specifiers
           format++;
            switch (c) {
                case 'c':
                    ch = va_arg(parameters, int);
                    putchar(ch);
                    break;
                case 's':
                    str = va_arg(parameters, const char);
                    if (str == NULL)
                        str = "(null)";
                    while (*str)
                        {
                        putchar(*str);
                        str++;
                        }
                    break;
                case '%':
                    putchar('%');
                    break;
                default:
                    putchar('%'); // Treat unknown conversion specifiers as literals
                    putchar(c);
                    break;
            }
            characters_printed++;
        } else {
            putchar(c); // Output non-'%' characters as-is
            characters_printed++;
        }
        format++;
    }

    va_end(parameters);
    return characters_printed;
}
