/*
** show_game.c for tetris in /home/thibaut/Repository/PSU_2016_tetris
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri Mar 10 17:23:15 2017 
** Last update Sun Mar 19 22:10:01 2017 
*/

#include <unistd.h>
#include <curses.h>
#include <time.h>
#include "main.h"

void	aff_interface(t_datamap *map)
{
  int	i;
  int	j;

  j = -1;
  while (j < map->map_size[0] + 1)
    {
      i = -1;
      while (i < map->map_size[1] + 1)
	{
	  move(j + 1, (COLS / 2) - (map->map_size[1] / 2) + i);
	  if ((j == -1 || j == map->map_size[0]) &&
	      (i == -1 ||
	       i == map->map_size[1]))
	    printw("+");
	  else if (j == -1 || j == map->map_size[0])
	    printw("-");
	  else if (i == -1 || i == map->map_size[1])
	    printw("|");
	  i++;
	}
      j++;
    }
}

static void	print_char_1(t_datamap *game, int i, int j)
{
  char		c;

  c = game->map[i][j];
  if (c != ' ')
    {
      c -= 48;
      attron(COLOR_PAIR(c));
      mvprintw(i + 1, COLS / 2 - game->map_size[1] / 2 + j, CHAR);
      attron(COLOR_PAIR(7));
    }
  else
    mvprintw(i + 1, COLS / 2 - game->map_size[1] / 2 + j, " ");
}

static void	print_char_2(t_datamap *game, int i, int j)
{
  char		c;

  c = game->map_only_one[i][j];
  if (c != ' ')
    {
      c -= 48;
      attron(COLOR_PAIR(c));
      mvprintw(i + 1, COLS / 2 - game->map_size[1] / 2 + j, CHAR);
      attron(COLOR_PAIR(c));
    }
}

void	aff_map(t_datamap *game)
{
  int	i;
  int	j;

  i = 0;
  while (game->map[i] != NULL)
    {
      j = 0;
      while (game->map[i][j])
	print_char_1(game, i, j++);
      i++;
    }
  i = 0;
  while (game->map_only_one[i])
    {
      j = 0;
      attron(COLOR_PAIR(game->tetriminos->color));
      while (game->map_only_one[i][j])
	print_char_2(game, i, j++);
      i++;
    }
  attron(COLOR_PAIR(7));
}

void	show_game(t_datamap *game)
{
  aff_interface(game);
  aff_stats(game);
  aff_next_tetrimino(*game);
  aff_map(game);
  refresh();
}
