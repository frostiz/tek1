/*
** flags_level.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris/src/flags
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 27 14:50:51 2017 Sahel
** Last update Sat Mar 18 17:28:50 2017 Sahel
*/

#include <unistd.h>
#include "basic.h"
#include "main.h"

int	flags_level(char **av, int *av_i, t_datamap *game)
{
  char	*str;

  if (match(av[*av_i], "-l"))
    {
      if (av[*av_i + 1] && getnbr_(av[*av_i + 1]) > 0)
	{
	  game->level = getnbr_(av[*av_i + 1]);
	  (*av_i)++;
	  return (0);
	}
    }
  else
    {
      str = without_before_(av[*av_i], '=');
      if (!str || getnbr_(str) <= 0)
	return (puterror_("Bad argument after the = of --level=", 2 ));
      game->level = getnbr_(av[*av_i]);
      return (0);
    }
  return (puterror_("Bad Argument after -l argument\n", 2));
}
