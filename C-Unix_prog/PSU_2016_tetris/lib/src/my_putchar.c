/*
** my_putchar.c for Lib in /home/H3r3zy/rendu/CPool_Day07/lib/my
** 
** Made by Lucas Sahel
** Login   <H3r3zy@epitech.net>
** 
** Started on  Tue Oct 11 11:31:28 2016 Lucas Sahel
** Last update Fri Feb 17 08:34:09 2017 Sahel
*/

#include <unistd.h>

void	putchar_(char c)
{
  write(1, &c, 1);
}
