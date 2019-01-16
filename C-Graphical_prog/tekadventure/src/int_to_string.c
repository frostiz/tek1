/*
** int_to_string.c for int_to_string.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Thu May  4 20:36:45 2017 Vincent Roye
** Last update Sun May 28 12:31:45 2017 Victor Dubret
*/

#include	<stdlib.h>
#include	"tekadventure.h"
#include	"my.h"

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

static void	init_values(int *len, int *negative,
			    int *nb, int *tmp)
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
