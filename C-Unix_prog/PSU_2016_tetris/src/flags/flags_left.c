/*
** flags_left.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris/src/flags
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Mon Feb 27 15:24:41 2017 Sahel
** Last update Tue Mar  7 18:03:40 2017 Sahel
*/

#include "main.h"
#include "basic.h"

int	flags_left(char **av, int *ac, t_datamap *game)
{
  char	*str;

  if (match(av[*ac], "-kl"))
    {
      if (!av[*ac + 1])
	return (puterror_("No argument after -kl argument\n", 2));
      game->key.left = strdup_(av[*ac + 1]);
      (*ac)++;
    }
  else
    {
      str = without_before_(av[*ac], '=');
      if (!str)
	return (puterror_("Nothing after --key-left= argument\n", 2));
      game->key.left = str;
    }
  return (0);
}
