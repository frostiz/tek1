/*
** newmain.c for raytracer in /home/thibaut/Repository/raytracer1/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Mar 19 18:32:55 2017 
** Last update Sun Mar 19 19:43:47 2017 
*/

#include "my.h"

sfRenderWindow*	create_window(char *name, int width, int height)
{
  sfRenderWindow* window;
  sfVideoMode mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    {
      exit(EXIT_FAILURE);
    }
  return (window);
}

void	reset_buffer(t_my_framebuffer* buffer)
{
  int	i;

  i = 0;
  while (i < WIDTH * HEIGHT * 4)
    {
      buffer->pixels[i] = 0;
      i++;
    }
}

void	interpret_key(t_my_framebuffer *framebuffer,
		      sfTexture *texture,
		      sfRenderWindow *window)
{
  if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue)
    {
      reset_buffer(framebuffer);
      raytrace_scene_sphere(framebuffer);
    }
  if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
    {
      reset_buffer(framebuffer);
      raytrace_scene_cone(framebuffer);
    }
  if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
    {
      reset_buffer(framebuffer);
      raytrace_scene_cylinder(framebuffer);
    }
  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    sfRenderWindow_close(window);
  sfTexture_updateFromPixels(texture,
			     framebuffer->pixels,
			     framebuffer->width,
			     framebuffer->height, 0, 0);
}

int	process_game_loop(sfRenderWindow *window,
			  sfSprite *sprite,
			  t_my_framebuffer *framebuffer,
			  sfTexture *texture)
{
  sfEvent	event;

  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(window);
	  interpret_key(framebuffer, texture, window);
	}
      sfRenderWindow_clear(window, sfBlack);
      sfSprite_setTexture(sprite, texture, sfTrue);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
  return (0);
}

int	main(int argc, char **argv, char **env)
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  t_my_framebuffer	*framebuffer;

  if (get_var_env_value(env, "DISPLAY") == NULL)
    {
      my_putstr_err("DISPLAY environnement variable not found.\n");
      return (84);
    }
  (void)argc;
  (void)argv;
  window = create_window("Raytracer1", WIDTH, HEIGHT);
  texture = sfTexture_create(WIDTH, HEIGHT);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  framebuffer = my_framebuffer_create(WIDTH, HEIGHT);
  process_game_loop(window, sprite, framebuffer, texture);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
  sfRenderWindow_destroy(window);
  return (0);
}
