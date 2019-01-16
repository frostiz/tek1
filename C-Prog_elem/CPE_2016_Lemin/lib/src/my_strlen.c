/*
** my_strlen.c for my_strlen.c in /home/roye_v/delivery/PSU_2016/PSU_2016_minishell2
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr  9 17:52:03 2017 Vincent Roye
** Last update Sun Apr  9 18:06:45 2017 Vincent Roye
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
