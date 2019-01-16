/*
** full_command_to_wordtab.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2/src
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed May  3 06:05:07 2017 Thibaut Trouvé
** Last update Wed May  3 06:14:51 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "main.h"
#include "my.h"

static int	count_char(char *str, char c)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	count++;
      i++;
    }
  return (count);
}

static int	new_line(t_count *i, char **args, char *str)
{
  if (i->line != -1)
    args[i->line][i->col] = '\0';
  i->line++;
  args[i->line] = malloc(sizeof(char) * my_strlen(&str[i->idx]) + 1);
  if (args[i->line] == NULL)
    return (-1);
  i->col = 0;
  return (0);
}

static void	put_null(t_count i, char **args)
{
  if (i.col != 0)
    {
      args[i.line][i.col] = '\0';
      args[i.line + 1] = NULL;
    }
  else
    args[i.line] = NULL;
}

static void	init_struct(t_count *i)
{
  i->col = 0;
  i->line = -1;
  i->idx = 0;
}

char		**full_command_to_wordtab(char *str, char sep)
{
  t_count	i;
  char		**args;

  args = malloc(sizeof(char *) * (count_char(str, sep) + 1 + 1));
  if (args == NULL)
    return (NULL);
  init_struct(&i);
  if (str[0] == '\0')
    {
      args[0] = NULL;
      return (args);
    }
  while (str[i.idx] != '\0')
    {
      if (str[i.idx] == sep || i.idx == 0)
	new_line(&i, args, str);
      if (str[i.idx] != sep)
	{
	  args[i.line][i.col] = str[i.idx];
	  i.col++;
	}
      i.idx++;
    }
  put_null(i, args);
  return (args);
}
