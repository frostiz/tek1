/*
** special_sfml.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Thu May 18 23:51:44 2017 Antoine Duez
** Last update Fri May 19 02:14:17 2017 Antoine Duez
*/

#include <SFML/Graphics/RenderWindow.h>
#include "editor.h"

CSFML_WINDOW_API sfBool sfMouse_isButtonReleased(sfMouseButton button,
						 t_window *win)
{
  sfEvent		event;

  sfRenderWindow_pollEvent(win->window, &event);
  if (event.mouseButton.type == sfEvtMouseButtonReleased &&
      event.mouseButton.button == button)
    return (sfTrue);
  else
    return (sfFalse);
}

CSFML_WINDOW_API sfBool sfKeyboard_isKeyReleased(sfKeyCode key,
						 t_window *win)
{
  sfEvent		event;

  sfRenderWindow_pollEvent(win->window, &event);
  if (event.key.type == sfEvtKeyReleased &&
      event.key.code == key)
    return (sfTrue);
  else
    return (sfFalse);
}
