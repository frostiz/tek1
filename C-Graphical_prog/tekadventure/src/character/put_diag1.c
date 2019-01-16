/*
** put_diag1.c for put_diag1.c in /home/roye_v/delivery/tekadventure
**
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
**
** Started on  Sat May 27 15:35:16 2017 Vincent Roye
** Last update Sun May 28 15:30:13 2017 Victor Dubret
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<stdlib.h>
#include	"tekadventure.h"
#include	"my.h"

static void	init_values(t_put_line *line, t_diag *draw)
{
  line->i = 0;
  line->move_click = 0;
  draw->cumul = draw->dx / 2;
  draw->i = 1;
  line->coord.x = draw->x;
  line->coord.y = draw->y;
}

static void	incr_sprite(t_put_line *line, t_diag draw)
{
  if (line->i == 30)
    {
      line->coord.x = draw.x;
      line->coord.y = draw.y;
      line->i = 0;
    }
  (line->i)++;
  line->tmp.x = draw.x;
  line->tmp.y = draw.y;
}

static int	check_left_click(t_put_line *line, t_diag draw,
				 t_game *game, int (*walkzone)[])
{
  while (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
    line->move_click = 1;
  if (line->move_click == 1)
    {
      if (check_valid_coord(walkzone, line->tmp) != 1)
	{
	  line->coord.x = draw.x;
	  line->coord.y = draw.y;
	}
      line->to = sfMouse_getPosition((sfWindow *)game->window);
      return (1);
    }
  return (0);
}

static void	incr_diag(t_diag *draw)
{
  draw->x += draw->x_inclin;
  draw->cumul += draw->dy;
  if (draw->cumul >= draw->dx)
    {
      draw->cumul -= draw->dx;
      draw->y += draw->y_inclin;
    }
}

sfVector2i	my_put_diag1(t_game *game, t_diag draw,
			     sfVector2i from, int (*walkzone)[])
{
  t_put_line	line;

  init_values(&line, &draw);
  while (draw.i <= draw.dx)
    {
      incr_sprite(&line, draw);
      if (check_valid_coord(walkzone, line.tmp) == 1)
	return (line.coord);
      if (check_left_click(&line, draw, game, walkzone) == 1)
	return (move_character(game, line.coord, line.to, walkzone));
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	{
	  line.coord.x = -100;
	  line.coord.y = -100;
	  return (line.coord);
	}
      incr_diag(&draw);
      print_everything(game, draw, from);
      draw.i++;
    }
  line.coord.x = draw.x;
  line.coord.y = draw.y;
  return (line.coord);
}
