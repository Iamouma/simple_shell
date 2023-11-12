#include "main.h"
#include <libgen.h>
/**
 * cd - changes directory.
 * @dir: directory.
 * Return: 0 Success
 */
void cd(char *dir)
{
	char cwd[1024];
	char *dn;
	char *dp;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd() error");
		return;
	}
	if (chdir(dir) == -1)
	{
		perror("chdir() error");
		return;
	}
	dn = strdup(dir);
	dp = dn;
	if (dn != NULL)
	{
		dp = dirname(dn);
		if (chdir(dp) == -1)
		{
			perror("chdir() error");
			free(dn);
			return;
		}
		free(dn);
	}
	if (setenv("OLPWD", cwd, 1) == -1)
	{
		perror("setenv() error");
		return;
	}
	if (setenv("PWD", getcwd(cwd, sizeof(cwd)), 1) == -1)
	{
		perror("setenv() error");
		return;
	}
}
