/*
** main.c for main.c in /home/roye_v/delivery/wireframe
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Dec 11 21:38:49 2016 Vincent Roye
** Last update Thu Jun  1 06:45:06 2017 thibaut trouve
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include "tekadventure.h"

void	init_screen(t_window *win)
{
  win->window = create_window("TekAdventure", SCREEN_WIDTH, SCREEN_HEIGHT);
  win->sprite = sfSprite_create();
  win->texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  win->framebuffer = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void	keep_screen(t_window *win)
{
  sfRenderWindow_clear(win->window, sfBlack);
  sfSprite_setTexture(win->sprite, win->texture, sfTrue);
  sfRenderWindow_drawSprite(win->window, win->sprite, NULL);
  sfRenderWindow_display(win->window);
}

void		disp_img(t_my_framebuffer *framebuffer, char *path)
{
  sfColor	pixel;
  int		*img;
  int		x;
  int		y;
  int		i;

  i = 3;
  pixel.a = 255;
  img = load_img(path);
  if (img == NULL)
    return ;
  y = img[1];
  while (y > 0)
    {
      x = 0;
      while (x < img[2] && i < img[0])
	{
	  pixel.b = img[i];
	  pixel.g = img[i + 1];
	  pixel.r = img[i + 2];
	  my_put_pixel(framebuffer, x, y, pixel);
	  x++;
	  i += 3;
	}
      y--;
    }
}

void		keyboard(t_window *win, sfVector2i *win_coords, char *path)
{
  if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
    {
      disp_img(win->framebuffer, path);
    }
}

int		main(int ac, char **argv, char **env)
{
  t_window	win;
  sfVector2i	win_coords;

  init_screen(&win);
  while (sfRenderWindow_isOpen(win.window))
    {
      keep_screen(&win);
      if (ac == 2)
	keyboard(&win, &win_coords, argv[1]);
      sfTexture_updateFromPixels(win.texture, win.framebuffer->pixels,
				 SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    }
  free(win.framebuffer);
  sfRenderWindow_destroy(win.window);
}
