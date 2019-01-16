/*
** main.c for main.c in /home/frostiz/PSU_2016_my_sokoban
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Mon Dec 12 11:35:21 2016 thibaut trouve
** Last update Tue Dec 20 09:09:00 2016 thibaut trouve
*/

#include "my.h"

int	*restart(t_maps *maps, int *pos_player)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (maps->map[i] != NULL)
    {
      while (maps->map[i][j] != '\0')
	{
	  if (maps->map[i][j] == 'X' && maps->map_o[i][j] != 'X')
	    maps->map[i][j] = maps->map_o[i][j];
	  if (maps->map[i][j] == 'P' && maps->map_o[i][j] != 'P')
	    maps->map[i][j] = maps->map_o[i][j];
	  if (maps->map_o[i][j] == 'X' && maps->map[i][j] != 'X')
	    maps->map[i][j] = 'X';
	  if (maps->map_o[i][j] == 'P' && maps->map[i][j] != 'P')
	    stock_position_restart(*maps, i, j, pos_player);
	  j++;
	}
      i++;
      j = 0;
    }
  return (pos_player);
}

void	interpret_ch(int ch, t_maps *maps, int *pos_player)
{
  if (ch == KEY_RIGHT)
    move_right(maps->map, pos_player, maps->map_o);
  else if (ch == KEY_LEFT)
    move_left(maps->map, pos_player, maps->map_o);
  else if (ch == KEY_UP)
    move_up(maps->map, pos_player, maps->map_o);
  else if (ch == KEY_DOWN)
    move_down(maps->map, pos_player, maps->map_o);
  else if (ch == ' ')
    pos_player = restart(maps, pos_player);
}

int	main_loop(t_maps maps)
{
  int	ch;
  int	*pos_player;

  pos_player = find_p(maps.map);
  ch = 0;
  if (COLS >= maps.col_max && LINES >= maps.row_max)
    aff_map(maps.map, maps.row_max, maps.col_max);
  if (check_lose(maps.map) == 1)
    return (free_memory(maps.map, 1));
  while (ch != 'q')
    {
      ch = getch();
      clear();
      interpret_ch(ch, &maps, pos_player);
      if (COLS >= maps.col_max && LINES >= maps.row_max)
	aff_map(maps.map, maps.row_max, maps.col_max);
      else
	mvprintw(LINES / 2, COLS / 2 - 9, "Resize your window");
      refresh();
      if (check_win(maps.map, maps.map_o) == 1)
	return (free_memory(maps.map, 0));
      else if (check_lose(maps.map) == 1)
	return (free_memory(maps.map, 1));
    }
  return (0);
}

int	core(char **argv)
{
  t_maps	maps;

  maps.row_max = get_col_and_raw_max(&(maps.col_max), argv);
  maps.map = stock_map(argv, maps.col_max, maps.row_max);
  maps.map_o = stock_map(argv, maps.col_max, maps.row_max);
  if (maps.row_max <= 2 || maps.col_max <= 2 ||
      count_o(maps.map) == 0 || check_nb_o(maps.map) == 1 ||
      check_map(maps.map) == 1)
    {
      my_putstr("Invalid map\n");
      exit(84);
    }
  make_window();
  exit(main_loop(maps));
}

int	main(int argc, char **argv)
{
  if (argc != 2)
    {
      my_putstr("Invalid number of argument !\n");
      exit(84);
    }
  core(argv);
  return (0);
}
