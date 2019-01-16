/*
** get_next_line.h for get_next_line in /home/dubret_v/delivery/prog_elem/CPE_2016_getnextline
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu@epitech.net>
** 
** Started on  Sat Jan  7 10:38:56 2017 dubret_v
** Last update Tue Jan 17 11:43:03 2017 dubret_v
*/

#ifndef GET_NEXT_LINE_
# define GET_NEXT_LINE_
# ifndef READ_SIZE
#  define READ_SIZE 1
# endif /* !READ_SIZE */

typedef struct	s_my_char
{
  char		buffer[READ_SIZE + 1];
  char		*str;
  int		size;
  int		i;
}		t_buff;

typedef struct	s_realloc
{
  int		i;
  int		j;
  char		*tmp;
}		t_realoc;

char	*get_next_line(const int);

#endif /* !GET_NEXT_LINE */
