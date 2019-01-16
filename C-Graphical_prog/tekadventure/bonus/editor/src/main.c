/*
** main.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Thu May 18 21:43:44 2017 Antoine Duez
** Last update Sun May 28 04:15:17 2017 Antoine Duez
*/

#include <SFML/Graphics/Texture.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "editor.h"

void		printtab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      printf("%s\n", tab[i]);
      i++;
    }
}

int		check_background_validity(t_window *win)
{
  int		i;
  sfTexture	*background;

  i = 0;
  while (win->editor.scene[i] != NULL)
    {
      background = sfTexture_createFromFile(win->editor.scene[i]->name, NULL);
      if (!background)
	return (1);
      i++;
    }
  return (0);
}

void		print_config_next(t_window *win, int i)
{
  printf("Object Zone\n");
  print_object_zone(win->editor.scene[i]->obj.from,
		    win->editor.scene[i]->obj.to,
		    win->editor.scene[i]->obj.text);
  printf("Spawn\n");
  printf("%d:%d\n", win->editor.scene[i]->spawn.from.x,
	 win->editor.scene[i]->spawn.to.y);
  printf("Music\n");
  printf("%s\n", sfText_getString(win->editor.scene[i]->music.text));
}

void		print_config(t_window *win)
{
  int		i;

  i = 0;
  while (win->editor.scene[i] != NULL)
    {
      printf("Scene:\n%d\n", i);
      printf("Background\n");
      printf("%s\n", win->editor.scene[i]->name);
      printf("Walk Zone\n");
      print_walk_zone(win->editor.scene[i]->w_zone.from,
		      win->editor.scene[i]->w_zone.to);
      printf("Door Zone\n");
      print_door_zone(win->editor.scene[i]->d_zone.from,
		      win->editor.scene[i]->d_zone.to,
		      win->editor.scene[i]->d_zone.text);
      print_config_next(win, i);
      i++;
    }
}

int		main()
{
  t_window	win;

  background_lecter(&win);
  music_lecter(&win);
  object_lecter(&win);
  if (check_background_validity(&win) == 1)
    return (84);
  launch_editor(win);
  print_config(&win);
  return (0);
}
