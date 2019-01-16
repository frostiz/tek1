/*
** int_to_string.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor/src
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Sat May 27 02:59:29 2017 Antoine Duez
** Last update Sat May 27 16:08:33 2017 Antoine Duez
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

char		*put_neg(char *str)
{
  int		len;
  char		*tmp;

  tmp = malloc(sizeof(char) * (my_strlen(str) + 2));
  if (tmp == NULL)
    return (NULL);
  len = my_strlen(str);
  while (len > 0)
    {
      tmp[len] = str[len - 1];
      len--;
    }
  tmp[0] = '-';
  tmp[my_strlen(str)] = '\0';
  free(str);
  return (tmp);
}

static void	init_values(int *len, int *negative, int *nb, int *tmp)
{
  *len = 0;
  *negative = 0;
  if (*nb < 0)
    {
      *negative = 1;
      *nb *= -1;
    }
  *tmp = *nb;
  while (*tmp > 0)
    {
      *tmp /= 10;
      (*len)++;
    }
}

char		*int_to_string(int nb)
{
  int		len;
  char		*str;
  int		tmp;
  int		negative;

  if (nb == 0)
    {
      str = malloc(sizeof(char) * 2);
      str[0] = '0';
      str[1] = '\0';
      return (str);
    }
  init_values(&len, &negative, &nb, &tmp);
  str = malloc(sizeof(char) * (len + 2));
  if (str == NULL)
    return (NULL);
  str[len] = '\0';
  while (len--)
    {
      str[len] = nb % 10 + '0';
      nb /= 10;
    }
  if (negative == 1)
    str = put_neg(str);
  return (str);
}
