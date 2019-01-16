/*
** basics.c for matchstick in /home/thibaut/Repository/CPE_2016_matchstick
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Thu Feb 23 10:26:13 2017 
** Last update Sun Feb 26 15:03:00 2017 
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
  return ;
}

void	print_starline(t_map info)
{
  int	i;

  i = 0;
  while (i < info.line_size)
    {
      my_putchar('*');
      i++;
    }
  my_putchar('\n');
  return ;
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return ;
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	strlen;

  i = 0;
  strlen = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[strlen] = src[i];
      i++;
      strlen++;
    }
  dest[strlen] = '\0';
  return (dest);
}
