/*
** add_var.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Sat May 20 12:32:05 2017 bastien bedu
** Last update Sat May 20 12:55:37 2017 bastien bedu
*/

#include	"env.h"

int		add_var(char *str_to_add, char *str_to, char *str, int *i)
{
  int		j;

  (*i)++;
  while (is_char_alphanum(str[*i]) == 1)
    (*i)++;
  j = 0;
  while (str_to_add[j] != '\0')
    {
      str_to[j] = str_to_add[j];
      j++;
    }
  return (j);
}
