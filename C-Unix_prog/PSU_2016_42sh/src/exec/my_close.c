/*
** my_close.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Tue May 16 16:26:44 2017 bastien bedu
** Last update Wed May 17 16:20:03 2017 bastien bedu
*/

#include	<unistd.h>

void		my_close(int fd)
{
  if (fd > 0)
    close(fd);
}
