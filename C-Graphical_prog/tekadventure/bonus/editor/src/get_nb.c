/*
** get_nb.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor/src
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Sat May 27 01:15:45 2017 Antoine Duez
** Last update Sat May 27 02:56:23 2017 Antoine Duez
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "editor.h"

int	get_background_nb()
{
  char	*str;
  int	fd;
  int	i;

  i = 0;
  fd = open("editor/editor_rsc/backgrounds", O_RDONLY);
  str = get_next_line(fd);
  while (my_strcmp(str, "==START==") == 0 && str != NULL)
    str = get_next_line(fd);
  str = get_next_line(fd);
  while (my_strcmp(str, "==END==") == 0 && str != NULL)
    {
      i++;
      str = get_next_line(fd);
    }
  close(fd);
  return (i);
}

int	get_music_nb()
{
  char	*str;
  int	fd;
  int	i;

  i = 0;
  fd = open("editor/editor_rsc/musics", O_RDONLY);
  str = get_next_line(fd);
  while (my_strcmp(str, "==START==") == 0 && str != NULL)
    str = get_next_line(fd);
  str = get_next_line(fd);
  while (my_strcmp(str, "==END==") == 0 && str != NULL)
    {
      i++;
      str = get_next_line(fd);
    }
  close(fd);
  return (i);
}

int	get_object_nb()
{
  char	*str;
  int	fd;
  int	i;

  i = 0;
  fd = open("editor/editor_rsc/objects", O_RDONLY);
  str = get_next_line(fd);
  while (my_strcmp(str, "==START==") == 0 && str != NULL)
    str = get_next_line(fd);
  str = get_next_line(fd);
  while (my_strcmp(str, "==END==") == 0 && str != NULL)
    {
      i++;
      str = get_next_line(fd);
    }
  close(fd);
  return (i);
}
