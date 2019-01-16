/*
** stock.c for stock.c in /home/frostiz/PSU_2016_minishell1
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Tue Jan 17 22:56:30 2017 thibaut trouve
** Last update Sun Jan 22 23:39:22 2017 thibaut trouve
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

char	*program_name(char *str)
{
  int   i;
  char  *name;

  name = malloc(sizeof(char) * my_strlen(str) + 1);
  if (name == NULL)
    return (NULL);
  i = 0;
  while (str[i] != ' ' && str[i] != '\0')
    {
      name[i] = str[i];
      i++;
    }
  name[i] = '\0';
  return (name);
}

char	**get_env(char **env)
{
  int   i;
  int   j;
  char  **my_env;

  if ((my_env = malloc(sizeof(char*) * (nb_env_var(env) + 2))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (env[i] != NULL)
    {
      if ((my_env[i] = malloc(sizeof(char) * my_strlen(env[i]) + 1)) == NULL)
	return (NULL);
      while (env[i][j] != '\0')
	{
	  my_env[i][j] = env[i][j];
	  j++;
	}
      my_env[i][j] = '\0';
      j = 0;
      i++;
    }
  my_env[i] = NULL;
  return (my_env);
}

void	clean_tab(char **tab, int *j, char *str, int opt)
{
  int	i;

  i = 0;
  if (opt == 1)
    {
      while (tab[i] != NULL)
	{
	  if (tab[i][0] == '\0')
	    tab[i] = NULL;
	  i++;
	}
    }
  else
    {
      while ((str[*j] == ' ' || str[*j] == '\t') && (str[*j] != '\0'))
	(*j)++;
    }
}

void	spacetab_found(t_count *count, char *str, char **tab)
{
  clean_tab(tab, &(count->i), str, 0);
  tab[count->k][count->j] = '\0';
  count->k++;
  count->j = 0;
  if ((tab[count->k] = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return ;
}

char	**get_args(char *str)
{
  char		**tab;
  t_count	count;

  init_struct(&count);
  if ((tab = malloc(sizeof(char*) * (getnb_args(str) + 2))) == NULL)
    return (NULL);
  if ((tab[0] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[count.i] != '\0')
    {
      clean_tab(tab, &(count.i), str, 0);
      if (str[count.i] == '\0')
	return (tab);
      tab[count.k][count.j] = str[count.i];
      count.i++;
      count.j++;
      if (str[count.i] == ' ' || str[count.i] == '\t')
	spacetab_found(&count, str, tab);
    }
  tab[count.k][count.j] = '\0';
  tab[count.k + 1] = NULL;
  clean_tab(tab, &(count.i), str, 1);
  return (tab);
}
