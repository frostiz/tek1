/*
** check_flags.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Mar  3 15:54:10 2017 Sahel
** Last update Sun Mar 19 20:05:44 2017 
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "basic.h"
#include "main.h"

static int	check_flags2(int (*flags[21])(char **, int *, t_datamap *),
			     int *ac_i, char **av, t_datamap *game)
{
  char	*f[20] = {"-l", "--level=*", "-kl", "--key-left=*", "-kr",
		  "--key-right=*", "-kt", "--key-turn=*", "-kd", "--key-drop=*"
		  , "-kq", "--key-quit=*", "-kp", "--key-pause=*",
		  "--map-size=*", "-w", "--without-next", "-d", "--debug",
		  NULL};
  int	f_i;
  int	find;

  f_i = 0;
  find = 0;
  while (f[f_i] && !find)
    {
      if (match(av[*ac_i], f[f_i]))
	{
	  find = 1;
	  if (flags[f_i](av, ac_i, game) == 84)
	    return (84);
	}
      f_i++;
    }
  if (find == 0)
    return (puterror_("1 Argument not found\n", 2));
  return (0);
}

int	check_flags(int ac, char **av, t_datamap *game)
{
  int	(*flags[21])(char **, int *, t_datamap *) =
    {flags_level, flags_level, flags_left, flags_left, flags_right,
     flags_right, flags_turn, flags_turn, flags_drop, flags_drop, flags_quit,
     flags_quit, flags_pause, flags_pause, flags_mapsize, flags_without,
     flags_without, flags_debug, flags_debug};
  int	ac_i;

  if (need_help(av))
    exit(0);
  ac_i = 1;
  while (ac_i < ac)
    {
      if (check_flags2(flags, &ac_i, av, game) == 84)
	return (84);
      ac_i++;
    }
  return (0);
}

static t_flag	which_flag(t_flag flag, char *arg, int *arg_i)
{
  if (match(arg, "--help"))
    flag.help++;
  else if (match(arg, "-d") || match(arg, "--debug") || match(arg, "-w") ||
        match(arg, "--without-next"))
    flag.without++;
  else if ((match(arg, "-l") && (*arg_i)++) || match(arg, "--level=*"))
    flag.level++;
  else if ((match(arg, "-kl") && (*arg_i)++) || match(arg, "--key-left=*"))
    flag.kl++;
  else if ((match(arg, "-kr") && (*arg_i)++) || match(arg, "--key-right=*"))
    flag.kr++;
  else if ((match(arg, "-kt") && (*arg_i)++) || match(arg, "--key-turn=*"))
    flag.kt++;
  else if ((match(arg, "-kd") && (*arg_i)++) || match(arg, "--key-drop=*"))
    flag.kd++;
  else if ((match(arg, "-kq") && (*arg_i)++) || match(arg, "--key-quit=*"))
    flag.kq++;
  else if ((match(arg, "-kp") && (*arg_i)++) || match(arg, "--key-pause=*"))
    flag.kp++;
  else if (match(arg, "--map-size=*"))
    flag.mapsize++;
  else
    flag.validity = 0;
  return (flag);
}

t_flag		check_flags_validity(char **av)
{
  t_flag	flag;
  int		av_i;

  av_i = 1;
  flag = init_flag(flag);
  while (av[av_i])
    {
      flag = which_flag(flag, av[av_i], &av_i);
      if (!av[av_i])
	flag.validity = 0;
      else
	av_i++;
    }
  if (flag.validity == 0 || flag.kt == 2 || flag.kl == 2 || flag.kr == 2 ||
      flag.kp == 2 || flag.kd == 2 || flag.level == 2 || flag.mapsize == 2 ||
      flag.kq == 2)
    flag.validity = 0;
  return (flag);
}
