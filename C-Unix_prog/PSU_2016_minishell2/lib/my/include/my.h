/*
** my.h for libmy in /home/thibaut/Repository/PSU_2016_minishell2/lib/my
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Mon Apr  3 21:22:58 2017 Thibaut Trouvé
** Last update Fri Apr  7 17:13:56 2017 Thibaut Trouvé
*/

#ifndef _MY_H_
# define _MY_H_

int	my_strlen(char *);
int	my_tablen(char **);
char	**my_copy_tab(char **);
char	*my_strdup(char *);
void	my_strcat(char *, char *);
int	my_getnbr(char *);
void	my_strcpy(char *, char *);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*my_putstr(char *);
void	print_tab(char **);
void	free_tab(char **);
char	*my_realloc(char *, int);
int	is_alphanum(char);

#endif
