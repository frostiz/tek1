/*
** get_word.c for  in /home/thibaut/Repository/PSU_2016_42sh
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun May 21 16:27:45 2017 Thibaut Trouvé
** Last update Sun May 21 20:25:45 2017 Thibaut Trouvé
*/

#include <string.h>
#include <stdlib.h>
#include "read.h"

static void	copy(char *str, char *tmp, int *i, int *j)
{
  tmp[*j] = str[*i];
  if (str[*i] == '/')
    {
      tmp[*j] = '\0';
      *j = -1;
    }
  (*i)++;
  (*j)++;
}

char	*get_word(char *str, int *cursor)
{
  int	i;
  char	*tmp;
  int	j;

  tmp = malloc(sizeof(char) * (int)strlen(str) + 1);
  if (tmp == NULL)
    return (NULL);
  j = 0;
  i = *cursor;
  if (i < 0)
    return (str);
  if ((str[i] == ' ' || str[i] == '\t') && i > 0)
    i--;
  while (i > 0 && (str[i] != ' ' && str[i] != '\t'))
    i--;
  if (str[i] == ' ')
    i++;
  while (str[i] != ' ' && str[i] != '\t' && str[i] && i < *cursor)
    copy(str, tmp, &i, &j);
  tmp[j] = '\0';
  return (tmp);
}

char	*get_after_word(char *str, int *cursor)
{
  char	*after;

  after = strdup(&str[*cursor]);
  if (after == NULL)
    return (NULL);
  return (after);
}

char	*get_before_word(char *str, int *cursor)
{
  int	i;
  char	*tmp;

  tmp = malloc(sizeof(char) * (int)strlen(str) + 1);
  if (tmp == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0' && i < *cursor)
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = '\0';
  while (i > 0 && tmp[i] != ' ' && tmp[i] != '\t' && tmp[i] != '/')
    i--;
  if (tmp[i] == ' ' || tmp[i] == '\t' || tmp[i] == '/')
    i++;
  tmp[i] = '\0';
  return (tmp);
}
