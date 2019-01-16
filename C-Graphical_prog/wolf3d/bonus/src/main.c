/*
** main.c for wolf3d in /home/frostiz/wolf3d/bonus/src
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Thu Jan 12 17:57:39 2017 thibaut trouve
** Last update Fri Jan 20 13:40:36 2017 thibaut trouve
*/

#include "my.h"

void	mainloop(t_map *data, t_window *win)
{
  while (sfRenderWindow_isOpen(win->window))
    {
      while (sfRenderWindow_pollEvent(win->window, &win->event))
	  if (win->event.type == sfEvtClosed)
	    sfRenderWindow_close(win->window);
      if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
	  move_ahead(data, win);
      else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
	  move_back(data, win);
      if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
	  move_left_right(data, win, 0);
      else if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
	  move_left_right(data, win, 1);
      if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
	  destroy_wall(data, win);
      else if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	  sfRenderWindow_close(win->window);
      sfRenderWindow_clear(win->window, sfBlack);
      sfSprite_setTexture(win->sprite, win->texture, sfTrue);
      sfRenderWindow_drawSprite(win->window, win->sprite, NULL);
      sfRenderWindow_display(win->window);
    }
}

int	main(int argc, char **argv)
{
  t_window	win;
  t_map		data;

  (void)argc;
  if (argv[1] == NULL)
    {
      printf("Invalid map name.\n");
      return (84);
    }
  if (make_window(&win, &data, argv) == 84)
    {
      printf("Invalid map\n");
      return (84);
    }
  data.map = stock_file(argv);
  if (data.map[(int)data.pos.y][(int)data.pos.x] == 1 ||
      check_error(data, argv) == 84)
    {
      printf("Invalid map\n");
      return (84);
    }
  aff(&data, &win);
  mainloop(&data, &win);
  sfRenderWindow_destroy(win.window);
  return (0);
}

