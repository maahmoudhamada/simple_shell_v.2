#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <dirent.h>
#define EMPTYSTR ""
#define PROMPT "# "

extern char **environ;

/**
 * struct path_list - Structure holds environ. vars
 *
 * @data: data of each node
 * @next: Pointer of lstist type points to next node
 *
 * Description: Structure helps to build environement linked list
 */

typedef struct path_list
{
char *data;
struct path_list *next;
} lst;



/**
* struct cmd_info - Structure contains cmd data
* @cmd: Command line
* @filen: File name of shell
* @args: Arguments of command line
* @env_lst: linked list holds environment variables
* @pth_lst: Linked list holds path directories
* @cmdno: Number of line (for error)
* @exitstat: Exit status
*
* Description: contains data of cmd to execute cmd and format error messages
*/

typedef struct cmd_info
{
char *cmd;
char *filen;
char **args;
int cmdno;
int exitstat;
lst *env_lst;
lst *pth_lst;
lst *alias_lst;
char *fline;
int flag;
} node_d;

/**
 * struct builtin_functions - Structure for builtin commands
 *
 * @bcmd: Builtin command name
 * @bfunc: Corespon. builtin function
 *
 * Description: Structure to help find the correct builtin func
 */

typedef struct builtin_functions
{
char *bcmd;
int (*bfunc)(node_d *st);
} bstruc;



char *_strconcat(char *s1, char *s2, int flag);
void clean_memory(node_d *st);
int _isspace(char c);
int cmd_formating(node_d *st, ssize_t gt);
int data_handler(node_d *st);
void error_handling(node_d *st, char *erro_mssg);
void execution(node_d *st);
int file_validate(node_d *st);
void free2d(char **grid);
char **gridup(char **grid, int sz);
void readline(node_d *st, int mode);
int _strlen2d(char **grid);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *s);
int wordCount(char *s, char *deli);
char **tokenizer(char *s, char *deli);
int writer(char *buf, int fd);

char *linenum_convert(int n);


/* Path handling */
int _strlen2d(char **grid);



/* Builtin functions */



int (*built_selector(char *cmd))(node_d *st);

int builtin_check(node_d *st, char *cmd);
int exit_builtin(node_d *st);

int printenv_builtin(node_d *st, char *line);







/* environment list builder functions */

void free_list(lst *head);
lst *node_add(lst **head, char *str);
int lstist_build(node_d *st);

/* path list builder function */
char *_getenv(const char *name, node_d *st);
int path_builder(node_d *st);

int env_builtin(node_d *st);
void env_builder(node_d *st);





void custom_atoi(node_d *st);





int list_len(lst *head);
char **convert_list(lst *head);


int pre_setenv(node_d *st);
int _setenv(const char *name, const char *value, node_d *st);
int _unsetenv(const char *name, node_d *st);
int pre_unsetenv(node_d *st);

int check_name(const char *name);


int cd_builtin(node_d *st);
void data_collector(node_d *st);


void var_replacement(node_d *st);

int alias_builtin(node_d *st);
void print_list(lst *h, char *name);
void alias_builder(node_d *st, char *name, char *value);
void alias_extraction(node_d *st);

int value_surr(char **str);
#endif
