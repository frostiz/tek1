/*
** get_next_line.c for get_next_line in /home/dubret_v/delivery/prog_elem/CPE_2016_getnextline
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu@epitech.net>
** 
** Started on  Sun Jan 15 02:52:11 2017 dubret_v
** Last update Mon Jan 16 16:29:35 2017 dubret_v
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"get_next_line.h"

char		*my_cat_realloc(char *str, char buff[])
{
  t_realoc	real;

  real.i = 0;
  real.j = 0;
  while (str[real.j] != '\0')
    real.j++;
  while (buff[real.i] != '\0')
    {
      str[real.j] = buff[real.i];
      real.i += 1;
      real.j += 1;
    }
  str[real.j] = '\0';
  real.tmp = malloc(sizeof(char) * ((real.j  + (READ_SIZE + 1))));
  if (real.tmp == NULL)
    return (NULL);
  real.i = 0;
  while (str[real.i] != '\0')
    {
      real.tmp[real.i] = str[real.i];
      real.i += 1;
    }
  real.tmp[real.i] = '\0';
  free(str);
  return (real.tmp);
}

void		reset_remainder(char remainder[])
{
  int		i;
  int		j;
  int		idx;

  i = 0;
  j = 0;
  idx = 0;
  while (remainder[i] != '\n' && remainder[i] != '\0')
    i++;
  remainder[i] = '\0';
  while (remainder[i + 1] != '\0')
    {
      remainder[j] = remainder[i + 1];
      remainder[i + 1] = '\0';
      j++;
      i++;
      idx = 1;
    }
  if (idx == 0)
    while (remainder[j] != '\0')
      {
	remainder[j] = '\0';
	j++;
      }
  remainder[i] = '\0';
}

int		checking_str(char *str, char remain[])
{
  int		i;
  int		idx;
  int		j;

  i = 0;
  idx = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n' && idx == 0)
	{
	  str[i] = '\0';
	  idx = 1;
	}
      else if (j < READ_SIZE + 1 && idx == 1)
	{
	  remain[j] = str[i];
	  j++;
	}
      i++;
    }
  return (idx);
}

char		*my_special_cat(char *str, char remainder[], int opt)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (opt == 0)
    {
      while (str[j] != '\0')
	j++;
      while (remainder[i] != '\n' && remainder[i] != '\0')
	{
	  str[j] = remainder[i];
	  i++;
	  j++;
	}
      str[j] = '\0';
      reset_remainder(remainder);
      return (str);
    }
  while (i < (READ_SIZE + 1))
    {
      str[i] = '\0';
      i++;
    }
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	remain[READ_SIZE + 1];
  t_buff	buff;

  buff.i = 0;
  if ((buff.str = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL || fd < 0)
    return (NULL);
  buff.str = my_special_cat(buff.str, remain, 1);
  while (((buff.size = read(fd, buff.buffer, READ_SIZE)) > 0))
    {
      if (buff.size < 0)
	return (NULL);
      buff.buffer[buff.size] = '\0';
      if (buff.i == 0 && remain[0] != '\0')
	{
	  buff.str = my_cat_realloc(buff.str, remain);
	  reset_remainder(remain);
	  buff.str = my_cat_realloc(buff.str, buff.buffer);
	  buff.i = 1;
	}
      else
	buff.str = my_cat_realloc(buff.str, buff.buffer);
      if ((checking_str(buff.str, remain)) == 1)
	return (buff.str);
    }
  return ((remain[0] != '\0') ? my_special_cat(buff.str, remain, 0) : NULL);
}
