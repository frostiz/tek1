/*
** need_help.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Mar  3 15:52:05 2017 Sahel
** Last update Sun Mar 19 20:04:36 2017 
*/

#include <stdlib.h>
#include "main.h"
#include "basic.h"

static int	is_a_flag(char *f[18], char **av, int av_i)
{
  int		find;
  int		f_i;

  f_i = 0;
  find = 0;
  while (f[f_i] && !find)
    {
      if (match(av[av_i - 1], f[f_i]))
	find = 1;
      f_i++;
    }
  return (find);
}

int	need_help(char **av)
{
  char	*f[18] = {"-l", "--level=*", "-kl", "--key-left=*", "-kr",
		  "--key-right=*", "-kt", "--key-turn=*", "-kd", "--key-drop=*"
		  , "-kq", "--key-quit=*", "-kp", "--key-pause=*",
		  "--map-size=*", "-w", "--without-next", NULL};
  int	find;
  int	av_i;

  av_i = 1;
  while (av[av_i])
    {
      if (match(av[av_i], "--help"))
	{
	  find = is_a_flag(f, av, av_i);
	  if (find == 0)
	    {
	      help(av[0], 0);
	      return (1);
	    }
	}
      av_i++;
    }
  return (0);
}
