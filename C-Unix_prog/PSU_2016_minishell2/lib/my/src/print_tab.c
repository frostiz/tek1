/*
** print_tab.c for print_tab.c$ in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Mon Apr  3 22:12:18 2017 Thibaut Trouvé
** Last update Fri Apr  7 17:13:32 2017 Thibaut Trouvé
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	print_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      write(1, "\n", 1);
      i++;
    }
}
