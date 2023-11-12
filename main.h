#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>


#define BUFFER_SIZE 4096
/**
 * struct character_print - prints the data.
 * @c: character.
 * @func_p: function pointer
 */
typedef struct character_print
{
	char *c;
	int (*func_p)(va_list args);
} prints_d;

int _putchar(char c);
int _printf(const char *format, ...);
int p_c(va_list args);
int p_s(va_list args);
int per_cent(va_list args __attribute((unused)));
int df(va_list args);
int print_dif(long int len, long int n);
int dcc(va_list args);
int print_dig_c(long int len, long int n);
int bn(va_list args);
void sigint_handler(int sig);
void cd(char *dir);
char **parse_input(char *input);


#endif
