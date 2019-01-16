/*
1;4600;0c** main.c for main.c in /home/roye_v/delivery/tekadventure
**
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
**
** Started on  Mon Mar 20 21:55:11 2017 Vincent Roye
** Last update Thu Jun  1 06:37:21 2017 thibaut trouve
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

int	*fill_file(int *file, int fd)
{
  int	size;
  int	a;
  int	i;

  i = 1;
  a = 0;
  size = 1;
  while (size != 0)
    {
      size = read(fd, &a, 1);
      file[i] = a;
      i++;
    }
  return (file);
}

int	*epur_image_value(int *file, int *img_size)
{
  int	*img;
  int	i;
  int	j;

  i = 55;
  j = 3;
  img = malloc(sizeof(int) * (file[0] - 1));
  if (img == NULL)
    return (NULL);
  img[0] = file[0] - 52;
  img[1] = img_size[0];
  img[2] = img_size[1];
  while (j <= img[0])
    {
      img[j] = file[i];
      i++;
      j++;
    }
  return (img);
}

int	get_file(t_loader *load, char *filename)
{
  load->file_size = get_file_size(filename);
  if (load->file_size == -1)
    return (84);
  load->file = malloc(sizeof(int) * (load->file_size + 1));
  if (load->file == NULL)
    return (84);
  load->file[0] = load->file_size;
  load->fd = open(filename, O_RDONLY);
  if (load->fd == -1)
    return (84);
  load->file = fill_file(load->file, load->fd);
  load->width = get_int_tab(load->file, 19);
  load->width = rev_int(load->width);
  load->height = get_int_tab(load->file, 23);
  load->height = rev_int(load->height);
  load->c_width = malloc(sizeof(char) * 9);
  if (load->c_width == NULL)
    return (84);
  load->c_height = malloc(sizeof(char) * 9);
  if (load->c_height == NULL)
    return (84);
  load->c_width[0] = '\0';
  load->c_height[0] = '\0';
  return (0);
}

void	get_width(t_loader *load)
{
  int	i;

  i = 0;
  while (i < 4)
    {
      load->c_width = my_strcat(load->c_width, my_base(load->width[i], 16));
      load->c_height = my_strcat(load->c_height, my_base(load->height[i], 16));
      i++;
    }
}

int	*load_img(char *filename)
{
  int		i;
  t_loader	*load;

  load = malloc(sizeof(t_loader));
  if (load == NULL)
    return (NULL);
  i = 0;
  if (get_file(load, filename) == 84)
    return (NULL);
  get_width(load);
  free(load->width);
  free(load->height);
  load->img_size = malloc(sizeof(int) * 2);
  if (load->img_size == NULL)
    return (NULL);
  load->img_size[0] = hex_to_int(load->c_height);
  load->img_size[1] = hex_to_int(load->c_width);
  free(load->c_height);
  free(load->c_width);
  load->img = epur_image_value(load->file, load->img_size);
  free(load->file);
  free(load->img_size);
  return (load->img);
}
