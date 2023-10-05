#include "main.h"
/**
 * stringlen - Sizes the length of a string
 * @string: String to be sized
 * Return: The length of the string
 */
size_t stringlen(const char *string)
{
	const char *str = string;

	if (str == NULL)
		return (0);
	while (*str)
		str++;

	return ((size_t)(str - string));
}
