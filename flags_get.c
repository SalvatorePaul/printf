#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current index in the format string
 * Return: Flags calculated from the format string
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr__i - 1;

	return (flags);
}
 /** The format string is a character array that has the format specifier
 * characters along with optional flags. The supported flags are '-', '+', '0',
 * '#', and ' '.
 * It calculates the active flags based on the format string 
 * The function iterates through the format string from the
 * current index (i) and checks for the presence of any of these flags.
 * If a flag is found, the corresponding flag value is set in the flags variable
 * using bitwise
 */
