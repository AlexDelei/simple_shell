#include "main.h"
/**
 * stringdup - Duplicates a string
 * @str: String to be duplicated
 * Return: Pointer to the duplicated string
 */
char *stringdup(char *str)
{
	unsigned int len;
	char *duplicate;

	if (str == NULL)
		return (NULL);
	len = strlen(str);
	duplicate = (char *)malloc(sizeof(char) * (len + 1));
	if (duplicate == NULL)
		return (NULL);
	strcpy(duplicate, str);
	return (duplicate);
}
