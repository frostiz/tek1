/*
** setenv.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Wed May 17 15:08:19 2017 Lucas Dumy
** Last update Thu May 18 21:05:21 2017 Lucas Dumy
*/

#include	<stdlib.h>
#include	<string.h>
#include	"mysh.h"

static int	line_to_add(char **env, char *str)
{
  int		i;

  i = 0;
  while (env != NULL && env[i] != NULL)
    {
      if (strncmp(str, env[i], strlen(str)) == 0 &&
	  env[i][strlen(str)] == '=')
	return (i);
      i++;
    }
  return (i);
}

static void	one_variable(char **new_env, char *str)
{
  int		i;

  i = 0;
  *new_env = malloc(sizeof(char) * (strlen(str) + 2));
  if (*new_env == NULL)
    exit(84);
  while (str[i] != '\0')
    {
      (*new_env)[i] = str[i];
      i++;
    }
  (*new_env)[i] = '=';
  (*new_env)[i + 1] = '\0';
}

static void	two_variables(char **new_env, char *str1, char *str2)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  *new_env = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 2));
  if (*new_env == NULL)
    exit(84);
  while (str1[i] != '\0')
    {
      (*new_env)[i] = str1[i];
      i++;
    }
  (*new_env)[i] = '=';
  while (str2[j] != '\0')
    {
      (*new_env)[i + j + 1] = str2[j];
      j++;
    }
  (*new_env)[i + j + 1] = '\0';
}

static int	setenv_error(char **tab)
{
  if (tab[2] != NULL && tab[3] != NULL)
    {
      my_perror("setenv: Too many arguments.\n");
      return (1);
    }
  else if ((tab[1][0] > 'Z' && tab[1][0] < 'a' && tab[1][0] != '_') ||
	   tab[1][0] < 'A' || tab[1][0] > 'z')
    {
      my_perror("setenv: Variable name must begin with a letter.\n");
      return (1);
    }
  else if (my_is_alphanum(tab[1]) == -1)
    {
      my_perror("setenv: Variable name must contain ");
      my_perror("alphanumeric characters.\n");
      return (1);
    }
  return (0);
}

void		my_setenv(char **tab, char ***env, int *return_value, int *fd)
{
  int		line;

  if (tab[1] == NULL)
    my_env(tab, env, return_value, fd);
  else if (setenv_error(tab) == 1)
    {
      *return_value = 1;
      return ;
    }
  else if (fd[2] == -1)
    {
      line = line_to_add(*env, tab[1]);
      if ((*env)[line] == NULL)
	*env = my_envdup(*env, 1, return_value);
      if (*return_value == 1)
	return ;
      if (tab[2] == NULL)
	one_variable(&((*env)[line]), tab[1]);
      else
	two_variables(&((*env)[line]), tab[1], tab[2]);
    }
  *return_value = 0;
}
