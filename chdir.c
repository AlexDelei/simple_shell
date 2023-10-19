#include "main.h"
/**
 * cd - Change the current directory of the process.
 * @arguments: Pointer to the array of arguments.
 * @current_dir: Pointer to the current directory string.
 * Return: 0 on success, -1 on failure.
 */
int cd(char **arguments, char *current_dir)
{
	char *target_dir = arguments[1], *prev_dir = strdup(current_dir);
	char *new_dir = getcwd(NULL, 0);

	if (target_dir == NULL)
	{
		target_dir = getenv("HOME");
		if (target_dir == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return (-1);
		}
	}
	if (prev_dir == NULL)
	{
		perror("cd");
		return (-1);
	}
	if (chdir(target_dir) == -1)
	{
		perror("cd");
		free(prev_dir);
		return (-1);
	}
	if (new_dir == NULL)
	{
		perror("cd");
		free(prev_dir);
		return (-1);
	}
	if (setenv("PWD", new_dir, 1) == -1)
	{
		perror("cd");
		free(prev_dir);
		free(new_dir);
		return (-1);
	}
	printf("%s\n", new_dir);
	free(prev_dir);
	free(new_dir);
	return (0);
}
