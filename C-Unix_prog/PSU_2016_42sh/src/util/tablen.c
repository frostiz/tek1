/*
** tablen.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Sat May 20 17:54:45 2017 bastien bedu
** Last update Sat May 20 17:55:51 2017 bastien bedu
*/

#include	<stdlib.h>

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    i++;
  return (i);
}
