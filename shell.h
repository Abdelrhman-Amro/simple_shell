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

/*****dirs*****/
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
} d_list;
d_list *Dirs();
d_list *add_D(d_list **h, char *s);
void free_L(d_list *h);

/******Execute*****/
char *take_line(d_list *h);
char *read_stream(void);
int my_getchar(void);
char **Parse(char *line, char *delim);
int Execute(char **args);
int check_cmd(char **words, char *line, d_list *h);
int Built_in(char *cmd);
int Ex_Built_in(char **words, d_list *h);

/*****Built_in*****/
int my_exit(char **words, d_list *h);
int my_env(void);

/*****PATH*****/
char *find_path(d_list *h, char *cmd);
char *my_getenv(char *var);

/*****str_handler_1*****/
size_t str_len(const char *s);
char *str_chr(const char *s, char c);
char *str_cpy(char *d, const char *s);
char *str_dup(const char *s);
int str_cmp(char *s1, char *s2);

/*****str_handler_2*****/
int a_to_i(const char *s);
size_t str_spn(const char *s1, const char *s2);

/*****output*****/
int print_char(char c);
void print_newline(char *s);
void print_no_newline(char *s);

#endif
