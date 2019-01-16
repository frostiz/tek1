/*
** end_game.c for end_game.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 12:38:26 2017 Vincent Roye
** Last update Sun May 28 22:43:15 2017 Vincent Roye
*/

#include	<SFML/Audio.h>
#include	<SFML/Graphics.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<string.h>
#include	"tekadventure.h"
#include	"cinematic.h"
#include	"my.h"
#include	"dialog.h"

void	horizontal_move(t_end_cine *cine, t_game *game)
{
  while (cine->ply_pos.y < 450.0)
    {
      if (cine->i > 8)
	cine->i = 0;
      sfRenderWindow_clear(game->window, sfBlack);
      sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
      sfRenderWindow_drawSprite(game->window,
				game->character->
				down_walk.sprite[cine->i], NULL);
      sfSprite_setPosition(game->character->down_walk.sprite[cine->i],
			   cine->ply_pos);
      sfRenderWindow_display(game->window);
      cine->ply_pos.y += 0.1;
      if (cine->j > 40)
	{
	  cine->j = 0;
	  cine->i++;
	}
      cine->j++;
    }
}

void	vertical_move(t_end_cine *cine, t_game *game)
{
  while (cine->ply_pos.x > 330.0)
    {
      if (cine->i > 8)
	cine->i = 0;
      sfRenderWindow_clear(game->window, sfBlack);
      sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
      sfRenderWindow_drawSprite(game->window,
				game->character->left_walk.sprite[cine->i],
				NULL);
      sfSprite_setPosition(game->character->left_walk.sprite[cine->i],
			   cine->ply_pos);
      sfRenderWindow_display(game->window);
      cine->ply_pos.x -= 0.1;
      if (cine->j > 40)
	{
	  cine->j = 0;
	  cine->i++;
	}
      cine->j++;
    }
}

int		end_cinematique(t_game *game)
{
  t_end_cine	cine;

  if (set_env_cinematic(&cine) == 1)
    return (1);
  horizontal_move(&cine, game);
  vertical_move(&cine, game);
  sfRenderWindow_drawSprite(game->window,
			    game->character->down_walk.sprite[cine.i],
			    NULL);
  while (cine.ship_pos.y > -200)
    {
      sfRenderWindow_clear(game->window, sfBlack);
      sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
      sfSprite_setPosition(cine.ship, cine.ship_pos);
      sfRenderWindow_drawSprite(game->window, cine.ship, NULL);
      sfRenderWindow_display(game->window);
      cine.ship_pos.y -= 0.20;
    }
  return (0);
}

int		end_game(t_game *game, t_map *graph)
{
  sfVector2f	pos;

  pos.x = 600;
  pos.y = 200;
  init_zone(game, graph, pos);
  if (end_cinematique(game) == 1)
    return (1);
  return (0);
}
