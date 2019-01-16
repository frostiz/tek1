/*
** init_main_screen.c for init_main_screen.c in /home/roye_v/delivery/tekadventure
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Mon May 22 13:55:51 2017 Vincent Roye
** Last update Sun May 28 06:07:10 2017 Vincent Roye
*/

#include	<SFML/Audio.h>
#include	<SFML/Graphics.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<math.h>
#include	<stdio.h>
#include	"tekadventure.h"
#include	"main_screen.h"

static int	init_text_font(t_window *win)
{
  win->text.font = sfFont_createFromFile("ttf/leadcoat.ttf");
  if (!(win->text.font))
    return (-1);
  win->text.text = sfText_create();
  win->text2.font = sfFont_createFromFile("ttf/leadcoat.ttf");
  if (!(win->text2.font))
    return (-1);
  win->text2.text = sfText_create();
  win->main_menu.new_game.font = sfFont_createFromFile("ttf/battlefield.ttf");
  if (!(win->main_menu.new_game.font))
    return (-1);
  win->main_menu.new_game.text = sfText_create();
  win->main_menu.options.font = sfFont_createFromFile("ttf/battlefield.ttf");
  if (!(win->main_menu.options.font))
    return (-1);
  win->main_menu.options.text = sfText_create();
  win->main_menu.main_title.font = sfFont_createFromFile("ttf/Starjout.ttf");
  if (!(win->main_menu.main_title.font))
    return (-1);
  win->main_menu.main_title.text = sfText_create();
  if (!(win->main_menu.main_title.text))
    return (-1);
  return (0);
}

static int		init_color_character(t_window *win)
{
  sfText_setColor(win->text.text, sfYellow);
  sfText_setColor(win->text2.text, sfYellow);
  sfText_setColor(win->main_menu.new_game.text, sfBlue);
  sfText_setColor(win->main_menu.options.text, sfBlue);
  sfText_setColor(win->main_menu.main_title.text, sfYellow);

  sfText_setCharacterSize(win->text.text, 50);
  sfText_setCharacterSize(win->text2.text, 50);
  sfText_setCharacterSize(win->main_menu.new_game.text, 22);
  sfText_setCharacterSize(win->main_menu.options.text, 22);
  sfText_setCharacterSize(win->main_menu.main_title.text, 50);
  return (0);
}

static int	init_position_font(t_window *win, sfVector2f text_pos)
{
  sfText_setString(win->main_menu.new_game.text, "Start");
  sfText_setPosition(win->main_menu.new_game.text, text_pos);
  text_pos.y += 30;
  sfText_setString(win->main_menu.options.text, "Sound");
  sfText_setPosition(win->main_menu.options.text, text_pos);
  text_pos.x = (SCREEN_WIDTH / 2) - 250;
  text_pos.y = (SCREEN_HEIGHT / 2 - 200);
  sfText_setString(win->main_menu.main_title.text, "Star Adventure");
  sfText_setPosition(win->main_menu.main_title.text, text_pos);
  sfText_setFont(win->text2.text, win->text2.font);
  sfText_setFont(win->text.text, win->text.font);
  sfText_setFont(win->main_menu.new_game.text, win->main_menu.new_game.font);
  sfText_setFont(win->main_menu.options.text, win->main_menu.options.font);
  sfText_setFont(win->main_menu.main_title.text,
		 win->main_menu.main_title.font);
  return (0);
}

static int	init_picture(t_window *win)
{
  sfVector2f	menu_scale;

  menu_scale.x = 0.3;
  menu_scale.y = 0.5;
  win->sprite = sfSprite_create();
  win->cockpit.sprite = sfSprite_create();
  win->main_menu.laser.sprite = sfSprite_create();
  win->texture =
    sfTexture_createFromFile("pictures/main_screen/Space.jpg", NULL);
  if (!win->texture)
    return (1);
  win->cockpit.texture =
    sfTexture_createFromFile("pictures/main_screen/cockpit.png", NULL);
  if (!win->cockpit.texture)
    return (1);
  win->main_menu.laser.texture =
    sfTexture_createFromFile("pictures/main_screen/laser.jpg", NULL);
  if (!win->main_menu.laser.texture)
    return (1);
  (void)menu_scale;
  sfSprite_setTexture(win->sprite, win->texture, sfTrue);
  sfSprite_setTexture(win->cockpit.sprite, win->cockpit.texture, sfTrue);
  sfSprite_setTexture(win->main_menu.laser.sprite,
		      win->main_menu.laser.texture, sfTrue);
  return (0);
}

int		init_main_screen(t_window *win)
{
  sfVector2f	text_pos;

  win->main_menu.clicked = 0;
  win->main_menu.sound = 0;
  text_pos.x = (SCREEN_WIDTH / 2) + 220;
  text_pos.y = SCREEN_HEIGHT - 290;
  win->window = create_window("TekAdventure",
			      SCREEN_WIDTH, SCREEN_HEIGHT);
  if (!(win->window))
    return (-1);
  if (init_text_font(win) == -1)
    return (-1);
  if (init_color_character(win) == -1)
    return (-1);
  if (init_position_font(win, text_pos) == -1)
    return (-1);
  if (init_picture(win) == -1)
    return (-1);
  return (0);
}
