#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

extern char **environ;
char *input(void);
char **tokenizer(char *input);
int executer(char **command, char **argv, int ind);
char *get_environ(char *var);
void free_arr(char **arr);
void error_printer(char *name, int ind, char *cmd);
char *path_geter(char *command);
void envi(char **command, int *status);
void exiter(char **command, char **argv, int *status, int ind);
void variable_replacer(char **command, int status);
void comment_handler(char ***comms);
int _strlen(char *s);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_itoa(int m);
void string_reverser(char *str, int length);
int is_num(char *str);
int _atoi(char *str);

#endif
