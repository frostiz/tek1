/*
** start_game.c for Tetris in /home/thibaut/Repository/PSU_2016_tetris
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri Mar 10 16:01:40 2017 
** Last update Sun Mar 19 23:09:24 2017 
*/

#include <curses.h>
#include <time.h>
#include <term.h>
#include <stdlib.h>
#include "main.h"
#include "basic.h"

void	setcolor()
{
  start_color();
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

int	prepare_game(char **final_sequence)
{
  char	*clear;
  char	*smkx;

  *final_sequence = malloc(sizeof(char) * 1 + 1);
  if (*final_sequence == NULL)
    return (84);
  *final_sequence[0] = '\0';
  if ((clear = tigetstr("clear")) == (char *) -1)
    return (84);
  if ((smkx = tigetstr("smkx")) == (char *) -1)
    return (84);
  putstr_(clear, 1);
  putstr_(smkx, 1);
  initscr();
  noecho();
  curs_set(0);
  return (0);
}

char	**create_map(int *map_size)
{
  char	**map;
  int	i;
  int	j;

  i = 0;
  map = malloc(sizeof(char *) * (map_size[0] + 1));
  if (map == NULL)
    return (NULL);
  while (i < map_size[0])
    {
      j = 0;
      map[i] = malloc(sizeof(char) * (map_size[1] + 1));
      if (map[i] == NULL)
	return (NULL);
      while (j < map_size[1])
	{
	  map[i][j] = ' ';
	  j++;
	}
      map[i][j] = '\0';
      i++;
    }
  map[i] = NULL;
  return (map);
}

int	nb_stars(char **map)
{
  int	i;
  int	j;
  int	nb;

  nb = 0;
  i = 0;
  while (map[i] != NULL)
    {
      j = 0;
      while (map[i][j] != '\0')
	{
	  if (map[i][j] != ' ')
	    nb++;
	  j++;
	}
      i++;
    }
  return (nb);
}

int	start_game(t_datamap *game)
{
  char	*final_sequence;
  char	**tab_sequence;

  if (prepare_game(&final_sequence) == 84)
    return (84);
  if ((tab_sequence = get_sequences(game->key)) == NULL)
    return (84);
  if ((game->map = create_map(game->map_size)) == NULL)
    return (84);
  if ((game->map_only_one = create_map(game->map_size)) == NULL)
    return (84);
  mode(0, 0);
  game->stat.high_score = get_high();
  take_next(game);
  srand(time(NULL));
  game->random = rand() % 10;
  put_tetri(game);
  setcolor();
  attron(COLOR_PAIR(7));
  if (game_loop(game, &final_sequence, tab_sequence) == 84)
    return (84);
  mode(1, 0);
  endwin();
  return (0);
}
