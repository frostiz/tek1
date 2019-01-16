/*
** check_env.c for tekadventure in /home/thibaut/Repository/tekadventure
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Thu May  4 17:09:16 2017 Thibaut Trouvé
** Last update Mon May 22 21:11:26 2017 Vincent Roye
*/

#include	<stdlib.h>
#include	"tekadventure.h"
#include	"my.h"

int		check_env(char **env)
{
  int		i;

  if (env == NULL)
    {
      my_puterror("Environnement not found.\n");
      return (-1);
    }
  i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp("DISPLAY=", env[i], 7) == 0)
	return (0);
      i++;
    }
  my_puterror("Missing DISPLAY environnement variable\n");
  return (-1);
}
