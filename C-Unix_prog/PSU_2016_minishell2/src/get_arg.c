/*
** get_arg.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Apr  9 16:56:31 2017 Thibaut Trouvé
** Last update Sun Apr  9 18:11:51 2017 thibaut trouve
*/

#include <stdlib.h>
#include "main.h"
#include "my.h"

static void	init_struct(t_count *i)
{
  i->col = 0;
  i->line = 0;
  i->idx = 0;
}

static int	stock_quote(char **tab, char *input, t_count *i)
{
  if (input[i->idx] == '"')
    {
      i->col = 0;
      tab[i->line] = malloc(sizeof(char) * my_strlen(&input[i->idx]) + 1);
      if (tab[i->line] == NULL)
	return (-1);
      i->idx++;
      while (input[i->idx] != '"' && input[i->idx] != '\0')
	{
	  tab[i->line][i->col] = input[i->idx];
	  i->idx++;
	  i->col++;
	}
      if (input[i->idx] == '\0')
	return (-1);
      i->idx++;
      tab[i->line][i->col] = '\0';
      i->line++;
    }
  return (0);
}

static int	stock_char(char **tab, char *input, t_count *i)
{
  if ((is_alphanum(input[i->idx]) == 1 ||
       is_in(input[i->idx], "/-$?.,_=:") == 1)
      && input[i->idx] != '\0')
    {
      i->col = 0;
      tab[i->line] = malloc(sizeof(char) * my_strlen(&input[i->idx]) + 1);
      if (tab[i->line] == NULL)
	return (-1);
      while ((is_alphanum(input[i->idx]) == 1 ||
	      is_in(input[i->idx], "/-$?.,_=:") == 1)
	     && input[i->idx] != '\0')
	{
	  tab[i->line][i->col] = input[i->idx];
	  i->idx++;
	  i->col++;
	}
      tab[i->line][i->col] = '\0';
      i->line++;
    }
  return (0);
}

static int	stock_ops(char **tab, char *input, t_count *i)
{
  if ((input[i->idx] == '>' || input[i->idx] == '<' ||
       input[i->idx] == ';' || input[i->idx] == '|' ||
       input[i->idx] == '-')
      && input[i->idx] != '\0')
    {
      i->col = 0;
      tab[i->line] = malloc(sizeof(char) * my_strlen(&input[i->idx]) + 1);
      if (tab[i->line] == NULL)
	return (-1);
      while ((input[i->idx] == '>' || input[i->idx] == '<' ||
	      input[i->idx] == ';' || input[i->idx] == '|')
	     && input[i->idx] != '\0')
	{
	  tab[i->line][i->col] = input[i->idx];
	  i->idx++;
	  i->col++;
	}
      tab[i->line][i->col] = '\0';
      i->line++;
      i->idx--;
    }
  return (0);
}

char	**get_args(char *input)
{
  t_count	i;
  int		ret;
  char		**tab;

  init_struct(&i);
  tab = malloc(sizeof(char *) * (my_strlen(input) + 1));
  if (tab == NULL)
    return (NULL);
  while (input[i.idx] != '\0')
    {
      ret = stock_char(tab, input, &i);
      if (ret == -1)
	return (NULL);
      ret = stock_ops(tab, input, &i);
      if (ret == -1)
	return (NULL);
      ret = stock_quote(tab, input, &i);
      if (ret == -1)
	return (NULL);
      if (input[i.idx] != '\0')
	i.idx++;
    }
  tab[i.line] = NULL;
  return (tab);
}
