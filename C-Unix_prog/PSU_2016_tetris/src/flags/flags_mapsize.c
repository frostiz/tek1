/*
** flags_left.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris/src/flags
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 27 15:24:41 2017 Sahel
** Last update Tue Mar 14 19:59:16 2017 Sahel
*/

#include "main.h"
#include "basic.h"

int	flags_mapsize(char **av, int *ac, t_datamap *game)
{
  int	nb1;
  int	nb2;
  char	**tab;
  char	*str;

  str = without_before_(av[*ac], '=');
  if (!str)
    return (puterror_("Nothing after = of the --map-size= flag\n", 2));
  tab = parse_(str, ',');
  if (tablen_(tab) != 2)
    return (puterror_("The PRGM need 2 nbr like 20,10 after map-size\n", 2));
  nb2 = getnbr_(tab[0]);
  nb1 = getnbr_(tab[1]);
  if (nb1 <= 0 || nb2 <= 0)
    return (puterror_("Size of map can't be <= 0", 2));
  game->map_size[0] = nb2;
  game->map_size[1] = nb1;
  return (0);
}
