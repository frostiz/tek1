/*
** main_screen.h for main_screen.h in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Mon May 22 13:59:07 2017 Vincent Roye
** Last update Sun May 28 05:55:55 2017 Vincent Roye
*/

#ifndef MAIN_SCREEN_H_
# define MAIN_SCREEN_H_

#include		<SFML/Graphics/RenderWindow.h>
#include		<SFML/Graphics/Texture.h>
#include		<SFML/Graphics/Sprite.h>
#include		<SFML/Audio.h>
#include		"tekadventure.h"

typedef struct		s_pic
{
  sfTexture		*texture;
  sfSprite*		sprite;
}			t_pic;

typedef struct		s_cockpit
{
  sfTexture		*texture;
  sfSprite*		sprite;
}			t_cockpit;

typedef struct		s_text
{
  sfFont*		font;
  sfText*		text;
  sfVector2f		text_pos;
}			t_text;

typedef struct		s_main_menu
{
  int			sound;
  int			clicked;
  t_text		new_game;
  t_text		options;
  t_text		main_title;
  t_pic			laser;
}			t_main_menu;

typedef struct		s_my_framebuffer
{
  sfUint8*		pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_window
{
  t_my_framebuffer*	framebuffer;
  sfRenderWindow*	window;
  sfMusic		*music;
  sfTexture		*texture;
  sfEvent		event;
  sfSprite*		sprite;
  sfVector2f		bg_pos;
  t_text		text;
  t_text		text2;
  t_cockpit		cockpit;
  t_main_menu		main_menu;
}			t_window;

int	init_main_screen(t_window *);
int	main_screen_loop();
int	parallax_main_screen(t_window *);
void	keep_screen(t_window *);
void	keyboard(t_window *);

#endif /* !MAIN_SCREEN_H_ */
