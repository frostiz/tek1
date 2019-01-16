/*
** hex_to_int.c for loader in /home/frostiz/repository/tekadventure/bonus/loader
** 
** Made by thibaut trouve
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun May 28 18:17:37 2017 thibaut trouve
** Last update Sun May 28 18:41:06 2017 thibaut trouve
*/

#include <math.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "tekadventure.h"

int	value(char hex)
{
  char	ascii[16] = "0123456789abcdef";
  int	i;

  i = 0;
  while (ascii[i] != hex && ascii[i] != '\0')
    i++;
  return (i);
}

int	hex_to_int(char *hex)
{
  int	i;
  int	mpow;
  int	nb;

  nb = 0;
  mpow = my_strlen(hex) - 1;
  i = 0;
  while (hex[i] != '\0')
    {
      nb += value(hex[i]) * pow(16, mpow);
      mpow--;
      i++;
    }
  return (nb);
}

char	*my_swap(char *str)
{
  char	change;
  int	i;
  int	j;

  j = my_strlen(str) - 1;
  i = 0;
  while (i != (my_strlen(str) / 2))
    {
      change = str[i];
      str[i] = str[j];
      str[j] = change;
      i++;
      j--;
    }
  return (str);
}

char	*my_base(int nb, int base)
{
  char	*result;
  char	*my_ascii;
  int	i;
  int	tmp;

  result = malloc(sizeof(char) * 3);
  if (result == NULL)
    return (NULL);
  my_ascii = "0123456789abcdef";
  result[0] = '0';
  result[1] = '0';
  result[2] = '\0';
  if (nb == 0)
    return (result);
  i = 0;
  while (nb > 0)
    {
      tmp = nb % base;
      result[i] = my_ascii[tmp];
      nb = nb / base;
      i++;
    }
  my_swap(result);
  return (result);
}
