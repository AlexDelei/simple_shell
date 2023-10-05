#include "main.h"
/**
 * path - Verify if the first command can be executed
 * @arguments: Array of entries by the user
 * Return: 0 if success, or -1 if the exe file doesn't exist
 */
int path(char **arguments)
{
	char *path, *dir, *command_path, *path_env = get_env("PATH");
	int exist_stat;

	if (path_env == NULL)
		return (-1);
	path = stringdup(path_env);
	free(path_env);
	dir = strtok(path, ":");
	while (dir != NULL)
	{
		command_path = add_command(dir, arguments[0]);
		exist_stat = isthere(command_path);
		free(command_path);
		if (exist_stat == 0)
		{
			free(path);
			arguments[0] = add_command(dir, arguments[0]);
			return (0);
		}
		dir = strtok(NULL, ":");
	}
	free(path);
	return (-1);
}
