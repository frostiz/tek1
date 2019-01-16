/*
** get_next_line.h for get_next_line.h in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sat Apr 22 21:30:27 2017 Vincent Roye
** Last update Sat Apr 29 17:13:01 2017 Vincent Roye
*/

#ifndef GET_NEXT_LINE_
# define GET_NEXT_LINE_
# ifndef READ_SIZE
#  define READ_SIZE (1)
# endif

typedef struct s_get
{
  char	buffer[READ_SIZE + 1];
  char	*str;
  int	i;
  int	j;
  int	size;
}		t_get;

char	*get_next_line(const int fd);

#endif
