/*
** flags_left.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris/src/flags
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 27 15:24:41 2017 Sahel
** Last update Sun Mar 19 20:53:38 2017 
*/

#include "main.h"
#include "basic.h"

int	flags_drop(char **av, int *ac, t_datamap *game)
{
  char	*str;

  if (match(av[*ac], "-kd"))
    {
      if (!av[*ac + 1])
	return (puterror_("No argument after -kd argument\n", 2));
      game->key.drop = strdup_(av[*ac + 1]);
      (*ac)++;
    }
  else
    {
      str = without_before_(av[*ac], '=');
      if (!str)
	return (puterror_("Nothing after --key-drop= argument\n", 2));
      game->key.drop = str;
    }
  return (0);
}
