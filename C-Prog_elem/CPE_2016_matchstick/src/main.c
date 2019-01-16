/*
** test.c for matchstick in /home/thibaut/Repository/CPE_2016_matchstick
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Thu Feb 23 09:59:07 2017 
** Last update Sun Feb 26 14:56:55 2017 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static int	count_actual_nbline(char **map)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  while (map[i] != NULL)
    {
      if (map[i][0] == ' ')
	nb--;
      nb++;
      i++;
    }
  return (nb);
}

static int	matchstick(t_map2 info)
{
  if (info.actual_nbline <= 0 || info.actual_nbline > 100 || info.del_max <= 0)
    return (84);
  aff_map(info);
  while (info.actual_nbline != 0)
    {
      if (my_turn(info) == 1)
	return (0);
      aff_map(info);
      info.actual_nbline = count_actual_nbline(info.map);
      if (info.actual_nbline == 0)
	{
	  my_putstr("You lost, too bad...\n");
	  return (2);
	}
      ai_turn(info);
      aff_map(info);
      info.actual_nbline = count_actual_nbline(info.map);
      if (info.actual_nbline == 0)
	{
	  my_putstr("I lost... snif... but I'll get you next time!!\n");
	  return (1);
	}
    }
  return (0);
}

int	main(int argc, char **argv)
{
  t_map2 info;

  if (argc != 3)
    return (84);
  info.init_nbline = my_getnbr(argv[1]);
  info.actual_nbline = info.init_nbline;
  info.map = create_stickmap(info.actual_nbline);
  info.del_max = my_getnbr(argv[2]);
  return (matchstick(info));
}
