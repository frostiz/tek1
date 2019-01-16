/*
** game_loop.c for tetris in /home/thibaut/Repository/PSU_2016_tetris
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri Mar 10 17:16:31 2017 
** Last update Sun Mar 19 22:25:52 2017 
*/

#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include "main.h"
#include "basic.h"

void	take_next(t_datamap *game)
{
  int	i;

  i = 0;
  while (i < game->random)
    {
      game->tetriminos = game->tetriminos->next;
      i++;
    }
}

void	put_tetri(t_datamap *game)
{
  int	middle;
  int	i;
  int	j;

  i = 0;
  while (game->map_only_one[i])
    {
      j = 0;
      middle = (game->map_size[1] / 2) - game->tetriminos->width / 2;
      game->coord[0] = 0;
      game->coord[1] = (char) middle;
      while (i < tablen_(game->tetriminos->tetriminos) &&
	     game->tetriminos->tetriminos[i][j])
	{
	  if (game->tetriminos->tetriminos[i][j] == '*')
	    game->map_only_one[i][middle + j] = game->tetriminos->color + 48;
	  else
	    game->map_only_one[i][middle + j] = ' ';
	  j++;
	}
      i++;
    }
}

void	fusion(char **map, char **tmp_map)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (tmp_map[i] != NULL)
    {
      j = 0;
      while (tmp_map[i][j] != '\0')
	{
	  if (tmp_map[i][j] != ' ')
	    map[i][j] = tmp_map[i][j];
	  j++;
	}
      i++;
    }
}

int	drop_time(t_datamap *game)
{
  game->time = clock() / game->cl;
  if (colision_bas(game) == 1)
    game->stat.score += 5;
  if (drop_tetrimino(game) == 1)
    {
      show_game(game);
      if (stock_score(game) == 84)
	exit(84);
      sleep(2);
      return (1);
    }
  return (0);
}

int	game_loop(t_datamap *game, char **final_seq, char **tab_seq)
{
  int	exist;

  exist = 0;
  while (exist != 5)
    {
      if (cat_key_pressed(final_seq) == NULL)
	return (84);
      exist = check_sequence_validity(*final_seq, tab_seq);
      interpret_exist(exist, tab_seq, final_seq, game);
      if (game->pause == 0 && (exist == 4 || clock() / game->cl > game->time))
	{
	  if (drop_time(game) == 1)
	    return (0);
	}
      clear();
      show_game(game);
    }
  return (0);
}
