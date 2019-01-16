/*
** my_puterror.c for tekadventure in /home/thibaut/Repository/scroller
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Thu May  4 17:11:43 2017 Thibaut Trouvé
** Last update Thu May  4 17:12:28 2017 Thibaut Trouvé
*/

#include <unistd.h>
#include "tekadventure.h"

void	my_puterror(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i++;
    }
}
