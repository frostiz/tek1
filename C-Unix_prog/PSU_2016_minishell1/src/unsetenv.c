/*
** unsetenv.c for unsetenv.c in /home/frostiz/PSU_2016_minishell1/src
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Sun Jan 22 23:12:10 2017 thibaut trouve
** Last update Sun Jan 22 23:39:37 2017 thibaut trouve
*/

#include "my.h"

void	del_var_from_env(char **my_env, int pos_var)
{
  while ((my_env)[pos_var] != NULL)
    {
      (my_env)[pos_var] = (my_env)[pos_var + 1];
      pos_var++;
    }
}

void	my_unsetenv(char ***my_env, char **tab)
{
  int  pos_var;
  int   i;

  if (tab[1] == NULL)
    {
      my_printf("unsetenv: Too few arguments.\n");
      return ;
    }
  i = 1;
  while (tab[i] != NULL)
    {
      pos_var = check_env_var(*my_env, tab[i]);
      if (nb_env_var(*my_env) != pos_var)
	del_var_from_env(*my_env, pos_var);
      i++;
    }
}
