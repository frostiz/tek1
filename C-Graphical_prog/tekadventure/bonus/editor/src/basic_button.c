/*
** basic_button.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor/src
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Sat May 27 01:57:17 2017 Antoine Duez
** Last update Sat May 27 02:49:34 2017 Antoine Duez
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

int	button_walk_zone(t_window *win)
{
  win->menu.draw_right = WALK;
  return (0);
}

int	button_spawn(t_window *win)
{
  win->menu.draw_right = SPAWN;
  return (0);
}

int	button_door(t_window *win)
{
  win->menu.draw_right = DOOR;
  return (0);
}

int	button_object(t_window *win)
{
  win->menu.draw_right = OBJECT;
  return (0);
}
