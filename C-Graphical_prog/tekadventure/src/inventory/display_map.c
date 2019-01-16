/*
** display_map.c for tekadventure in /home/DxCube/delivery/tekadventure
** 
** Made by Victor Dubret
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sun May 28 18:27:16 2017 Victor Dubret
** Last update Mon May 29 09:42:17 2017 Victor Dubret
*/

#include	"tekadventure.h"

static	void	draw_piece_ship(t_inventory inventory,
				sfVector2f coords, sfRenderWindow *window)
{
  int		i;

  i = 0;
  while (i < 6)
    {
      if (inventory.piece_ship[i] == 1)
	{
	  sfSprite_setPosition(inventory.sprites[i + 3], coords);
	  sfRenderWindow_drawSprite(window, inventory.sprites[i + 3], NULL);
	  if (coords.x == 315)
	    {
	      coords.x = 45;
	      coords.y = 390;
	    }
	  else
	    coords.x += 90;
	}
      i++;
    }
}

void		display_map(t_game *game, sfVector2f actual_pos)
{
  sfRenderWindow_clear(game->window, sfBlack);
  sfSprite_setPosition (game->character->down_walk.sprite[0], actual_pos);
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->down_walk.sprite[0], NULL);
  print_object(game);
  print_character(game);
}

void		draw_objects(sfRenderWindow *window, t_inventory inventory)
{
  sfVector2f    coords;

  coords.x = 45;
  coords.y = 290;
  sfRenderWindow_drawSprite(window, inventory.sprites[0], NULL);
  if (inventory.gold_key == 1)
    {
      sfSprite_setPosition(inventory.sprites[1], coords);
      sfRenderWindow_drawSprite(window, inventory.sprites[1], NULL);
      coords.x += 90;
    }
  draw_piece_ship(inventory, coords, window);
  if (inventory.sword == 1)
    {
      coords.x = 380;
      coords.y = 70;
      sfSprite_setPosition(inventory.sprites[2], coords);
      sfRenderWindow_drawSprite(window, inventory.sprites[2], NULL);
    }
}
