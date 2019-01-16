/*
** my.h for my.h in /home/roye_v/delivery/PSU_2016/PSU_2016_minishell2
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr  9 18:08:20 2017 Vincent Roye
** Last update Sun Apr 30 17:29:59 2017 Vincent Roye
*/

#ifndef MY_H_
# define MY_H_

void	my_putchar(char);
void	my_putchar_e(char);
void	my_putstr(char *);
void	my_put_error(char *);
char	*my_realloc(char *, int);
char	*my_strcat(char *, char *);
int	my_strcmp(char *, char *);
int	my_getnbr(char *);
int	my_strncmp(char *, char *, int);
int	my_printf(const char *s, ...);
int	my_put_nbr(int);
int	array_len(char **);
char	*my_strdup(char *);
char	**realloc_tab(char **, char *);
char	*my_revstr(char *);
void	my_strcpy(char *, char *);
int	my_strlen(char *);

#endif
