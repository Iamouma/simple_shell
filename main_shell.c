#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"

#define BUFFER_SIZE 256
#define MAX_ARGS 64

/**
 * main - takes in the command and executes it.
 * Return: 0 Successful.
 */
int main(void)
{
	run_shell();
	return (0);
}
