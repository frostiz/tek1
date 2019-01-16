/*
** mode.c for 42sh in /home/thibaut/Repository/PSU_2016_42sh
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri May 19 12:28:10 2017 Thibaut Trouvé
** Last update Fri May 19 14:12:32 2017 Vincent Roye
*/

#include		<sys/ioctl.h>
#include		<term.h>
#include		"read.h"

int			mode(int i)
{
  struct termios        newT;
  static struct termios oldT;

  if (i == 0)
    {
      ioctl(0, TCGETS, &oldT);
      ioctl(0, TCGETS, &newT);
      newT.c_lflag &= ~ECHO;
      newT.c_lflag &= ~ICANON;
      newT.c_cc[VMIN] = 1;
      newT.c_cc[VTIME] = 1;
      ioctl(0, TCSETS, &newT);
    }
  if (i == 1)
    ioctl(0, TCSETS, &oldT);
  return (0);
}
