/*
** ia_info.c for matchstick in /home/thibaut/Repository/CPE_2016_matchstick
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Feb 26 14:52:27 2017 
** Last update Sun Feb 26 15:00:30 2017 
*/

#include "my.h"

int	find_longest_line(char **map)
{
  int	i;
  int	max;
  int	pos;

  i = 0;
  max = 0;
  while (map[i] != NULL)
    {
      if (next_space(map[i]) > max)
	{
	  max = next_space(map[i]);
	  pos = i;
	}
      i++;
    }
  return (pos + 1);
}

int	find_sup_del_max(char **map, int nb_del_max)
{
  int	i;
  int	max;
  int	pos;

  i = 0;
  max = 0;
  pos = -1;
  while (map[i] != NULL)
    {
      if (next_space(map[i]) > max && next_space(map[i]) > nb_del_max)
	{
	  max = next_space(map[i]);
	  pos = i;
	}
      i++;
    }
  return (pos + 1);
}

int	is_sup_del_max(char **map, int del_max)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    {
      if (next_space(map[i]) > del_max)
	{
	  return (1);
	}
      i++;
    }
  return (0);
}

int	next_space(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != ' ')
    {
      i++;
    }
  return (i);
}
