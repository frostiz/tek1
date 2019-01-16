/*
** my_putstr.c for my_putstr in /home/H3r3zy/rendu/CPool_Day04
** 
** Made by Lucas Sahel
** Login   <H3r3zy@epitech.net>
** 
** Started on  Thu Oct  6 09:43:44 2016 Lucas Sahel
** Last update Fri Feb 17 08:33:53 2017 Sahel
*/

#include <unistd.h>
#include "basic.h"

void	putstr_(char *str, int fd)
{
  write(fd, str, strlen_(str));
}
