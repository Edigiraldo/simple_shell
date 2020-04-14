#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char **PATH_dirs(void);
char *strings_concat(char *PATH, char *command);
char **split_arguments(char *lineptr);
char *look_for_path(char *argv0, char **PATH_arr);
void call_command(char *argv[], char **PATH_arr, char *lineptr);
void Exit(char *lineptr, char **argv, char **PATH_arr);
void Env(char *lineptr, char **argv, char **PATH_arr);
int look_for_built_in(char *lineptr, char **argv, char **PATH_arr);
int main(int ac, char *av[]);

#endif
