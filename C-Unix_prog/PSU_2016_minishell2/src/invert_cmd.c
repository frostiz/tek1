/*
** invert_cmd.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2/src
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed May  3 04:32:42 2017 Thibaut Trouvé
** Last update Wed May  3 05:52:41 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "main.h"
#include "my.h"

static void	copy_end(int *i, int *j, char **tmp, char **tab)
{
  while (tab[*i] != NULL)
    {
      tmp[*j] = my_strdup(tab[*i]);
      (*j)++;
      (*i)++;
    }
  tmp[*j] = NULL;
}

static void	copy_mid(int *i, int *j, char **tmp, char **tab)
{
  while (tab[*i] && is_in(tab[*i][0], "><|") == 0)
    {
      tmp[*j] = my_strdup(tab[*i]);
      (*j)++;
      (*i)++;
    }
}

static void	copy_begin(int *i, int *j, char **tmp, char **tab)
{
  tmp[*j] = my_strdup(tab[*j]);
  (*j)++;
  (*i)++;
}

char	**invert(char **tab, int idx)
{
  int	i;
  int	j;
  char	**tmp;

  tmp = malloc(sizeof(char *) * (my_tablen(tab) + 1));
  if (tmp == NULL)
    return (NULL);
  j = 0;
  i = 0;
  while (j != idx)
    copy_begin(&i, &j, tmp, tab);
  i = idx + 2;
  copy_mid(&i, &j, tmp, tab);
  tmp[j] = my_strdup(tab[idx]);
  j++;
  tmp[j] = my_strdup(tab[idx + 1]);
  j++;
  copy_end(&i, &j, tmp, tab);
  return (tmp);
}

void	check_inverted(t_cmd *cmd)
{
  t_cmd	*tmp;
  int	i;

  tmp = cmd;
  while (tmp != NULL)
    {
      i = 0;
      while (tmp->args[i] != NULL)
	{
	  if (is_in(tmp->args[i][0], "><") == 1 &&
	      (i == 0 || is_in(tmp->args[i - 1][0], "|") == 1))
	    {
	      if (tmp->args[i + 1] &&
		  is_in(tmp->args[i + 1][0], "><|") == 0)
		{
		  if (tmp->args[i + 2] &&
		      is_in(tmp->args[i + 1][0], "><|") == 0)
		    tmp->args = invert(tmp->args, i);
		}
	    }
	  i++;
	}
      tmp = tmp->next;
    }
}
