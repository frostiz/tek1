/*
** draw_basic_menu.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor/src
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Sat May 27 02:38:42 2017 Antoine Duez
** Last update Sat May 27 03:02:21 2017 Antoine Duez
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

void		draw_square_next_background(t_window *win)
{
  sfVector2i	from;
  sfVector2i	to;

  from.x = 1150;
  from.y = 650;
  to.x = 1280;
  to.y = 720;
  my_draw_square(win->framebuffer, from, to, sfGreen);
  draw_ext(win->framebuffer, from, to, sfBlack);
  sfTexture_updateFromPixels(win->menu.t.next, win->framebuffer->pixels,
			     1280, 720, 0, 0);
  sfRenderWindow_drawSprite(win->window, win->menu.s.next, NULL);
}

void		draw_square_previous_background(t_window *win)
{
  sfVector2i	from;
  sfVector2i	to;

  from.x = 0;
  from.y = 650;
  to.x = 130;
  to.y = 720;
  my_draw_square(win->framebuffer, from, to, sfRed);
  draw_ext(win->framebuffer, from, to, sfBlack);
  sfTexture_updateFromPixels(win->menu.t.previous, win->framebuffer->pixels,
			     1280, 720, 0, 0);
  sfRenderWindow_drawSprite(win->window, win->menu.s.previous, NULL);
}
