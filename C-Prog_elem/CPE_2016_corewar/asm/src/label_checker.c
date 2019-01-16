/*
** label_checker.c for label_checker.c in /home/roye_v/delivery/CPE_2016/CPE_2016_corewar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr  2 10:41:35 2017 Vincent Roye
** Last update Sun Apr  2 10:45:11 2017 Vincent Roye
*/

#include "asm.h"

int	check_label_char(char check)
{
  int	i;
  int	ok;

  i = 0;
  ok = 1;
  while (LABEL_CHARS[i] != '\0')
    {
      if (LABEL_CHARS[i] == check)
	ok = 0;
      i++;
    }
  return (ok);
}

int	valid_label(char *tmp)
{
  int	i;

  i = 0;
  while (tmp[i] != '\0')
    {
      if (check_label_char(tmp[i]) == 1)
	return (1);
      i++;
    }
  return (0);
}
