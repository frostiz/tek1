/*
** getenv_.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Thu Mar  2 14:24:13 2017 Sahel
** Last update Thu Mar  2 14:37:37 2017 Sahel
*/

#include <unistd.h>
#include <stdlib.h>
#include "basic.h"
#include "main.h"

char	*getenv_(char **env, char *arg)
{
  int	env_i;

  env_i = 0;
  while (env[env_i])
    {
      if (match(env[env_i], arg))
	return (without_before_(env[env_i], '='));
      env_i++;
    }
  return (NULL);
}
