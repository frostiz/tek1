/*
** parallax_move.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/src/character
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Sun May 28 02:34:38 2017 Antoine Duez
** Last update Sun May 28 15:55:16 2017 Vincent Roye
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<stdlib.h>
#include	"tekadventure.h"
#include	"my.h"

static void	move_away(t_game *game, t_diag draw, int i, sfVector2f scale)
{
  if (draw.y_inclin == -1 && scale.x > 2.4 && scale.y > 2.4
      && game->same_bg == 0)
    {
      while (i < 9)
        {
          scale = sfSprite_getScale(game->character->right_walk.sprite[i]);
          scale.x -= 0.005;
          scale.y -= 0.005;
          sfSprite_setScale(game->character->right_walk.sprite[i], scale);
          scale = sfSprite_getScale(game->character->up_walk.sprite[i]);
          scale.x -= 0.005;
          scale.y -= 0.005;
          sfSprite_setScale(game->character->up_walk.sprite[i], scale);
          scale = sfSprite_getScale(game->character->left_walk.sprite[i]);
          scale.x -= 0.005;
          scale.y -= 0.005;
          sfSprite_setScale(game->character->left_walk.sprite[i], scale);
          scale = sfSprite_getScale(game->character->down_walk.sprite[i]);
          scale.x -= 0.005;
          scale.y -= 0.005;
          sfSprite_setScale(game->character->down_walk.sprite[i], scale);
          i++;
        }
    }
}

static void	move_to(t_game *game, t_diag draw, int i, sfVector2f scale)
{
  if (draw.y_inclin == 1 && scale.x < 3.0 && scale.y < 3.0
      && game->same_bg == 0)
    {
      while (i < 9)
        {
          scale = sfSprite_getScale(game->character->right_walk.sprite[i]);
          scale.x += 0.005;
          scale.y += 0.005;
          sfSprite_setScale(game->character->right_walk.sprite[i], scale);
          scale = sfSprite_getScale(game->character->up_walk.sprite[i]);
          scale.x += 0.005;
          scale.y += 0.005;
          sfSprite_setScale(game->character->up_walk.sprite[i], scale);
          scale = sfSprite_getScale(game->character->left_walk.sprite[i]);
          scale.x += 0.005;
          scale.y += 0.005;
          sfSprite_setScale(game->character->left_walk.sprite[i], scale);
          scale = sfSprite_getScale(game->character->down_walk.sprite[i]);
          scale.x += 0.005;
          scale.y += 0.005;
          sfSprite_setScale(game->character->down_walk.sprite[i], scale);
          i++;
        }
    }
}

static void	no_parallax(t_game *game, int i, sfVector2f scale)
{
  while (i < 9)
    {
      scale.x = 1.0;
      scale.y = 1.0;
      sfSprite_setScale(game->character->right_walk.sprite[i], scale);
      sfSprite_setScale(game->character->up_walk.sprite[i], scale);
      sfSprite_setScale(game->character->left_walk.sprite[i], scale);
      sfSprite_setScale(game->character->down_walk.sprite[i], scale);
      i++;
    }
}

static void	set_parallax(t_game *game, int i, sfVector2f scale)
{
  if (game->same_bg == 1)
    {
      scale.x = 3.0;
      scale.y = 3.0;
      while (i < 9)
	{
	  sfSprite_setScale(game->character->right_walk.sprite[i], scale);
	  sfSprite_setScale(game->character->up_walk.sprite[i], scale);
	  sfSprite_setScale(game->character->left_walk.sprite[i], scale);
	  sfSprite_setScale(game->character->down_walk.sprite[i], scale);
	  i++;
	}
      game->same_bg = 0;
    }
}

void		make_this_parallax(t_game *game, t_diag draw)
{
  sfVector2f	scale;
  int		i;

  i = 0;
  if (my_strcmp(game->background, "pictures/map/house.jpg") == 0)
    {
      scale = sfSprite_getScale(game->character->right_walk.sprite[0]);
      set_parallax(game, i, scale);
      move_away(game, draw, i, scale);
      move_to(game, draw, i, scale);
    }
  else
    no_parallax(game, i, scale);
}
