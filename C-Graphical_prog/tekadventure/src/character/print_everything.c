/*
** print_everything.c for print_everything.c in /home/roye_v/delivery/tekadventure
**
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
**
** Started on  Sat May 27 15:06:21 2017 Vincent Roye
** Last update Sun May 28 03:15:54 2017 Antoine Duez
*/

#include		<SFML/Graphics/RenderWindow.h>
#include		<SFML/Graphics/Texture.h>
#include		<SFML/Graphics/Sprite.h>
#include		<stdlib.h>
#include		"tekadventure.h"

static void		check_direction(t_move_player *move,
					sfVector2i from, t_diag draw)
{
  move->coord.x = draw.x;
  move->coord.y = draw.y;
  move->max = 4;
  if (move->coord.x < from.x)
    {
      move->col = from.x - move->coord.x;
      move->max = 1;
    }
  else if (move->coord.x >= from.x)
    {
      move->col = move->coord.x - from.x;
      move->max = 2;
    }
  if (move->coord.y < from.y)
    {
      move->tmp = from.y - move->coord.y;
      if (move->tmp > move->col)
	move->max = 3;
    }
  else if (move->coord.y >= from.y)
    {
      move->tmp = move->coord.y - from.y;
      if (move->tmp > move->col)
	move->max = 4;
    }
}

static void		which_direction(t_move_player move,
					t_game *game, int i)
{
  if (move.max == 1)
    {
      print_left(game, i, move.coord);
      game->character->last_pos = LEFT;
    }
  else if (move.max == 2)
    {
      game->character->last_pos = RIGHT;
      print_right(game, i, move.coord);
    }
  else if (move.max == 3)
    {
      game->character->last_pos = UP;
      print_up(game, i, move.coord);
    }
  else if (move.max == 4)
    {
      game->character->last_pos = DOWN;
      print_down(game, i, move.coord);
    }
}

void			print_everything(t_game *game, t_diag draw,
					 sfVector2i from)
{
  t_move_player		move;
  static int		i = 0;
  static int		j = 0;

  check_direction(&move, from, draw);
  which_direction(move, game, i);
  make_this_parallax(game, draw);
  j++;
  if (j == 5)
    {
      i++;
      j = 0;
    }
  if (i > 8)
    i = 0;
}
