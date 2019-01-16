/*
** signal_handler.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Apr  5 22:42:14 2017 Thibaut Trouvé
** Last update Wed Apr 26 16:19:51 2017 thibaut trouve
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"
#include "main.h"

void	sign_handler(int wstatus)
{
  if (wstatus == 11)
    {
      my_putstr("Segmentation fault (core dumped)\n");
      exit(0);
    }
}
