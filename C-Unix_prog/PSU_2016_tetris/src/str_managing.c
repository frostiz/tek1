/*
** str_managing.c for  in /home/sahel/rendu/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Mar 18 16:22:13 2017 Sahel
** Last update Sat Mar 18 16:44:18 2017 Sahel
*/

#include "basic.h"
#include "main.h"

void	without_last_char(char *str, char c)
{
  int	str_i;

  str_i = strlen_(str) - 1;
  while (str_i >= 0 && str[str_i] == c)
    str_i--;
  if (str_i != strlen_(str) - 1)
    str[str_i + 1] = '\0';
}

int	line_starspace(char *str)
{
  int	str_i;

  str_i = 0;
  while (str[str_i])
    {
      if (str[str_i] != ' ' && str[str_i] != '*')
	return (84);
      str_i++;
    }
  return (0);
}

char	*take_name(char *str)
{
  char	*name;
  int	name_i;

  if (sp_len_(str, '/') != strlen_(str))
    name = strdup_(&str[sp_len_(str, '/') + 1]);
  else
    name = strdup_(str);
  name_i = strlen_(name) - 1;
  while (name_i > 0 && name[name_i + 1] != '.')
    name_i--;
  if (name[name_i] == '.')
    name[0] = '\0';
  else
    name[name_i + 1] = '\0';
  return (name);
}
