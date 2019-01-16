/*
** special_sfvetor.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Tue May 23 14:47:47 2017 Antoine Duez
** Last update Sat May 27 16:44:22 2017 Antoine Duez
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include <stdlib.h>
#include "editor.h"

int		count_vector2i_tab(sfVector2i *vector)
{
  int		i;

  i = 0;
  while (vector[i].x != -1)
    i++;
  return (i);
}

int		count_text_tab(sfText **text)
{
  int		i;

  i = 0;
  while (text[i] != NULL)
    i++;
  return (i);
}

sfVector2i	*add_vector2i_value(sfVector2i *vector, sfVector2i new_value)
{
  sfVector2i	*new_vector;
  int		i;

  i = 0;
  if (vector[0].x == -1)
    {
      new_vector = malloc(sizeof(sfVector2i) * 2);
      new_vector[i] = new_value;
      new_vector[i + 1].x = -1;
    }
  else
    {
      new_vector =
	malloc(sizeof(sfVector2i) * (count_vector2i_tab(vector) + 2));
      while (vector[i].x != -1)
	{
	  new_vector[i] = vector[i];
	  i++;
	}
      new_vector[i] = new_value;
      new_vector[i + 1].x = -1;
    }
  return (new_vector);
}

sfText		**add_text_value(sfText **text, sfText *new_value)
{
  sfText	**new_text;
  int		i;

  i = 0;
  if (text == NULL)
    {
      new_text = malloc(sizeof(sfText *) * 2);
      new_text[i] = new_value;
      new_text[i + 1] = NULL;
    }
  else
    {
      new_text = malloc(sizeof(sfText *) * (count_text_tab(text) + 2));
      while (text[i] != NULL)
	{
	  new_text[i] = text[i];
	  i++;
	}
      new_text[i] = new_value;
      new_text[i + 1] = NULL;
    }
  return (new_text);
}
