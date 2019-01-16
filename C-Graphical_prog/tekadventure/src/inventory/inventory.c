/*
** inventory.c for tekadventure in /home/DxCube/delivery/tekadventure
** 
** Made by Victor Dubret
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Fri May 26 19:12:37 2017 Victor Dubret
** Last update Sun May 28 22:00:54 2017 Victor Dubret
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include "tekadventure.h"

static int	incr_(int *i, int j, int limit)
{
  if (j == 5)
    {
      *i += 1;
      j = 0;
    }

  j++;
  if (*i == limit)
    *i = 0;
  return (j);
}

int		draw_without_sword(sfRenderWindow *window,
				   t_inventory inventory,
				   t_game *game, sfVector2f actual_pos)
{
  sfVector2f	coords;
  int		i;
  int		j;

  coords.x = 125;
  coords.y = 60;
  i = 0;
  j = 0;
  while (i < 9 && sfKeyboard_isKeyPressed(sfKeyI) != sfTrue)
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	{
	  sfRenderWindow_close(window);
	  return (0);
	}
      display_map(game, actual_pos);
      draw_objects(window, inventory);
      sfSprite_setPosition(inventory.sprites_character[i], coords);
      sfRenderWindow_drawSprite(window, inventory.sprites_character[i], NULL);
      j = incr_(&i, j, 9);
      sfRenderWindow_display(window);
    }
  while (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue);
  return (0);
}

int		draw_with_sword(sfRenderWindow *window, t_inventory inventory,
				   t_game *game, sfVector2f actual_pos)
{
  sfVector2f	coords;
  int		i;
  int		j;

  coords.x = 125;
  coords.y = 60;
  i = 0;
  j = 0;
  while (i < 6 && sfKeyboard_isKeyPressed(sfKeyI) != sfTrue)
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	{
	  sfRenderWindow_close(window);
	  return (0);
	}
      display_map(game, actual_pos);
      draw_objects(window, inventory);
      sfSprite_setPosition(inventory.sprites_character_s[i], coords);
      sfRenderWindow_drawSprite(window,
				inventory.sprites_character_s[i], NULL);
      j = incr_(&i, j, 6);
      sfRenderWindow_display(window);
    }
  while (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue);
  return (0);
}

int		draw_inventory(sfRenderWindow *window, t_inventory inventory,
			      t_game *game, sfVector2f actual_pos)
{
  if (inventory.sword == 0)
    draw_without_sword(window, inventory, game, actual_pos);
  else
    draw_with_sword(window, inventory, game, actual_pos);
  return (0);
}
