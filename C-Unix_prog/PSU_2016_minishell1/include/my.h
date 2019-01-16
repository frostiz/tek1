/*
** my.h for my.h in /home/frostiz/PSU_2016_minishell1/include
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Mon Jan 16 14:03:41 2017 thibaut trouve
** Last update Tue Jan 24 15:11:39 2017 thibaut trouve
*/

#ifndef MY_H_
# define MY_H_
# define INEXISTANT 1
# define NOT_DIR 2

#include <stdarg.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include "get_next_line.h"

typedef struct	s_paths
{
  char old_pwd[2000];
  char pwd[2000];
  char *old_tmp;
  char *tmp;
  char  *new_path;
}		t_path;

typedef struct	s_count
{
  int	i;
  int	j;
  int	k;
}		t_count;

typedef struct stat t_stat;

char	*get_next_line(const int);
int     my_strlen(char *str);
void    my_putchar(char c);
int     my_putstr(char *str);
int     nb_env_var(char **env);
int     getnb_args(char *str);
char    **get_env(char **env);
char    **get_args(char *str);
char    *test_paths(char **tab, char **my_env);
char	**get_env(char **env);
char	*program_name(char *str);
int     find_path(char **my_env);
int	my_strncmp(char *, char *, int);
int	my_strcmp(char *, char *);
int	is_existing_prog(char *, char *);
void	aff_env(char **);
int	my_printf(char *, ...);
char	*my_strcpy(char *, char *);
char	*my_strcat(char *, char *);
char	*my_strdup(char *);
int	my_strlen(char *);
char    **get_env(char **);
int	is_slash(char *);
char    *find_good_path(int, char *, char **, char **);
char    *test_paths(char **tab, char **my_env);
void    init_struct(t_count *count);
void    clean_tab(char **tab, int *j, char *str, int opt);
void    spacetab_found(t_count *count, char *str, char **tab);
char    **get_args(char *str);
int     check_env_var(char **my_env, char *var_name);
char    **pop_var_in_env(char **my_env, char *var_name, char *var_value);
void    modify_var_env(char **, int, char *, char *);
int     check_name_validity(char *name);
void    my_setenv(char ***my_env, char *var_name, char *var_value);
void    del_var_from_env(char **my_env, int pos_var);
void    my_unsetenv(char ***my_env, char **tab);
char    *get_var_env_value(char **my_env, char *var_name);
void    go_home(char ***my_env, char *tmp[2000]);
void    go_back(t_path *path, char ***my_env);
char    *get_cd_path(t_path *path, char **tab);
int     change_path(t_path *path, char **tab, t_stat file);
void    change_directory(char **tab, char ***my_env);
void    sign_handler(int sign);
int     env_command(char **tab, char ***my_env);
int     builtin(char **tab, char ***my_env);
void    execute(char *correct_path, char **tab, char **my_env);
void    basic_programs(char **tab, char ***my_env, char **argv);
int     my_isatty(int fd);
void    free_my_env(char **my_env);
int     minishell_1(char **argv, char **env);
int	is_folder(char *);
int	test_chdirpath(char **);
void	check_status(int);
char    *clearstr(t_str *strings, char *remain, t_pos *pos);
int	my_getnbr(char *);

#endif /* MY_H */
