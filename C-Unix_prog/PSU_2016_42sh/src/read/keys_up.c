/*
** keys_up.c for keys_up.c in /home/roye_v/delivery/PSU_2016_42sh
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 21 14:43:19 2017 Vincent Roye
** Last update Sun May 21 16:18:46 2017 dubret_v
*/

#include	<stdlib.h>
#include	<string.h>
#include	<ncurses.h>
#include	<term.h>
#include	"read.h"

static char	*less_than_zero(t_hist *hist)
{
  char		*seq;

  hist->idx = 0;
  seq = tgetstr("dl", NULL);
  if (seq == NULL)
    return (NULL);
  my_putstr(seq);
  my_putstr("$> ");
  my_putstr(hist->hist[hist->idx]);
  return (strdup(hist->hist[hist->idx]));
}

static char	*last_string(t_hist *hist)
{
  char		*seq;

  seq = tgetstr("dl", NULL);
  if (seq == NULL)
    return (NULL);
  my_putstr(seq);
  my_putstr("$> ");
  my_putstr(hist->hist[hist->idx]);
  return (strdup(hist->hist[hist->idx]));
}

char		*keys_up(char *str, int *cursor, t_hist *hist)
{
  (void)str;
  (void)cursor;
  char		*seq;

  hist->idx--;
  if (hist->idx < 0)
    {
      hist->idx = 0;
      return (str);
    }
  else if (hist->idx < 0 && hist && hist->hist[0] != NULL)
    return (less_than_zero(hist));
  else if (hist->hist[hist->idx] == NULL && hist->len > 0)
    return (last_string(hist));
  else if (hist->idx >= 0)
    {
      seq = tgetstr("dl", NULL);
      if (seq == NULL)
	return (NULL);
      my_putstr(seq);
      my_putstr("$> ");
      my_putstr(hist->hist[hist->idx]);
      return (strdup(hist->hist[hist->idx]));
    }
  return (str);
}
