/*
** show_game_stats.c for tetris in /home/thibaut/Repository/PSU_2016_tetris/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Mar 19 20:12:45 2017 
** Last update Sun Mar 19 23:09:55 2017 
*/

#include <curses.h>
#include <time.h>
#include "main.h"

static void	format_time(long long int sec, int end_x)
{
  int		hour;
  long long int	min;

  hour = 0;
  min = 0;
  if (sec >= 60)
    {
      min = sec / 60;
      sec = sec % 60;
    }
  if (min >= 60)
    {
      hour = min / 60;
      min = min % 60;
    }
  mvprintw(11, end_x - 18, "Time : %.2d:%.2lli:%.2lli", hour, min, sec);
}

static void	aff_stats_gui(t_datamap *game)
{
  int		start_x;
  int		start_y;
  int		end_x;

  start_x = COLS / 2 - game->map_size[1] / 2 - 25;
  end_x = COLS / 2 - game->map_size[1] / 2 - 5;
  while (start_x < end_x)
    {
      start_y = 3;
      while (start_y < 14)
	{
          move(start_y, start_x);
          if ((start_y == 3 || start_y == 14 - 1) &&
	      ((start_x == end_x - 1) ||
	       (start_x == end_x - 20)))
	    printw("+");
	  else if (start_x == end_x - 20 ||
		   start_x == end_x - 1)
	    printw("|");
	  else if (start_y == 3 || start_y == 14 - 1)
	    printw("-");
	  start_y++;
	}
      start_x++;
    }
}

void		aff_stats(t_datamap *game)
{
  int	end_x;

  end_x = COLS / 2 - game->map_size[1] / 2 - 5;
  aff_stats_gui(game);
  mvprintw(5, end_x - 18, "High score : %d", game->stat.high_score);
  mvprintw(6, end_x - 18, "Score : %d", game->stat.score);
  mvprintw(8, end_x - 18, "Lines : %d", game->stat.line_deleted);
  mvprintw(9, end_x - 18, "Level : %d", game->level);
  if (game->pause != 1)
    game->stat.chrono = clock() / game->stat.cps;
  format_time(game->stat.chrono, end_x);
}
