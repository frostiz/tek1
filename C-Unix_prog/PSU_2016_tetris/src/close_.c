/*
** close_.c for  in /home/sahel/rendu/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Mar 18 17:07:50 2017 Sahel
** Last update Sat Mar 18 17:12:57 2017 Sahel
*/

#include <unistd.h>

int	close_(int fd, int ret)
{
  if (fd > 2)
    close(fd);
  return (ret);
}
