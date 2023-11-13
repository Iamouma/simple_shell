#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"


#define BUFFER_SIZE 256
#define MAX_ARGS 64

/**
 * show_prompt - it displays the command prompt.
 * Return: nothing.
 */
void show_prompt(void)
{
	if (getpid() == getpgrp())
	{
		write(STDOUT_FILENO, "# ", 2);
		fflush(stdout);
	}
}

/**
 * exit_command - checks for exit commands.
 * @input: pointer to a constant char string.
 */
void exit_command(const char *input)
{
	if (strcmp(input, "e") == 0 || strcmp(input, "q") == 0 || input[0] == '\n')
	{
		exit(0);
	}
}

/**
 * parse_input - breaks arguments.
 * @input: pointer to a char string.
 * Return: arguments passed.
 */
char **parse_input(char *input)
{
	char **args = malloc(MAX_ARGS * sizeof(char *));
	char *token = strtok(input, " \n\t\r");
	int len = 0;

	while (token != NULL)
	{
		args[len++] = token;
		token = strtok(NULL, " \n\t\r");
	}

	args[len] = NULL;
	return (args);
}

/**
 * run_command - executes entered command.
 * @args: array of string.
 */
void run_command(char **args)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error: fork failed");
		exit(0);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			printf("Error: command not found.\n");
			exit(0);
		}
	}
	else
	{
		int count;

		waitpid(pid, &count, 0);
	}
}

/**
 * run_shell - main function running the shell.
 * Return: nothing.
 */
void run_shell(void)
{
	char input[BUFFER_SIZE];
	char **args;

	while (1)
	{
		show_prompt();

		if (fgets(input, BUFFER_SIZE, stdin) == NULL || input[0] == '\n')
		{
			exit(0);
		}

		input[strcspn(input, "\n")] = '\0';
		if (feof(stdin))
		{
			write(STDOUT_FILENO, "\n", 2);
			exit(0);
		}

		exit_command(input);

		if (strncmp(input, "cd", 2) == 0)
		{
			args = parse_input(input);
			free(args);
			continue;
		}

		args = parse_input(input);
		if (args[0] != NULL && args[0][0] != '\0')
		{
			run_command(args);
			free(args);
		}
	}
}
