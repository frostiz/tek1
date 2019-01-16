/*
** my_exit.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Apr  5 23:40:38 2017 Thibaut Trouvé
** Last update Sun Apr  9 15:56:49 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"
#include "main.h"

void	my_exit(char **args, t_tab **data)
{
  (void)args;
  (void)data;
  exit(my_getnbr(args[1]));
}
