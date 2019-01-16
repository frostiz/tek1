/*
** colision.c for  in /home/sahel/rendu/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 17 13:05:10 2017 Sahel
** Last update Sat Mar 18 16:42:36 2017 Sahel
*/

#include <time.h>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include "basic.h"
#include "main.h"

int	colision_bas(t_datamap *game)
{
  int	map_i;
  int	map_i_i;

  map_i = 0;
  while (game->map[map_i])
    {
      map_i_i = 0;
      while (game->map[map_i][map_i_i])
	{
	  if (game->map[map_i + 1] && game->map[map_i + 1][map_i_i] != ' ' &&
	      game->map_only_one[map_i][map_i_i] != ' ')
	    return (1);
	  if (map_i == game->map_size[0] - 1 &&
	      game->map_only_one[map_i][map_i_i] != ' ')
	    return (1);
	  map_i_i++;
	}
      map_i++;
    }
  return (0);
}

int	colision_left(t_datamap *game)
{
  int	map_i;
  int	map_i_i;

  map_i = 0;
  while (game->map[map_i])
    {
      map_i_i = 0;
      while (game->map[map_i][map_i_i])
	{
	  if (map_i_i > 0 && game->map[map_i][map_i_i - 1] != ' ' &&
	      game->map_only_one[map_i][map_i_i] != ' ')
	    return (1);
	  if (map_i_i == 0 && game->map_only_one[map_i][map_i_i] != ' ')
	    return (1);
	  map_i_i++;
	}
      map_i++;
    }
  return (0);
}

int	colision_right(t_datamap *game)
{
  int	map_i;
  int	map_i_i;

  map_i = 0;
  while (game->map[map_i])
    {
      map_i_i = 0;
      while (game->map[map_i][map_i_i])
	{
	  if (game->map[map_i][map_i_i + 1] &&
	      game->map[map_i][map_i_i + 1] != ' ' &&
	      game->map_only_one[map_i][map_i_i] != ' ')
	    return (1);
	  if (map_i_i == game->map_size[1] - 1 &&
	      game->map_only_one[map_i][map_i_i] != ' ')
	    return (1);
	  map_i_i++;
	}
      map_i++;
    }
  return (0);
}

int	colision(t_datamap *game, char **new)
{
  int	map_i;
  int	map_i_i;

  map_i = 0;
  while (game->map[map_i])
    {
      map_i_i = 0;
      while (game->map[map_i][map_i_i])
	{
	  if (game->map[map_i][map_i_i] != ' ' &&
	      new[map_i][map_i_i] != ' ')
	    return (1);
	  map_i_i++;
	}
      map_i++;
    }
  return (0);
}

int	drop_tetrimino(t_datamap *game)
{
  if (colision_bas(game) == 1)
    {
      if (game->tetriminos->next != NULL)
	{
	  fusion(game->map, game->map_only_one);
	  score_line(game);
	  take_next(game);
	  clear();
	  free_tab(game->map_only_one);
	  srand(time(NULL));
	  game->random = rand() % 10;
	  aff_next_tetrimino(*game);
	  game->map_only_one = create_map(game->map_size);
	  put_tetri(game);
	  if (colision_bas(game) == 1)
	    return (1);
	}
    }
  else
    {
      descendre(game->map_only_one);
      game->coord[0]++;
    }
  return (0);
}
