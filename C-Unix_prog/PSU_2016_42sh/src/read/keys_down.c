/*
** keys_down.c for keys_down.c in /home/roye_v/delivery/PSU_2016_42sh
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 21 14:51:41 2017 Vincent Roye
** Last update Sun May 21 16:18:32 2017 dubret_v
*/

#include	<stdlib.h>
#include	<string.h>
#include	<ncurses.h>
#include	<term.h>
#include	"read.h"

static char	*end_array(t_hist *hist, int *cursor)
{
  char		*seq;

  hist->idx = hist->len;
  seq = tgetstr("dl", NULL);
  if (seq == NULL)
    return (NULL);
  my_putstr(seq);
  my_putstr("$> ");
  hist->idx = hist->len;
  *cursor = 0;
  return (strdup(""));
}

char		*keys_down(__attribute__ ((unused)) char *str,
			   int *cursor,
			   t_hist *hist)
{
  char		*seq;

  hist->idx++;
  if (hist->idx > hist->len)
    return (end_array(hist, cursor));
  else if (hist->hist[hist->idx] == NULL)
    {
      hist->idx = hist->len;
      seq = tgetstr("dl", NULL);
      if (seq == NULL)
	return (NULL);
      my_putstr(seq);
      my_putstr("$> ");
      hist->idx = hist->len;
      *cursor = 0;
      return (strdup(""));
    }
  else
    seq = tgetstr("dl", NULL);
  if (seq == NULL)
    return (NULL);
  my_putstr(seq);
  my_putstr("$> ");
  my_putstr(hist->hist[hist->idx]);
  return (strdup(hist->hist[hist->idx]));
}
