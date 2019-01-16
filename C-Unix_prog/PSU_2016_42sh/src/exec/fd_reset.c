/*
** fd_reset.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
**
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
**
** Started on  Tue May 16 23:11:41 2017 bastien bedu
** Last update Thu May 18 14:24:40 2017 Lucas Dumy
*/

#include	<unistd.h>
#include	"mysh.h"

void		fd_reset(int *fd, int *fd_save, int mode)
{
  if (mode == 0)
    {
      fd_save[0] = fd[0];
      fd_save[1] = fd[1];
    }
  else
    {
      if (fd[0] != fd_save[0] && fd[0] > 0)
	close(fd[0]);
      fd[0] = fd_save[0];
      if (fd[1] != fd_save[1] && fd[1] > 1)
	close(fd[1]);
      fd[1] = fd_save[1];
    }
}
