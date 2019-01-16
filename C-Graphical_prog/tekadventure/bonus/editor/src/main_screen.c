/*
** main_screen.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor/src
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Sat May 27 01:54:37 2017 Antoine Duez
** Last update Sat May 27 16:08:53 2017 Antoine Duez
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

void	init_main_screen_next(t_window *win)
{
  sfSprite_setTexture(win->menu.s.walk_zone, win->menu.t.walk_zone, sfTrue);
  win->menu.s.spawn = sfSprite_create();
  win->menu.t.spawn = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(win->menu.s.spawn, win->menu.t.spawn, sfTrue);
  win->menu.s.door = sfSprite_create();
  win->menu.t.door = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(win->menu.s.door, win->menu.t.door, sfTrue);
  win->menu.s.music = sfSprite_create();
  win->menu.t.music = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(win->menu.s.music, win->menu.t.music, sfTrue);
  win->menu.s.object = sfSprite_create();
  win->menu.t.object = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(win->menu.s.object, win->menu.t.object, sfTrue);
  win->menu.display_standard_ui = 1;
  win->menu.draw_right = NONE;
}

int	init_main_screen(t_window *win)
{
  win->editor.scene[win->editor.pos]->t.background =
    sfTexture_createFromFile(win->editor.scene[win->editor.pos]->name, NULL);
  if (!win->editor.scene[win->editor.pos]->t.background)
    return (1);
  sfSprite_setTexture(win->editor.scene[win->editor.pos]->s.background,
		      win->editor.scene[win->editor.pos]->t.background, sfTrue);
  win->menu.s.next = sfSprite_create();
  win->menu.t.next = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(win->menu.s.next, win->menu.t.next, sfTrue);
  win->menu.s.previous = sfSprite_create();
  win->menu.t.previous = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(win->menu.s.previous, win->menu.t.previous, sfTrue);
  win->menu.s.walk_zone = sfSprite_create();
  win->menu.t.walk_zone = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  init_main_screen_next(win);
  return (0);
}
