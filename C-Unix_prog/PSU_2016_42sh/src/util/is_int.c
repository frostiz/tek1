/*
** is_int.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Sat May 20 18:14:40 2017 bastien bedu
** Last update Sat May 20 18:21:37 2017 bastien bedu
*/

#include	<stdlib.h>

int		is_int(char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    i++;
  if (str[i] == '\0')
    return (0);
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  if (str[i] == '\0')
    return (1);
  return (0);
}
