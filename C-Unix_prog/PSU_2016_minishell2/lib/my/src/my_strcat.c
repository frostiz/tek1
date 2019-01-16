/*
** my_strcat.c for my_strcat in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Apr  5 20:58:35 2017 Thibaut Trouvé
** Last update Wed Apr  5 21:03:19 2017 Thibaut Trouvé
*/

#include "my.h"

void	my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = my_strlen(dest);
  j = 0;
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i++;
      j++;
    }
  dest[i] = '\0';
}
