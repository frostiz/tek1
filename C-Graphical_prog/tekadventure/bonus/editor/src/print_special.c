/*
** print_special.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor/src
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Sat May 27 01:24:55 2017 Antoine Duez
** Last update Sat May 27 20:35:34 2017 Antoine Duez
*/

#include <string.h>
#include <stdio.h>
#include "editor.h"
#include "my.h"

void	print_walk_zone(sfVector2i *from, sfVector2i *to)
{
  int	i;

  i = 0;
  while (from[i].x != -1)
    {
      printf("%d:%d\n", from[i].x, from[i].y);
      printf("%d:%d\n", to[i].x, to[i].y);
      i++;
    }
}

void	print_door_zone(sfVector2i *from, sfVector2i *to, sfText **text)
{
  int	i;
  char	*str;
  char	**tab;

  i = 0;
  while (from[i].x != -1)
    {
      str = strdup(sfText_getString(text[i]));
      tab = str_to_wordtab(str, ' ');
      printf("%d:%d\n", from[i].x, from[i].y);
      printf("%d:%d\n", to[i].x, to[i].y);
      printf("%s\n", tab[1]);
      i++;
    }
}

void	print_object_zone(sfVector2i *from, sfVector2i *to, sfText **text)
{
  int	i;

  i = 0;
  while (from[i].x != -1)
    {
      printf("%d:%d\n", from[i].x, from[i].y);
      printf("%d:%d\n", to[i].x, to[i].y);
      printf("%s\n", sfText_getString(text[i]));
      i++;
    }
}
