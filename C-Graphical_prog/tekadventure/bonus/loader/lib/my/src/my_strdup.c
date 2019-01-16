/*
** my_strdup.c for my_strdup.c in /home/roye_v/delivery/raytracer1
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Thu Mar 16 14:13:24 2017 Vincent Roye
** Last update Thu Mar 16 14:15:30 2017 Vincent Roye
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*str;

  str = malloc(sizeof(char) * (my_strlen(src) + 1));
  if (str == NULL)
    return (NULL);
  my_strcpy(str, src);
  return (str);
}
