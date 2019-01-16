/*
** initialization.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor/src
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Sat May 27 01:35:20 2017 Antoine Duez
** Last update Sat May 27 17:29:55 2017 Vincent Roye
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

void		init_draws(t_window *win, int i)
{
  win->editor.scene[i]->w_zone.from = malloc(sizeof(sfVector2i));
  win->editor.scene[i]->w_zone.from[0].x = -1;
  win->editor.scene[i]->w_zone.to = malloc(sizeof(sfVector2i));
  win->editor.scene[i]->w_zone.to[0].x = -1;
  win->editor.scene[i]->d_zone.font =
    sfFont_createFromFile("ttf/battlefield.ttf");
  win->editor.scene[i]->d_zone.text = NULL;
  win->editor.scene[i]->d_zone.from = malloc(sizeof(sfVector2i));
  win->editor.scene[i]->d_zone.from[0].x = -1;
  win->editor.scene[i]->d_zone.to = malloc(sizeof(sfVector2i));
  win->editor.scene[i]->d_zone.to[0].x = -1;
  win->editor.scene[i]->obj.font =
    sfFont_createFromFile("ttf/battlefield.ttf");
  win->editor.scene[i]->obj.text = NULL;
  win->editor.scene[i]->obj.from = malloc(sizeof(sfVector2i));
  win->editor.scene[i]->obj.from[0].x = -1;
  win->editor.scene[i]->obj.to = malloc(sizeof(sfVector2i));
  win->editor.scene[i]->obj.to[0].x = -1;
}

void		init_textures_next(t_window *win, int i)
{
  win->editor.scene[i]->t.spawn =
    sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(win->editor.scene[i]->s.spawn,
		      win->editor.scene[i]->t.spawn, sfTrue);
  win->editor.scene[i]->s.door = sfSprite_create();
  win->editor.scene[i]->t.door =
    sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(win->editor.scene[i]->s.door,
		      win->editor.scene[i]->t.door, sfTrue);
  win->editor.scene[i]->s.object = sfSprite_create();
  win->editor.scene[i]->t.object =
    sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(win->editor.scene[i]->s.object,
		      win->editor.scene[i]->t.object, sfTrue);
  win->editor.scene[i]->music.text = sfText_create();
}

void		init_textures(t_window *win, int i)
{
  win->editor.scene[i]->music.font =
    sfFont_createFromFile("ttf/battlefield.ttf");
  win->editor.scene[i]->drawbuffer =
    my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  win->editor.scene[i]->doorbuffer =
    my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  win->editor.scene[i]->objectbuffer =
    my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  win->editor.scene[i]->s.background = sfSprite_create();
  win->editor.scene[i]->s.walk_zone = sfSprite_create();
  win->editor.scene[i]->t.walk_zone =
    sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(win->editor.scene[i]->s.walk_zone,
		      win->editor.scene[i]->t.walk_zone, sfTrue);
  win->editor.scene[i]->s.spawn = sfSprite_create();
  init_textures_next(win, i);
}

void		init_texts(t_window *win, int i, sfVector2f music_pos)
{
  sfText_setColor(win->editor.scene[i]->music.text, sfWhite);
  sfText_setCharacterSize(win->editor.scene[i]->music.text, 12);
  sfText_setString(win->editor.scene[i]->music.text, "none");
  sfText_setPosition(win->editor.scene[i]->music.text, music_pos);
  win->editor.scene[i]->music.font =
    sfFont_createFromFile("ttf/battlefield.ttf");
  sfText_setFont(win->editor.scene[i]->music.text,
		 win->editor.scene[i]->music.font);
}

void		init_screen(t_window *win)
{
  int		i;
  int		j;
  sfVector2f	music_pos;

  music_pos.x = 10;
  music_pos.y = 10;
  j = 0;
  win->editor.info.scene =
    malloc(sizeof(int) * (win->editor.background_max + 1));
  while (j <= win->editor.background_max)
    {
      win->editor.info.scene[j] = j;
      j++;
    }
  i = 0;
  win->window = create_window("TekEditor", SCREEN_WIDTH, SCREEN_HEIGHT);
  win->framebuffer = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  while (win->editor.scene[i] != NULL)
    {
      init_draws(win, i);
      init_textures(win, i);
      init_texts(win, i, music_pos);
      i++;
    }
  win->editor.pos = 0;
}
