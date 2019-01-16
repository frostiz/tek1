/*
** main.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 27 14:31:57 2017 Sahel
** Last update Sun Mar 19 22:12:15 2017 
*/

#include <stdio.h>
#include <sys/ioctl.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include "basic.h"

int			mode(int i, int time)
{
  struct termios	newT;
  static struct termios	oldT;

  if (i == 0)
    {
      ioctl(0, TCGETS, &oldT);
      ioctl(0, TCGETS, &newT);
      newT.c_lflag &= ~ECHO;
      newT.c_lflag &= ~ICANON;
      newT.c_cc[VMIN] = 0;
      newT.c_cc[VTIME] = time;
      ioctl(0, TCSETS, &newT);
    }
  if (i == 1)
    ioctl(0, TCSETS, &oldT);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_datamap	*game;
  t_flag	flag;

  game = init_game(env);
  if (!game)
    return (puterror_("Term in env not found", 1));
  flag = check_flags_validity(av);
  if (flag.validity == 0 && flag.help == 0)
    return (puterror_("Flag not valid\n", 1));
  if (check_flags(ac, av, game) == 84)
    return (84);
  if (game->debug == 1)
    debug(game);
  if (get_tetrimino(game) == 84 || !game->tetriminos)
    return (84);
  if (game->debug == 1)
    {
      mode(0, 255);
      putstr_("Press any key to start Tetris\n", 1);
      read(0, NULL, 1);
      mode(1, 0);
    }
  if (start_game(game) == 84)
    return (84);
  return (0);
}
