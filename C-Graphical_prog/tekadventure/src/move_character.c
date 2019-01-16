/*
** move_character.c for move_character.c in /home/roye_v/delivery/tekadventure
**
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
**
** Started on  Fri May 26 03:01:23 2017 Vincent Roye
** Last update Sun May 28 03:13:47 2017 Antoine Duez
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<stdlib.h>
#include	"tekadventure.h"

int		check_valid_coord(int (*walkzone)[2],
				  sfVector2f coord)
{
  int		rect;
  int		good_pos;

  good_pos = 1;
  rect = 1;
  while (rect <= (walkzone[0][0]))
    {
      if ((int)coord.x > walkzone[rect][0] &&
	  (int)coord.x < walkzone[rect + 1][0] &&
	  (int)coord.y > walkzone[rect][1] &&
	  (int)coord.y < walkzone[rect + 1][1])
	good_pos = 0;
      rect += 2;
    }
  return (good_pos);
}

sfVector2f	int_to_float(sfVector2i convert)
{
  sfVector2f	to_convert;

  to_convert.x = (float)convert.x;
  to_convert.y = (float)convert.y;
  return (to_convert);
}

sfVector2i	my_put_diag(t_game *game, sfVector2i from,
			    sfVector2i to, int (*walkzone)[])
{
  t_diag	draw;

  draw.x = from.x;
  draw.y = from.y;
  draw.dx = to.x - from.x;
  draw.dy = to.y - from.y;
  draw.x_inclin = (draw.dx > 0) ? 1 : -1;
  draw.y_inclin = (draw.dy > 0) ? 1 : -1;
  draw.dx = abs(draw.dx);
  draw.dy = abs(draw.dy);
  if (draw.dx > draw.dy)
    return (my_put_diag1(game, draw, from, walkzone));
  else
    return (my_put_diag2(game, draw, from, walkzone));
}

sfVector2i	move_character(t_game *game, sfVector2i from,
			       sfVector2i to, int (*walkzone)[])
{
  if (to.x == from.x)
    to.x++;
  if (to.y == from.y)
    to.y++;
  return (my_put_diag(game, from, to, walkzone));
}
