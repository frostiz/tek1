/*
** print_direction.c for print_direction.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sat May 27 15:01:16 2017 Vincent Roye
** Last update Sun May 28 02:17:31 2017 Vincent Roye
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<stdlib.h>
#include	"tekadventure.h"

void		print_left(t_game *game, int i, sfVector2f coord)
{
  sfRenderWindow_clear(game->window, sfBlack);
  sfSprite_setPosition (game->character->left_walk.sprite[i], coord);
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->left_walk.sprite[i], NULL);
  print_object(game);
  print_character(game);
  sfRenderWindow_display(game->window);
}

void		print_right(t_game *game, int i, sfVector2f coord)
{
  sfRenderWindow_clear(game->window, sfBlack);
  sfSprite_setPosition (game->character->right_walk.sprite[i], coord);
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->right_walk.sprite[i], NULL);
  print_object(game);
  print_character(game);
  sfRenderWindow_display(game->window);
}

void		print_up(t_game *game, int i, sfVector2f coord)
{
  sfRenderWindow_clear(game->window, sfBlack);
  sfSprite_setPosition (game->character->up_walk.sprite[i], coord);
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->up_walk.sprite[i], NULL);
  print_object(game);
  print_character(game);
  sfRenderWindow_display(game->window);
}

void		print_down(t_game *game, int i, sfVector2f coord)
{
  sfRenderWindow_clear(game->window, sfBlack);
  sfSprite_setPosition (game->character->down_walk.sprite[i], coord);
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->down_walk.sprite[i], NULL);
  print_object(game);
  print_character(game);
  sfRenderWindow_display(game->window);
}
