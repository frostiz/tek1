/*
** check_and_print.c for check_and_print.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 12:51:27 2017 Vincent Roye
** Last update Sun May 28 12:58:00 2017 Vincent Roye
*/

#include	<stdlib.h>
#include	"tekadventure.h"
#include	"my.h"

sfVector2f	get_pos_object(int (*object)[2], int i)
{
  sfVector2f	tmp;

  tmp.x = (float)(object[i][0]);
  tmp.y = (float)(object[i][1]);
  return (tmp);
}

int		check_str(char *str, t_game *game)
{
  int		i;

  i = 0;
  while (game->stock_obj[i] != NULL)
    {
      if (my_strcmp(game->stock_obj[i], str) == 0)
	return (1);
      i++;
    }
  return (0);
}

void		print_object(t_game *game)
{
  int		i;

  i = 0;
  while (i != game->nb_obj)
    {
      if (check_str(game->obj[i]->name, game) != 1)
	sfRenderWindow_drawSprite(game->window,
				  game->obj[i]->sprite, NULL);
      i++;
    }
}

void		print_character(t_game *game)
{
  int		i;

  i = 0;
  while (i != game->nb_char)
    {
      sfRenderWindow_drawSprite(game->window,
				game->charac[i]->sprite, NULL);
      i++;
    }
}
