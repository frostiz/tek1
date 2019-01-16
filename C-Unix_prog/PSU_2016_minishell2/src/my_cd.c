/*
** my_cd.c for minishell1 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Apr  5 23:39:59 2017 Thibaut Trouvé
** Last update Tue May  2 12:07:23 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "my.h"
#include "main.h"

static void	go_home(char **env)
{
  char	*home;

  home = get_var_env_value(env, "HOME");
  if (home != NULL)
    chdir(home);
  else
    my_putstr("HOME not found in environnement.\n");
}

static char	**create_setenv_tab(char *var, char *value)
{
  char	**tab;

  tab = malloc(sizeof(char *) * 4);
  if (tab == NULL)
    return (NULL);
  tab[0] = my_strdup("setenv");
  tab[1] = my_strdup(var);
  tab[2] = my_strdup(value);
  tab[3] = NULL;
  return (tab);
}

static void	go_back(t_tab **data)
{
  char	*actual;
  char	*old;
  char	**tab;
  char	path[2000];

  old = get_var_env_value((*data)->my_env, "OLDPWD");
  if (old == NULL)
    {
      my_putstr("OLDPWD not found in environnement.\n");
      return ;
    }
  actual = my_strdup(getcwd(path, 2000));
  chdir(old);
  tab = create_setenv_tab("PWD", old);
  my_setenv(tab, data);
  free_tab(tab);
  tab = create_setenv_tab("OLDPWD", actual);
  my_setenv(tab, data);
  free_tab(tab);
  free(actual);
}

static void	change_pwd(t_tab **data, char **arg)
{
  char	**tab;
  char	path[2000];

  tab = create_setenv_tab("OLDPWD", getcwd(path, 2000));
  my_setenv(tab, data);
  free_tab(tab);
  chdir(arg[1]);
  tab = create_setenv_tab("PWD", getcwd(path, 2000));
  my_setenv(tab, data);
  free_tab(tab);
}

void	my_cd(char **arg, t_tab **data)
{
  int	validity;

  validity = check_cd_errors(arg);
  if (validity == -1)
    {
      (*data)->exit_value = 1;
      return ;
    }
  if (arg[1] == NULL)
    {
      go_home((*data)->my_env);
      return ;
    }
  else if (arg[1][0] == '-')
    {
      go_back(data);
      return ;
    }
  change_pwd(data, arg);
}
