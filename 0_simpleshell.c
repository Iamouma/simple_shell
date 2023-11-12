#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"
/**
 * main - takes command and executes it.
 * Return: 0 Successful
 */
int main(void)
{
	char input[BUFFER_SIZE];
	char **args;
	pid_t pid;

	signal(SIGKILL, sigint_handler);

	while (1)
	{
		if (getpid() == getgrp())
		{
			write(STDOUT_FILENO, "> ", 2);
			fflush(stdout);
		}

		if (fgets(input, BUFFER_SIZE, stdin) == NULL || input[0] == '\n')
		{
			exit(0);
			continue;
		}
		input[strcspn(input, "\n")] = '\0';

		if (feof(stdin))
		{
			write(STDOUT_FILENO, "\n", 2);
			exit(0);
		}

		if (strcmp(input, "e") == 0 || strcmp(input, "q") == 0 || input[0] == '\n')
		{
			exit(0);
			continue;
		}

		if (strncmp(input, "cd", 2) == 0)
		{
			args = parse_input(input);

			cd(args[1]);

			free(args);
			continue;
		}

		args = parse_input(input);

		if (args[0] != NULL && args[0][0] != '\0')
		{
			pid = fork();

			if (pid == -1)
			{
				perror("Error: fork failed");
				exit(0);
			}
			else if (pid == 0)
			{
				if (execvp(args[0], args) == -1)
				{
					_printf("Error: command not found.\n");
					exit(0);
				}
			}
			else
			{
				int count;
				waitpid(pid, &count, 0);
			}

			free(args);
		}
	}
	return (0);
}

/**
 * parse_input - braeks args.
 * @input: user input.
 * Return: arg passed.
 */
#define MAX_ARGS 64
char **parse_input(char *input)
{
	char **args = malloc(MAX_ARGS * sizeof(char *));
	char *token = strtok(input, "\n\t\r");
	int len = 0;

	while (token != NULL)
	{
		args[len++] = token;
		token = strtok(NULL, "\n\t\r");
		;
	}
	args[len] = NULL;
	return (args);
}
