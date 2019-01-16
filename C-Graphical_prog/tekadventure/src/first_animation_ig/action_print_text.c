/*
** action_print_text.c for tekadventure in /home/DxCube/delivery/tekadventure/src/first_animation_ig
** 
** Made by Victor Dubret
** Login   <Victor.dubret@epitech.eu>
** 
** Started on  Sun May 28 19:03:34 2017 Victor Dubret
** Last update Mon May 29 09:45:29 2017 Victor Dubret
*/

#include	"tekadventure.h"
#include	"dialog.h"

static	t_attribute	init_values(sfVector2i *to, sfVector2i *from,
				    t_attribute attribute, t_game *game)
{
  *to = init_vector(from->x, from->y + 50);
  *from = movement_cannot_change(game, *from, *to);
  attribute.pos = init_float_vector(to->x - 150, to->y - 80);
  return (attribute);
}

int		actions(sfVector2i *from, t_game *game)
{
  sfVector2i	to;
  t_datatext	text;
  t_attribute	attribute;
  t_dialog	dial;

  if (init_for_text(&attribute, &text, to, "Que se passe-t-il ?\n"))
    return (84);
  while (sfKeyboard_isKeyPressed(sfKeySpace) != sfTrue);
  attribute = init_values(&to, from, attribute, game);
  dial = create_dialog(text, attribute);
  if (dial.text == NULL)
    return (84);
  display_all(game, from, dial);
  while (sfKeyboard_isKeyPressed(sfKeySpace) != sfTrue);
  if (init_for_text(&attribute, &text, to, "Mon vaisseau est en miettes.\n"))
    return (84);
  to = init_vector(from->x + 150, from->y);
  *from = movement_cannot_change(game, *from, to);
  attribute.pos = init_float_vector(to.x - 150, to.y - 80);
  dial = create_dialog(text, attribute);
  if (dial.text == NULL)
    return (84);
  display_all(game, from, dial);
  while (sfKeyboard_isKeyPressed(sfKeySpace) != sfTrue);
  return (0);
}
