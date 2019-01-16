/*
** control_keys.c for 42sh in /home/thibaut/Repository/PSU_2016_42sh
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri May 19 12:52:33 2017 Thibaut Trouvé
** Last update Sun May 21 15:21:37 2017 Vincent Roye
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<term.h>
#include	"read.h"

int		control_backline(char *str, int *cursor)
{
  (void)cursor;
  if (str[0] != '\0' && str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = '\0';
  printf("\n");
  return (1);
}

int		control_a(char *str, int *cursor)
{
  char	*seq;
  int	i;

  i = 0;
  seq = tgetstr("le", NULL);
  if (seq == NULL)
    return (84);
  while (i < (int)strlen(str) && *cursor > 0)
    {
      my_putstr(seq);
      (*cursor)--;
      i++;
    }
  return (0);
}

int		control_e(char *str, int *cursor)
{
  char	*seq;

  seq = tgetstr("nd", NULL);
  if (seq == NULL)
    return (84);
  while (*cursor < (int)strlen(str))
    {
      my_putstr(seq);
      (*cursor)++;
    }
  return (0);
}

int		control_l(char *str, int *cursor)
{
  char		*seq;

  (void)cursor;
  seq = tgetstr("cl", NULL);
  if (seq == NULL)
    return (84);
  my_putstr(seq);
  my_putstr("$> ");
  my_putstr(str);
  return (0);
}

int		control_del(char *str, int *cursor)
{
  char		*seq;

  if (*cursor > 0)
    {
      seq = tgetstr("le", NULL);
      if (seq == NULL)
	return (84);
      my_putstr(seq);
      seq = tgetstr("dc", NULL);
      if (seq == NULL)
	return (84);
      my_putstr(seq);
      (*cursor)--;
      del_char(str, *cursor);
    }
  return (0);
}
