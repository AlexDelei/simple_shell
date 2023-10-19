#include "main.h"
/**
 * blt - Verify if the input is a builtin
 * @arguments: Pointer to the array of arguments
 * @exit_stat: Current exit status
 * @current_dir: navigates through directories
 * Return: -1 if the command is not a builtin, 0 if it is
 */
int blt(char **arguments, int exit_stat, char *current_dir)
{
	char *builtins[] = {"exit", "env", "cd"}, **env_ptr;
	int num_builtins = sizeof(builtins) / sizeof(char *);
	int i;

	for (i = 0; i < num_builtins; i++)
	{
		if (stringcmp(arguments[0], builtins[i]) == 0)
		break;
	}
	if (i == num_builtins)
		return (-1);
	if (stringcmp(builtins[i], "exit") == 0)
	{
		if (arguments[1] != NULL)
		{
			if (is_numeric(arguments[1]))
				exit_stat = atoi(arguments[1]);
			else
			{
				fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", arguments[1]);
				exit_stat = 2;
			}
		}
		else
			exit_stat = 2;
		free(arguments[0]);
		exit(exit_stat);
	}
	else if (stringcmp(builtins[i], "env") == 0)
	{
		if (environ == NULL)
			return (0);
		env_ptr = environ;
		while (*env_ptr)
		{
			printf("%s\n", *env_ptr);
			env_ptr++;
		}
	}
	else if (stringcmp(builtins[i], "cd") == 0)
	{
		if (arguments[1] == NULL)
		{
			if (chdir(getenv("HOME")) != 0)
			{
				perror("cd");
				return (-1);
			}
		}
		else
		{
			if (chdir(arguments[1]) != 0)
			{
				perror("cd");
				return (-1);
			}
		}
		if (getcwd(current_dir, PATH_MAX) == NULL)
		{
			perror("getcwd");
			return (-1);
		}
	}
	return (0);
}
