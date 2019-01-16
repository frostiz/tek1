/*
** open_window.c for open_window.c in /home/frostiz/bootstrap_graphical_programming
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Thu Nov 10 09:13:47 2016 thibaut trouve
** Last update Thu Dec 15 10:32:34 2016 thibaut trouve
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
