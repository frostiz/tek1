/*
** display_env.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Apr  5 23:17:19 2017 Thibaut Trouvé
** Last update Sun Apr  9 15:31:35 2017 Thibaut Trouvé
*/

#include "my.h"
#include "main.h"

void	display_env(char **args, t_tab **data)
{
  (void)args;
  print_tab((*data)->my_env);
}
