/*
** main.c for test in /home/thibaut/Repository/test
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri Mar 31 19:01:21 2017 Thibaut Trouvé
** Last update Sun Apr  2 03:49:26 2017 Thibaut Trouvé
*/

#include <stdio.h>
#include <unistd.h>

int	write_invert(int fd, int nb)
{
  int	tmp;

  tmp = nb >> 24;
  write(fd, &tmp, 1);
  tmp = nb >> 16;
  write(fd, &tmp, 1);
  tmp = nb >> 8;
  write(fd, &tmp, 1);
  tmp = nb;
  write(fd, &tmp, 1);
  return (0);
}
