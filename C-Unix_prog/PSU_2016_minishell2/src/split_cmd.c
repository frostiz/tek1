/*
** split_cmd.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed May  3 03:46:06 2017 Thibaut Trouvé
** Last update Wed May  3 06:13:28 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "main.h"
#include "my.h"

char	**extract_cmd(char **args, int idx, char c)
{
  int	i;
  int	j;
  char	**real_cmd;

  real_cmd = malloc(sizeof(char *) * (my_tablen(args) + 1));
  if (real_cmd == NULL)
    return (NULL);
  i = idx;
  j = 0;
  while (args[i] != NULL && args[i][0] != '|')
    {
      if (i == 0 || (args[i][0] != c && args[i - 1][0] != c))
	{
	  real_cmd[j] = args[i];
	  j++;
	}
      i++;
    }
  real_cmd[j] = NULL;
  return (real_cmd);
}

static t_split	*add_split_cmd(t_split *split, char **tab)
{
  t_split	*new;
  t_split	*tmp;

  new = malloc(sizeof(t_split));
  if (new == NULL)
    return (NULL);
  new->next = NULL;
  new->real_cmd = tab;
  if (split == NULL)
    return (new);
  tmp = split;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (split);
}

static char	**init_values(char **args, int *i, int *j)
{
  char	**tab;

  tab = malloc(sizeof(char *) * (my_tablen(args) + 1));
  if (tab == NULL)
    return (NULL);
  *i = 0;
  *j = 0;
  return (tab);
}

t_split	*split_cmd(t_split *split, char **args)
{
  int	i;
  int	j;
  char	**tab;

  tab = init_values(args, &i, &j);
  while (args[i] != NULL)
    {
      tab[j] = args[i];
      i++;
      j++;
      if (args[i] == NULL || args[i][0] == '|' )
	{
	  tab[j] = NULL;
	  split = add_split_cmd(split, tab);
	  tab = malloc(sizeof(char *) * (my_tablen(args) + 1));
	  if (tab == NULL)
	    return (NULL);
	  j = 0;
	  if (args[i] != NULL)
	    i++;
	}
    }
  return (split);
}
