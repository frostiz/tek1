/*
** free_struct.c for free_struct.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 02:25:18 2017 Vincent Roye
** Last update Sun May 28 02:28:52 2017 Vincent Roye
*/

#include	<stdlib.h>
#include	"tekadventure.h"

void		free_struct(t_game *game)
{
  int		i;

  i = 0;
  if (game->nb_obj == 0)
    {
      while (i < game->nb_obj)
	{
	  free(game->obj[i]);
	  i++;
	}
      free(game->obj);
    }
  i = 0;
  if (game->nb_char == 0)
    {
      while (i < game->nb_char)
	{
	  free(game->charac[i]);
	  i++;
	}
      free(game->charac);
    }
}
