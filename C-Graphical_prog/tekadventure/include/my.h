/*
** my.h for my.h in /home/roye_v/delivery/my_lib/include
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sat Feb 11 18:32:44 2017 Vincent Roye
** Last update Thu May 25 15:06:56 2017 dubret_v
*/

#ifndef MY_H_
# define MY_H_

typedef struct	s_puthexa
{
  int		j;
  int		l;
  char		*m;
}		t_puthexa;

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_put_nbr(int nb);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
int	my_int_swap(int *a, int *b);
int	my_printf(const char *s, ...);
int	my_getnbr(char *);
char	*my_realloc(char *str, int size);
char	*my_memset(char c, int len);
char	*my_put_hexa(unsigned int i);
char	*my_put_binary(unsigned int i);
char	*my_strcat(char *dest, char *src);
char	*my_revstr(char *str);
char	*my_strdup(char *str);
char	*my_strcpy(char *dest, char *src);
char	**str_to_wordtab(char *, char);
int	arr_len(char **);
int	is_only_digit(char **);

#endif
