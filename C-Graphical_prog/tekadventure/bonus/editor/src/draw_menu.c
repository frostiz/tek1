/*
** draw_menu.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Tue May 23 14:37:14 2017 Antoine Duez
** Last update Sat May 27 02:55:39 2017 Antoine Duez
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

void		draw_square_walk_button(t_window *win)
{
  sfVector2i	from;
  sfVector2i	to;

  from.x = 160;
  from.y = 650;
  to.x = 290;
  to.y = 720;
  my_draw_square(win->framebuffer, from, to, sfYellow);
  draw_ext(win->framebuffer, from, to, sfBlack);
  sfTexture_updateFromPixels(win->menu.t.walk_zone, win->framebuffer->pixels,
			     1280, 720, 0, 0);
  sfRenderWindow_drawSprite(win->window, win->menu.s.walk_zone, NULL);
}

void		draw_square_spawn_button(t_window *win)
{
  sfVector2i	from;
  sfVector2i	to;

  from.x = 320;
  from.y = 650;
  to.x = 450;
  to.y = 720;
  my_draw_square(win->framebuffer, from, to, sfMagenta);
  draw_ext(win->framebuffer, from, to, sfBlack);
  sfTexture_updateFromPixels(win->menu.t.spawn, win->framebuffer->pixels,
			     1280, 720, 0, 0);
  sfRenderWindow_drawSprite(win->window, win->menu.s.spawn, NULL);
}

void		draw_square_door_button(t_window *win)
{
  sfVector2i	from;
  sfVector2i	to;

  from.x = 480;
  from.y = 650;
  to.x = 610;
  to.y = 720;
  my_draw_square(win->framebuffer, from, to, sfBlue);
  draw_ext(win->framebuffer, from, to, sfBlack);
  sfTexture_updateFromPixels(win->menu.t.door, win->framebuffer->pixels,
			     1280, 720, 0, 0);
  sfRenderWindow_drawSprite(win->window, win->menu.s.door, NULL);
}

void		draw_square_music_button(t_window *win)
{
  sfVector2i	from;
  sfVector2i	to;

  from.x = 640;
  from.y = 650;
  to.x = 770;
  to.y = 720;
  my_draw_square(win->framebuffer, from, to, sfWhite);
  draw_ext(win->framebuffer, from, to, sfBlack);
  sfTexture_updateFromPixels(win->menu.t.music, win->framebuffer->pixels,
			     1280, 720, 0, 0);
  sfRenderWindow_drawSprite(win->window, win->menu.s.music, NULL);
}

void		draw_square_object_button(t_window *win)
{
  sfVector2i	from;
  sfVector2i	to;

  from.x = 800;
  from.y = 650;
  to.x = 930;
  to.y = 720;
  my_draw_square(win->framebuffer, from, to, sfCyan);
  draw_ext(win->framebuffer, from, to, sfBlack);
  sfTexture_updateFromPixels(win->menu.t.object, win->framebuffer->pixels,
			     1280, 720, 0, 0);
  sfRenderWindow_drawSprite(win->window, win->menu.s.object, NULL);
}
