/*
** epur_back.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Sun May 21 22:58:44 2017 bastien bedu
** Last update Sun May 21 23:24:45 2017 bastien bedu
*/

#include	<stdlib.h>

int		move(char *str, int *i, int mode)
{
  if (mode == 1 && str[*i] != '\0')
    (*i)++;
  if (str[*i] == '`')
    mode = 1;
  else
    mode = 0;
  while (str[*i] != '`' && str[*i] != '\0')
    (*i)++;
  if (mode == 1 && str[*i] != '\0')
    (*i)++;
  return (mode);
}

void		epur_line(char *str)
{
  int		i;

  i = 0;
  while (str != NULL && str[i] != '\0')
    {
      if (str[i] == '\n')
	str[i] = ' ';
      i++;
    }
}
