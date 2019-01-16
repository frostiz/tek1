/*
** my_strcpy.c for my_strcpy in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Apr  5 20:57:03 2017 Thibaut Trouvé
** Last update Wed Apr  5 21:00:23 2017 Thibaut Trouvé
*/

#include "my.h"

void	my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
}
