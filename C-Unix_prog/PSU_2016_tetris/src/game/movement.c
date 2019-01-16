/*
** movement.c for  in /home/sahel/rendu/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 17 13:15:38 2017 Sahel
** Last update Sun Mar 19 20:06:23 2017 
*/

#include "basic.h"
#include "main.h"

void	descendre(char **map)
{
  int	map_i;
  int	map_i_i;

  map_i = tablen_(map) - 1;
  while (map_i > 0)
    {
      map_i_i = 0;
      while (map[map_i][map_i_i])
	{
	  map[map_i][map_i_i] = map[map_i - 1][map_i_i];
	  map[map_i - 1][map_i_i] = ' ';
	  map_i_i++;
	}
      map_i--;
    }
}

void	move_left(t_datamap *game)
{
  int	map_i;
  int	map_i_i;
  char	**map;

  map = game->map_only_one;
  if (colision_left(game) == 0)
    {
      map_i = 0;
      while (map[map_i])
	{
	  map_i_i = 0;
	  while (map[map_i][map_i_i + 1])
	    {
	      map[map_i][map_i_i] = map[map_i][map_i_i + 1];
	      map[map_i][map_i_i + 1] = ' ';
	      map_i_i++;
	    }
	  map_i++;
	}
      game->coord[1]--;
    }
}

void	move_right(t_datamap *game)
{
  int	map_i;
  int	map_i_i;
  char	**map;

  map = game->map_only_one;
  if (colision_right(game) == 0)
    {
      map_i = 0;
      while (map[map_i])
	{
	  map_i_i = strlen_(map[map_i]) - 1;
	  while (map_i_i > 0)
	    {
	      map[map_i][map_i_i] = map[map_i][map_i_i - 1];
	      map[map_i][map_i_i - 1] = ' ';
	      map_i_i--;
	    }
	  map_i++;
	}
      game->coord[1]++;
    }
}

static int	turn_line(t_datamap *game, int len, char **new, int j)
{
  int	i;

  i = len - 1;
  while (i >= 0)
    {
      if ((game->coord[1] + (len - 1) - j < 0 ||
	   game->coord[0] + i >= game->map_size[0] - 1 ||
	   game->coord[1] + j >= game->map_size[1]) ||
	  ((game->coord[0] + (len - 1) - j >= game->map_size[0] - 1||
	    game->coord[1] + i >= game->map_size[1]) &&
	   game->map_only_one[game->coord[0] + i]
	   [game->coord[1] + j] != ' '))
	return (1);
      if (game->map_only_one[game->coord[0] + i]
	  [game->coord[1] + j] != ' ')
	new[game->coord[0] + (len - 1) - j]
	  [game->coord[1] + i] = game->tetriminos->color + 48;
      i--;
    }
  return (0);
}

void	turn(t_datamap *game)
{
  char	**new;
  int	len;
  int	j;

  if (!(new = create_map(game->map_size)))
    return ;
  if (game->tetriminos->width > game->tetriminos->height)
    len = game->tetriminos->width;
  else
    len = game->tetriminos->height;
  j = 0;
  while (game->coord[1] + j < game->coord[1] + len)
    {
      if (turn_line(game, len, new, j))
	return ;
      j++;
    }
  if (colision(game, new) == 0)
    {
      free_tab(game->map_only_one);
      game->map_only_one = new;
    }
  else
    free_tab(new);
}
