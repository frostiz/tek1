/*
** print_first_text.c for tekadventure in /home/DxCube/delivery/tekadventure
** 
** Made by Victor Dubret
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sun May 28 06:12:18 2017 Victor Dubret
** Last update Sun May 28 22:02:07 2017 Vincent Roye
*/

#include	"tekadventure.h"
#include	"dialog.h"

sfVector2i	(*incr_sup[4])(t_game *, sfVector2i, sfVector2i)
= {abs_inf, abs_sup, ord_inf, ord_sup};

int	(*what_sup[2])(int, int)
= {is_inf, is_sup};

int	init_for_text(t_attribute *attribute,
			      t_datatext *text, sfVector2i to, char *str)
{
  text->string = str;
  text->font_path = "ttf/battlefield.ttf";
  if (!text->font_path)
    return (84);
  text->size = 25;
  text->color = sfWhite;
  attribute->scale.x = 1.0;
  attribute->scale.y = 1.0;
  attribute->pos.x = (float)to.x - 30;
  attribute->pos.y = (float)to.y - 75;
  attribute->angle = 0;
  return (0);
}

void	display_all(t_game *game, sfVector2i *from, t_dialog dial)
{
  sfVector2f	spawn;

  spawn.x = (float)from->x;
  spawn.y = (float)from->y;
  sfRenderWindow_clear(game->window, sfBlack);
  sfSprite_setPosition (game->character->down_walk.sprite[0], spawn);
  sfRenderWindow_drawSprite(game->window, game->bg->sprite, NULL);
  sfRenderWindow_drawSprite(game->window,
			    game->character->down_walk.sprite[0], NULL);
  sfRenderWindow_drawText(game->window, dial.text, NULL);
  print_object(game);
  print_character(game);
  sfRenderWindow_display(game->window);
}

sfVector2i	movement_cannot_change(t_game *game,
				       sfVector2i from,
				       sfVector2i to)
{
  int			i;
  int			j;

  i = 0;
  j = 0;
  while (i < 2 && j < 4)
    {
      if (what_sup[i](from.x, to.x) == 1)
	from = incr_sup[j](game, from, to);
      i++;
      j++;
    }
  i = 0;
  while (i < 2 && j < 4)
    {
      if (what_sup[i](from.y, to.y) == 1)
	from = incr_sup[j](game, from, to);
      i++;
      j++;
    }
  return (from);
}

static	sfVector2i	init_values(sfVector2i to
				    , sfVector2i *from,
				    t_map *graph, t_game *game)
{
  to = init_vector(from->x + 150, from->y);
  game->background = graph->background;
  *from = movement_cannot_change(game, *from, to);
  to = init_vector(from->x - 300, from->y);
  *from = movement_cannot_change(game, *from, to);
  return (to);
}

int			print_first_text(t_game *game, sfVector2i *from,
					 t_map *graph)
{
  t_datatext	text;
  t_attribute	attribute;
  sfVector2i	to;
  t_dialog	dial;

  to = init_values(to, from, graph, game);
  if (init_for_text(&attribute, &text, to, "!?!?!?!\n") == 84)
    return (84);
  dial = create_dialog(text, attribute);
  if (dial.text == NULL)
    return (84);
  display_all(game, from, dial);
  if (actions(from, game) == 84)
    return (84);
  to = init_vector(637, 647);
  *from = movement_cannot_change(game, *from, to);
  text.string = "Je dois retrouver tous\nles morceaux et partir d'ici.";
  attribute.pos = init_float_vector(to.x - 175, to.y - 100);
  dial = create_dialog(text, attribute);
  if (dial.text == NULL)
    return (84);
  display_all(game, from, dial);
  while (sfKeyboard_isKeyPressed(sfKeySpace) != sfTrue);
  return (0);
}
