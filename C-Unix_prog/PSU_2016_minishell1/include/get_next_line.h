/*
** get_next_line.h for get_next_line.h in /home/frostiz/CPE_2016_getnextline
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Tue Jan  3 14:03:52 2017 thibaut trouve
** Last update Sun Jan 22 16:33:57 2017 thibaut trouve
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# ifndef READ_SIZE
#  define READ_SIZE 200000
# endif /* !READ_SIZE */

#include <stdlib.h>
#include <unistd.h>

typedef	struct	s_my_pos
{
  int	src;
  int	dest;
}		t_pos;

typedef	struct	s_my_str
{
  char	*str;
  char	buffer[READ_SIZE];
}		t_str;

int     init_check_error(char **, t_pos *, int, char **);
int     my_strcpy_len(char *, char *, t_pos *, char);
char    *clean_fill_remain(t_str *, char *, t_pos *, int);
char    *my_realloc(char *, int, t_pos);
char    *get_next_line(const int);

#endif /* GET_NEXT_LINE_H_ */
