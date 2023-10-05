#include "main.h"
/**
 * stringcmp - Compares two strings
 * @str1: String to be compared
 * @str2: String to be compared
 * Return: 0 if the strings same, > 0 if str1 greater, < 0 if str2 greater
 */
int stringcmp(char *str1, char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
