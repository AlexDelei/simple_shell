#include "main.h"
/**
 * main - runs our shell
 * Return: exit status
 */
int main(void)
{
	ssize_t bytes_read = 0;
	size_t buffer_size = 0;
	char *entry = NULL, *arguments[20];
	int builtin_status, verify_status, exist_status, counter = 1, exit_status = 0;

	while (1)
	{
		prompt("$ ", 2);
		bytes_read = getline(&entry, &buffer_size, stdin);
		if (bytes_read == -1)
			break;
		if (*entry != '\n')
		{
			user_args(entry, arguments);
			if (arguments[0] != NULL)
			{
				exist_status = isthere(arguments[0]);
			if (exist_status != 0)
			{
				verify_status = path(arguments);
				if (verify_status == 0)
					exit_status = exec(arguments), free(entry);
				else
				{
					builtin_status = blt(arguments, exit_status);
					if (builtin_status != 0)
						exit_status = not_found(arguments, counter), free(entry);
				}
			}
			else
				exit_status = exec(arguments), free(entry);
			}
			else
				free(entry);
		}
		else
			free(entry);
		entry = NULL;
		counter++;
	}
	last_dealloc(entry);
	return (exit_status);
}
