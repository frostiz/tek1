/*
** my_read.c for my_read.c in /home/roye_v/delivery/PSU_2016_42sh
**
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
**
** Started on  Thu May 18 14:16:12 2017 Vincent Roye
** Last update Sun May 21 22:38:54 2017 Thibaut Trouvé
*/

#include        <stdlib.h>
#include        <term.h>
#include        <fcntl.h>
#include        <string.h>
#include        <unistd.h>
#include        <ncurses.h>
#include        <sys/ioctl.h>
#include	<stdlib.h>
#include	"read.h"

int		keep_reading(t_read *rd, t_hist *hist)
{
  rd->ret = which_control_sequences(rd->buff);
  if (rd->ret != -1)
    {
      rd->ret = control_sequences(rd->ret, &rd->cursor, rd->str);
      if (rd->ret == 84)
	return (0);
      else if (rd->ret == 1)
	{
	  hist->hist = add_history(rd->str, hist);
	  return (1);
	}
    }
  else
    rd->str = add_char(rd->str, &rd->cursor, rd->buff);
  return (2);
}

int		check_sequences(t_read *rd, t_hist *hist, t_keys *keys)
{
  rd->tmp = strdup(rd->str);
  rd->str = known_sequences(rd->ret, &rd->cursor, rd->str, hist);
  if (rd->str == NULL)
    return (1);
  else if (rd->str[0] != '\0' && strcmp(rd->tmp, rd->str) != 0 &&
	   strcmp(rd->buff, keys->remove) != 0)
    rd->cursor = (int)strlen(rd->str);
  free(rd->tmp);
  return (0);
}

static char	*which_value(t_read rd)
{
  if (rd.ret == 0)
    {
      free(rd.str);
      return (NULL);
    }
  else
    return (rd.str);
}

static void	my_mem_zero(t_read *rd)
{
  int		i;

  i = 0;
  while (i < 9)
    {
      rd->buff[i] = '\0';
      i++;
    }
}

char		*read_command(t_keys *keys, t_hist *hist)
{
  t_read	rd;

  rd.cursor = 0;
  rd.str = malloc(sizeof(char));
  if (rd.str == NULL)
    return (NULL);
  rd.str[0] = '\0';
  my_mem_zero(&rd);
  while ((rd.size = read(0, rd.buff, 7)))
    {
      rd.buff[rd.size] = '\0';
      rd.ret = which_sequences(keys, rd.buff);
      if (rd.ret != -1)
	{
	  if (check_sequences(&rd, hist, keys) == 1)
	    return (NULL);
	}
      else if (rd.buff[0] >= 0)
	{
	  rd.ret = keep_reading(&rd, hist);
	  if (rd.ret == 0 || rd.ret == 1)
	    return (which_value(rd));
	}
    }
  return (NULL);
}
