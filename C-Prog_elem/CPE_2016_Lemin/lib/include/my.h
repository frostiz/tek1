/*
** my.h for my.h in /home/roye_v/delivery/PSU_2016/PSU_2016_minishell2/src/my/lib/include
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr  9 18:02:44 2017 Vincent Roye
** Last update Sun Apr 30 17:29:24 2017 Vincent Roye
*/

#ifndef MY_H_
# define MY_H_

typedef struct	s_puthexa
{
  int		j;
  int		l;
  char		*m;
}		t_puthexa;

void	my_putchar(char);
void	my_putstr(char *);
int	my_put_nbr(int);
int	my_getnbr(char *);
char	*my_realloc(char *, int);
char	*my_strcat(char *, char *);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*my_strdup(char *);
char	*my_revstr(char *);
void	my_strcpy(char *, char *);
int	my_strlen(char *);

#endif
