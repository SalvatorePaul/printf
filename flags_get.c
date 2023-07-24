#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current index in the format string
 * Return: Flags calculated from the format string
 */
/* - = 0 ' ' */
/* 1 2 4 8 16 */
int get_flags(const char *format, int *i)
{
	int flags = 0;
	int a, b_i;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (b_i = *i + 1; format[b_i] != '\0'; b_i++)
	{
		for (a = 0; FLAGS_CH[a] != '\0'; a++)
		{
			if (format[b_i] == FLAGS_CH[a])
			{
				flags |= FLAGS_ARR[a];
				break;
			}
		}
		if (FLAGS_CH[a] == 0)
			break;
	}
	*i = b_i - 1;
	return (flags);
}
