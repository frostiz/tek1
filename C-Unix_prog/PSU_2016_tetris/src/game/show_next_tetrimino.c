/*
** show_next_tetrimino.c for tetris in /home/thibaut/Repository/PSU_2016_tetris/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Mar 19 20:21:50 2017 
** Last update Sun Mar 19 20:48:28 2017 
*/

#include <curses.h>
#include "main.h"

static void	interpret_pos(int start_x, int start_y,
			      int end_y, t_datamap game)
{
  if ((start_y == 3 || start_y == end_y - 1) &&
      ((start_x == COLS / 2 + game.map_size[1] / 2 + 5) ||
       (start_x == COLS / 2 + game.map_size[1] / 2 + 5 +
	game.tetriminos->width + 2 + 2 - 1)))
    printw("+");
  else if (start_x == COLS / 2 + game.map_size[1] / 2 + 5 ||
	   start_x == COLS / 2 + game.map_size[1] / 2 + 5 +
	   game.tetriminos->width + 2 + 2 - 1)
    printw("|");
  else if (start_y == 3 || start_y == end_y - 1)
    printw("-");
}

void		aff_next_tetrimino_gui(t_datamap game)
{
  int		start_x;
  int		start_y;
  int		end_x;
  int		end_y;

  mvprintw(2, COLS / 2 + game.map_size[1] / 2 + 6, "Next");
  start_x = COLS / 2 + game.map_size[1] / 2 + 5;
  end_x = start_x + game.tetriminos->width + 2 + 2;
  start_y = 3;
  end_y = start_y + game.tetriminos->height + 2 + 2;
  while (start_x < end_x)
    {
      start_y = 3;
      while (start_y < end_y)
	{
	  move(start_y, start_x);
	  interpret_pos(start_x, start_y, end_y, game);
	  start_y++;
	}
      start_x++;
    }
}

static void	get_next_tetri(t_datamap *game)
{
  int		i;

  i = 0;
  while (i < game->random)
    {
      game->tetriminos = game->tetriminos->next;
      i++;
    }
}

static void	check_size(t_datamap game, int *j, int *k)
{
  if (game.tetriminos->height == 1)
    (*j)++;
  if (game.tetriminos->width == 1)
    {
      if (game.tetriminos->height != 1)
	*j = -1;
      (*k)++;
    }
}

void		aff_next_tetrimino(t_datamap game)
{
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  k = 0;
  get_next_tetri(&game);
  aff_next_tetrimino_gui(game);
  attron(COLOR_PAIR(game.tetriminos->color));
  check_size(game, &j, &k);
  while (game.tetriminos->tetriminos[i] != NULL)
    {
      mvprintw(4 + game.tetriminos->height / 2 + i + j,
               COLS / 2 + game.map_size[1] / 2 + 6 +
               game.tetriminos->width / 2 + k,
               "%s", game.tetriminos->tetriminos[i]);
      i++;
    }
  attron(COLOR_PAIR(7));
}
