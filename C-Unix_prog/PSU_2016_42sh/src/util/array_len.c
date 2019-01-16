/*
** array_len.c for array_len.c in /home/roye_v/delivery/PSU_2016_42sh
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 21 12:59:24 2017 Vincent Roye
** Last update Sun May 21 13:01:35 2017 Vincent Roye
*/

#include	<stdlib.h>
#include	"exec.h"

int		array_len(char **stock)
{
  int		i;

  i = 0;
  while (stock[i] != NULL)
    i++;
  return (i);
}
