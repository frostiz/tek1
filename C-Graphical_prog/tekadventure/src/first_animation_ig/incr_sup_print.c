/*
** incr_sup_print.c for tekadventure in /home/DxCube/delivery/tekadventure
** 
** Made by Victor Dubret
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sun May 28 16:34:24 2017 Victor Dubret
** Last update Sun May 28 19:15:17 2017 Victor Dubret
*/

#include		"tekadventure.h"

static void		disp_in_move(t_game *game, sfVector2i from,
				     int i, sfSprite **sprites)
{
  sfVector2f		tmp;

  tmp = init_float_vector(from.x, from.y);
  sfRenderWindow_clear(game->window, sfBlack);
  sfSprite_setPosition (sprites[i], tmp);
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  sfRenderWindow_drawSprite(game->window, sprites[i], NULL);
  print_object(game);
  print_character(game);
  sfRenderWindow_display(game->window);
}

sfVector2i	abs_inf(t_game *game, sfVector2i from, sfVector2i to)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (from.x < to.x)
    {
      disp_in_move(game, from, i, game->character->right_walk.sprite);
      if (j == 5)
	{
	  i++;
	  j = 0;
	}
      from.x++;
      j++;
      if (i == 8)
	i = 0;
    }
  return (from);
}

sfVector2i	abs_sup(t_game *game, sfVector2i from, sfVector2i to)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (from.x > to.x)
    {
      disp_in_move(game, from, i, game->character->left_walk.sprite);
      if (j == 5)
	{
	  i++;
	  j = 0;
	}
      from.x--;
      j++;
      if (i == 8)
	i = 0;
    }
  return (from);
}

sfVector2i	ord_inf(t_game *game, sfVector2i from, sfVector2i to)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (from.y < to.y)
    {
      disp_in_move(game, from, i, game->character->down_walk.sprite);
      if (j == 5)
	{
	  i++;
	  j = 0;
	}
      from.y++;
      j++;
      if (i == 8)
	i = 0;
    }
  return (from);
}

sfVector2i	ord_sup(t_game *game, sfVector2i from, sfVector2i to)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (from.y > to.y)
    {
      disp_in_move(game, from, i, game->character->up_walk.sprite);
      if (j == 5)
	{
	  i++;
	  j = 0;
	}
      from.y--;
      j++;
      if (i == 8)
	i = 0;
    }
  return (from);
}
