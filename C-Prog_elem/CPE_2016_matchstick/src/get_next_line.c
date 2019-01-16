/*
** test.c for get_next_line.c in /home/frostiz/CPE_2016_getnextline
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Tue Jan 10 22:04:47 2017 thibaut trouve
** Last update Sun Feb 26 15:01:52 2017 
*/

#include "get_next_line.h"

int	init_check_error(char **remain, t_pos *pos, int fd, char **str)
{
  static int	bool = 1;

  if (fd == -1 || READ_SIZE > 4294967295)
    return (84);
  if (bool == 1)
    {
      if ((*remain = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
	return (84);
      *remain[0] = '\0';
      bool = 0;
    }
  pos->dest = 0;
  pos->src = 0;
  if ((*str = malloc(sizeof(char) * (READ_SIZE * 2 + 2))) == NULL)
    return (84);
  return (0);
}

int	my_strcpy_len(char *dest, char *src, t_pos *pos, char opt)
{
  int	i;

  i = 0;
  if (opt == '\n' || opt == '\0')
    {
      while (src[pos->src] != opt && src[pos->src] != '\0')
	{
	  dest[pos->dest] = src[pos->src];
	  pos->dest++;
	  pos->src++;
	}
      dest[pos->dest] = '\0';
      return (src[pos->src] == '\n' ? -3 : -2);
    }
  else
    {
      while (src[i] != '\0')
	i++;
      return (i);
    }
  return (-1);
}

char	*clean_fill_remain(t_str *strings, char *remain, t_pos *pos, int opt)
{
  if (opt == 1)
    {
      if (strings->buffer[++(pos->src)] != '\0' && remain != NULL)
	{
	  pos->dest = 0;
	  my_strcpy_len(remain, strings->buffer, pos, '\0');
	}
      while (remain[0] == '\n')
	{
	  pos->dest = 0;
	  pos->src = 1;
	  my_strcpy_len(remain, remain, pos, '\0');
	}
      return (strings->str);
    }
  pos->src++;
  pos->dest = 0;
  my_strcpy_len(remain, remain, pos, '\0');
  while (remain[0] == '\n')
    {
      pos->dest = 0;
      pos->src = 1;
      my_strcpy_len(remain, remain, pos, '\0');
    }
  return (strings->str);
}

char	*my_realloc(char *str, int size, t_pos pos)
{
  char	*new;

  new = malloc(sizeof(char) * (size + my_strcpy_len(str, str, &pos, 1) + 1));
  if (new == NULL)
    return (NULL);
  pos.dest = 0;
  pos.src = 0;
  my_strcpy_len(new, str, &pos, '\0');
  return (new);
}

char	*get_next_line(const int fd)
{
  t_str		strings;
  t_pos		pos;
  int		size;
  static char	*remain = NULL;

  if (init_check_error(&remain, &pos, fd, &strings.str) == 84)
    return (NULL);
  if (remain[0] != '\0')
    if (my_strcpy_len(strings.str, remain, &pos, '\n') == -3)
      return (clean_fill_remain(&strings, remain, &pos, 0));
    else if (remain[0] != '\0')
      {
	remain[0] = '\0';
	pos.dest = my_strcpy_len(strings.str, strings.str, &pos, 1);
	pos.src = 0;
      }
  while ((size = read(fd, strings.buffer, READ_SIZE)) > 0)
    {
      strings.buffer[size] = '\0';
      if (my_strcpy_len(strings.str, strings.buffer, &pos, '\n') == -3)
	return (clean_fill_remain(&strings, remain, &pos, 1));
      strings.str = my_realloc(strings.str, READ_SIZE, pos);
      pos.src = 0;
    }
  return (NULL);
}

