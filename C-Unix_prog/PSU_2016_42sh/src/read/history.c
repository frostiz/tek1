/*
** history.c for history.c in /home/roye_v/delivery/PSU_2016_42sh
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Fri May 19 14:04:39 2017 Vincent Roye
** Last update Sun May 21 22:32:49 2017 Thibaut Trouvé
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"read.h"
#include	"exec.h"

int		is_only_space(char *str)
{
  int		i;
  int		space;

  i = 0;
  space = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' ||  str[i] == '\t')
	space++;
      i++;
    }
  if (space == i)
    return (1);
  return (0);
}

char		**realloc_tab(char **history, char *str)
{
  char		**tmp;
  int		row;

  row = 0;
  tmp = malloc(sizeof(char *) * (array_len(history) + 2));
  if (tmp == NULL)
    return (NULL);
  while (history[row] != NULL)
    {
      tmp[row] = strdup(history[row]);
      free(history[row]);
      row++;
    }
  tmp[row] = strdup(str);
  tmp[row + 1] = NULL;
  free(history);
  return (tmp);
}

char		**add_history(char *str, t_hist *hist)
{
  if (str[0] == '\0' || is_only_space(str) == 1)
    return (hist->hist);
  hist->hist = realloc_tab(hist->hist, str);
  hist->len++;
  hist->idx = hist->len;
  return (hist->hist);
}
