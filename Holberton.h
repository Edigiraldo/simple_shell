#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "/usr/include/paths.h"

char **PATH_dirs(char **environ);
char *strings_concat(char *PATH, char *command);
char **split_arguments(char *lineptr);
char *look_for_path(char *argv0, char **PATH_arr);
void call_command(char *av[], char *argv[], char **, char *, char **, int *);
void Exit(char *lineptr, char **argv, char **PATH_arr, char **environ);
void Env(char *lineptr, char **argv, char **PATH_arr, char **environ);
int look_for_built_in(char *lineptr, char **argv, char **PATH_arr, char **);
int main(int ac, char *av[]);
int _strlen(char *str);
int _atoi(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_getenv(const char *name, char **);
void print_prompt(void);
char *_strdup(char *str);
void print_error(char *message, int *parameter, char *message2);
char *int_str(int n);

#endif
