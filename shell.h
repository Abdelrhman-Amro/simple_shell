#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define cmd_DELIM " \n"
#define pth_DELIM ":"
#define check_if_num(c) ((c >= 48) && (c <= 57))

extern char **environ;

/**
 * struct dirs_list - store dirs
 * @dir: dirs
 * @len: ln
 * @next: next pointer
 */
typedef struct dirs_list
{
	char *dir;
	int len;
	struct dirs_list *next;
} list_d;

/******Execute*****/
char *read_line(list_d *h);
char *read_stream(void);
int my_getchar(void);
char **Parse(char *line, char *delim);
int Execute(char **args);
int check_cmd(char **words, char *line, list_d *h);
int Built_in(char *cmd);
int Ex_Built_in(char **words, list_d *h);

/*****Built_in*****/
int my_exit(char **words, list_d *h);
int my_env(void);

/*****Dirs_list*****/
list_d *build_dirs();
list_d *add_dir(list_d **head, char *str);
void free_list(list_d *h);

/*****PATH*****/
char *find_path(list_d *h, char *cmd);
char *my_getenv(char *var);

/*****P1_strings*****/
size_t my_strlen(const char *m);
char *my_strchr(const char *str, int ch);
char *my_strcpy(char *dst, const char *src);
char *my_strdup(const char *src);
int my_strcmp(char *m1, char *m2);

/*****P2_strings*****/
size_t my_strspn(const char *m1, const char *m2);
int my_atoi(const char *buffer);


int my_putchar(char c);
void my_puts(char *str);
void my_print(char *str);


#endif
