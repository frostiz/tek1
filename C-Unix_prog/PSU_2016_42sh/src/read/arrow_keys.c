/*
** keys.c for 42sh in /home/thibaut/Repository/PSU_2016_42sh
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri May 19 12:24:08 2017 Thibaut Trouvé
** Last update Sun May 21 20:19:01 2017 Vincent Roye
*/

#include	<stdio.h>
#include	<string.h>
#include	<term.h>
#include	<stdlib.h>
#include	"read.h"

int		init_keys(t_keys *keys)
{
  keys->right = tigetstr("kcuf1");
  if (keys->right == (char *) -1)
    return (-1);
  keys->left = tigetstr("kcub1");
  if (keys->left == (char *) -1)
    return (-1);
  keys->up = tigetstr("kcuu1");
  if (keys->up == (char *) -1)
    return (-1);
  keys->down = tigetstr("kcud1");
  if (keys->down == (char *) -1)
    return (-1);
  keys->remove = tigetstr("kdch1");
  if (keys->remove == (char *) -1)
    return (-1);
  return (0);
}

char		*keys_right(char *str, int *cursor, t_hist *hist)
{
  (void)hist;
  char		*seq;

  seq = tgetstr("nd", NULL);
  if (seq == NULL)
    return (NULL);
  if (*cursor < (int)strlen(str))
    {
      my_putstr(seq);
      (*cursor)++;
    }
  return (str);
}

char		*keys_left(char *str, int *cursor, t_hist *hist)
{
  char		*seq;

  (void)hist;
  (void)str;
  seq = tgetstr("le", NULL);
  if (seq == NULL)
    return (NULL);
  if (*cursor > 0)
    {
      my_putstr(seq);
      (*cursor)--;
    }
  return (str);
}

char		*keys_remove(char *str, int *cursor, t_hist *hist)
{
  char		*seq;

  (void)hist;
  if (*cursor >= 0)
    {
      seq = tgetstr("dc", NULL);
      if (seq == NULL)
	return (NULL);
      my_putstr(seq);
      del_char(str, *cursor);
    }
  return (str);
}
