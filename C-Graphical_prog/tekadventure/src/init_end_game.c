/*
** init_end_game.c for init_end_game.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 28 12:46:37 2017 Vincent Roye
** Last update Sun May 28 21:40:10 2017 Vincent Roye
*/

#include	<stdlib.h>
#include	"tekadventure.h"
#include	"cinematic.h"

int		check_piece(t_game *game)
{
  int		i;
  int		piece;

  i = 0;
  piece = 0;
  while (game->inventory.piece_ship[i] < 6)
    {
      if (game->inventory.piece_ship[i] == 1)
	piece++;
      i++;
    }
  return (piece);
}

int		set_env_cinematic(t_end_cine *cine)
{
  cine->scale.x = 0.20;
  cine->scale.y = 0.20;
  cine->ship_pos.x = 300.0;
  cine->ship_pos.y = 370.0;
  cine->ply_pos.x = WIDTH / 2;
  cine->ply_pos.y = 20.0;
  cine->ship = sfSprite_create();
  cine->t_ship =
    sfTexture_createFromFile("pictures/ship/spaceship.png", NULL);
  if (cine->t_ship == NULL)
    return (1);
  sfSprite_setTexture(cine->ship, cine->t_ship, sfTrue);
  sfSprite_setPosition(cine->ship, cine->ship_pos);
  sfSprite_setScale(cine->ship, cine->scale);
  cine->i = 0;
  cine->j = 0;
  return (0);
}
