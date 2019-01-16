/*
** mouse.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor/src
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Sat May 27 01:49:44 2017 Antoine Duez
** Last update Sat May 27 03:09:41 2017 Antoine Duez
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

void		all_event_button(t_window *win, sfEvent event)
{
  if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
      && (event.mouseButton.x >= 160 && event.mouseButton.x <= 290)
      && (event.mouseButton.y >= 650 && event.mouseButton.y <= 720))
    button_walk_zone(win);
  else if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
	   && (event.mouseButton.x >= 320 && event.mouseButton.x <= 450)
	   && (event.mouseButton.y >= 650 && event.mouseButton.y <= 720))
    button_spawn(win);
  else if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
	   && (event.mouseButton.x >= 480 && event.mouseButton.x <= 610)
	   && (event.mouseButton.y >= 650 && event.mouseButton.y <= 720))
    button_door(win);
  else if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
	   && (event.mouseButton.x >= 640 && event.mouseButton.x <= 770)
	   && (event.mouseButton.y >= 650 && event.mouseButton.y <= 720))
    button_music(win);
  else if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
	   && (event.mouseButton.x >= 800 && event.mouseButton.x <= 930)
	   && (event.mouseButton.y >= 650 && event.mouseButton.y <= 720))
    button_object(win);
}

void		other_commands(t_window *win)
{
  if (win->menu.display_standard_ui == -1)
    {
      if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
	{
	  if (win->menu.draw_right == WALK)
	    draw_walk_zone(win);
	  else if (win->menu.draw_right == SPAWN)
	    draw_spawn(win);
	  else if (win->menu.draw_right == DOOR)
	    draw_door(win);
	  else if (win->menu.draw_right == OBJECT)
	    draw_object(win);
	}
    }
}

int		mouse(t_window *win)
{
  sfEvent	event;

  sfRenderWindow_pollEvent(win->window, &event);
  if (win->menu.display_standard_ui == 1)
    {
      if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
	  && (event.mouseButton.x >= 1150 && event.mouseButton.x <= 1280)
	  && (event.mouseButton.y >= 650 && event.mouseButton.y <= 720))
	button_next_background(win);
      else if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
	       && (event.mouseButton.x >= 0 && event.mouseButton.x <= 130)
	       && (event.mouseButton.y >= 650 && event.mouseButton.y <= 720))
	button_previous_background(win);
      all_event_button(win, event);
    }
  other_commands(win);
  return (0);
}
