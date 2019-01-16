/*
** my_wordtab_to_arrtab.c for minishell2 in /home/frostiz/Backup/minishell2/src
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Sun Apr  9 17:33:50 2017 thibaut trouve
** Last update Sun Apr  9 18:07:13 2017 thibaut trouve
*/

#include <stdlib.h>
#include "my.h"
#include "main.h"

static void	init_struct(t_count *i)
{
  i->line = 0;
  i->col = 0;
  i->idx = 0;
}

static int	count(char **tab, char *sep)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (tab[i] != NULL)
    {
      if (my_strcmp(tab[i], sep) == 0)
	count++;
      i++;
    }
  return (count + 1);
}

static int	fill_cmd(char ***cmd, t_count *i, char **tab, char *sep)
{
  cmd[i->line][i->col] = my_strdup(tab[i->idx]);
  if (cmd[i->line][i->col] == NULL)
    return (-1);
  i->idx++;
  i->col++;
  if (tab[i->idx] != NULL)
    {
      if (my_strcmp(tab[i->idx], sep) == 0)
	{
	  cmd[i->line][i->col] = NULL;
	  i->col = 0;
	  i->line++;
	  cmd[i->line] = malloc(sizeof(char *) * (my_tablen(tab) + 1));
	  if (cmd[i->line] == NULL)
	    return (-1);
	  i->idx++;
	}
    }
  else
    {
      cmd[i->line][i->col] = NULL;
      i->line++;
    }
  return (0);
}

char	***my_wordtab_to_arrtab(char **tab, char *sep)
{
  t_count	i;
  int		ret;
  char		***cmd;

  init_struct(&i);
  cmd = malloc(sizeof(char **) * (count(tab, sep) + 1));
  if (cmd == NULL)
    return (NULL);
  cmd[i.line] = malloc(sizeof(char *) * (my_tablen(tab) + 1));
  if (cmd[i.line] == NULL)
    return (NULL);
  while (tab[i.idx] != NULL)
    {
      ret = fill_cmd(cmd, &i, tab, sep);
      if (ret == -1)
	return (NULL);
    }
  if (i.line == 0)
    free(cmd[0]);
  cmd[i.line] = NULL;
  return (cmd);
}
