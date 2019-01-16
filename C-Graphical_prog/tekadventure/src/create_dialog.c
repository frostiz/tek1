/*
** create_dialog.c for tekadventure in /home/frostiz/repository/tekadventure
**
** Made by thibaut trouve
** Login   <thibaut.trouve@epitech.eu>
**
** Started on  Thu May 25 12:55:24 2017 thibaut trouve
** Last update Sun May 28 21:06:38 2017 Vincent Roye
*/

#include <SFML/Graphics.h>
#include "tekadventure.h"
#include "dialog.h"
#include "my.h"

static void	set_text_parameters(t_datatext data, t_attribute attrib,
				    sfText *text, sfFont *font)
{
  sfText_setPosition(text, attrib.pos);
  sfText_setScale(text, attrib.scale);
  sfText_setRotation(text, attrib.angle);
  sfText_setString(text, data.string);
  sfText_setFont(text, font);
  sfText_setCharacterSize(text, data.size);
  sfText_setColor(text, data.color);
}

static void	incr_values(sfVector2f *rect_size, sfFloatRect rect)
{
  rect_size->x = rect.width + 20;
  rect_size->y = rect.height + 20;
}

t_dialog	create_dialog(t_datatext data, t_attribute attrib)
{
  t_dialog		text;
  sfFont		*font;
  sfFloatRect		rect;
  sfVector2f		rect_size;

  text.text = sfText_create();
  if (text.text == NULL)
    return (text);
  font = sfFont_createFromFile(data.font_path);
  if (font == NULL)
    {
      text.text = NULL;
      return (text);
    }
  set_text_parameters(data, attrib, text.text, font);
  rect = sfText_getGlobalBounds(text.text);
  text.border = sfRectangleShape_create();
  attrib.pos = init_float_vector(attrib.pos.x - 10, attrib.pos.y - 10);
  sfRectangleShape_setPosition(text.border, attrib.pos);
  incr_values(&rect_size, rect);
  sfRectangleShape_setSize(text.border, rect_size);
  sfRectangleShape_setFillColor(text.border, sfWhite);
  sfRectangleShape_setOutlineColor(text.border, data.color);
  sfRectangleShape_setOutlineThickness(text.border, 2);
  return (text);
}
