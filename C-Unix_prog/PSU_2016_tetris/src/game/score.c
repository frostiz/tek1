/*
** score.c for  in /home/sahel/rendu/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 17 15:36:17 2017 Sahel
** Last update Sun Mar 19 23:23:26 2017 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <curses.h>
#include <unistd.h>
#include "basic.h"
#include "main.h"

int	get_high()
{
  int	nb;
  int	fd;
  int	size;

  size = 0;
  fd = open(".score", O_CREAT | O_RDONLY, 00644);
  if (fd == -1)
    {
      clear();
      endwin();
      return (puterror_("Invalid file : .score.\n", 2));
    }
  size = read(fd, &nb, sizeof(int));
  close(fd);
  if (size == 0)
    return (0);
  return (nb);
}

int	stock_score(t_datamap *game)
{
  int	fd;
  int	nb;

  nb = get_high();
  fd = open(".score", O_CREAT | O_WRONLY | O_TRUNC, 00644);
  if (fd == -1)
    {
      clear();
      endwin();
      return (puterror_("Invalid file : .score.\n", 2));
    }
  if (game->stat.score > nb)
    write(fd, &game->stat.score, sizeof(int));
  else
    write(fd, &nb, sizeof(int));
  close(fd);
  return (0);
}

static void	move_down_n_line(char **map, int map_i)
{
  int		map_i_i;

  while (map_i > 0)
    {
      map_i_i = 0;
      while (map_i_i < strlen_(map[map_i]))
	{
	  map[map_i][map_i_i] = map[map_i - 1][map_i_i];
	  map[map_i - 1][map_i_i] = ' ';
	  map_i_i++;
	}
      map_i--;
    }
}

void	score_line(t_datamap *game)
{
  int	map_i;

  map_i = 0;
  while (game->map[map_i])
    {
      if (sp_len_(game->map[map_i], ' ') == strlen_(game->map[map_i]))
	{
	  move_down_n_line(game->map, map_i);
	  game->stat.score += 5;
	  game->stat.line_deleted++;
	  game->cl -= 30000;
	  if (game->stat.line_deleted % 10 == 0)
	    game->level++;
	}
      map_i++;
    }
}
