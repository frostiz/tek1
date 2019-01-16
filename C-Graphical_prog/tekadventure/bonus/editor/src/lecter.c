/*
** lecter.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor/src
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Sat May 27 01:19:22 2017 Antoine Duez
** Last update Sat May 27 17:14:24 2017 Antoine Duez
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "editor.h"

void  init_scene(t_window *win, int i, int fd)
{
  win->editor.scene[i] = malloc(sizeof(t_scene));
  win->editor.scene[i]->name = get_next_line(fd);
  win->editor.info.background[i] = strdup(win->editor.scene[i]->name);
}

void	background_lecter(t_window *win)
{
  int	fd;
  int	i;
  char	*str;

  i = 0;
  win->editor.background_max = get_background_nb() - 1;
  win->editor.scene = malloc(sizeof(t_scene *) * (get_background_nb() + 1));
  win->editor.info.background =
    malloc(sizeof(char *) * (get_background_nb() + 1));
  fd = open("editor/editor_rsc/backgrounds", O_RDONLY);
  str = get_next_line(fd);
  while (my_strcmp(str, "==START==") != 1 && str != NULL)
    str = get_next_line(fd);
  init_scene(win, i, fd);
  while (my_strcmp(win->editor.scene[i]->name, "==END==") != 1
	 && win->editor.scene[i]->name != NULL)
    {
      i++;
      init_scene(win, i, fd);
    }
  win->editor.scene[i] = NULL;
  win->editor.info.background[i] = NULL;
  close(fd);
}

void	music_lecter(t_window *win)
{
  int	fd;
  int	i;
  char	*str;

  i = 0;
  win->editor.music_max = get_music_nb() - 1;
  win->editor.info.music = malloc(sizeof(char *) * (get_music_nb() + 1));
  fd = open("editor/editor_rsc/musics", O_RDONLY);
  str = get_next_line(fd);
  while (my_strcmp(str, "==START==") != 1 && str != NULL)
    str = get_next_line(fd);
  win->editor.info.music[i] = get_next_line(fd);
  while (my_strcmp(win->editor.info.music[i], "==END==") != 1
	 && win->editor.info.music[i] != NULL)
    {
      i++;
      win->editor.info.music[i] = get_next_line(fd);
    }
  win->editor.info.music[i] = NULL;
  close(fd);
}

void	object_lecter(t_window *win)
{
  int	fd;
  int	i;
  char	*str;

  i = 0;
  win->editor.obj_max = get_object_nb() - 1;
  win->editor.info.object = malloc(sizeof(char *) * (get_object_nb() + 1));
  fd = open("editor/editor_rsc/objects", O_RDONLY);
  str = get_next_line(fd);
  while (my_strcmp(str, "==START==") != 1 && str != NULL)
    str = get_next_line(fd);
  win->editor.info.object[i] = get_next_line(fd);
  while (my_strcmp(win->editor.info.object[i], "==END==") != 1
	 && win->editor.info.object[i] != NULL)
    {
      i++;
      win->editor.info.object[i] = get_next_line(fd);
    }
  win->editor.info.object[i] = NULL;
  close(fd);
}
