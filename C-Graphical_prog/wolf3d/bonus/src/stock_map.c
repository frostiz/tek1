/*
** stock_map.c for stock_map.c in /home/frostiz/wolf3d/bonus/src
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Thu Jan 12 17:44:57 2017 thibaut trouve
** Last update Sun Jan 15 21:36:43 2017 thibaut trouve
*/

#include "my.h"

int	nb_lign(char *buffer)
{
  int   i;
  int   nb_lign;

  nb_lign = 0;
  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	nb_lign++;
      i++;
    }
  return (nb_lign);
}

int	lign_lenght(char *buffer)
{
  int   i;
  int   len;
  int   tmp;

  i = 0;
  len = 0;
  tmp = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	{
	  if (tmp > len)
	    len = tmp;
	  tmp = -1;
	}
      tmp++;
      i++;
    }
  return (len);
}

void	backslash_n(t_count *counts, int **map, char buffer[])
{
  counts->buf++;
  counts->col = 0;
  counts->row++;
  if ((map[counts->row] = malloc(sizeof(int) * lign_lenght(buffer) + 1))
      == NULL)
    return ;
}

int	**stock_file(char **argv)
{
  t_count	counts;
  char		buffer[1048576];
  int	        **map;

  read(open(argv[1], O_RDONLY), buffer, 1048576);
  counts.buf = 0;
  counts.col = 0;
  counts.row = 0;
  if ((map = malloc(sizeof(int*) * nb_lign(buffer) + 1)) == NULL)
    return (NULL);
  if ((map[0] = malloc(sizeof(int) * lign_lenght(buffer) + 1)) == NULL)
    return (NULL);
  while (buffer[counts.buf] != '\0')
    {
      if (buffer[counts.buf] != '0')
	map[counts.row][counts.col] = 1;
      else
	map[counts.row][counts.col] = 0;
      counts.buf++;
      counts.col++;
      if (buffer[counts.buf] == '\n' && buffer[counts.buf + 1] != '\0')
	  backslash_n(&counts, map, buffer);
    }
  return (map);
}

int	get_mapsize(char **argv, int *max_x)
{
  int   fd;
  int   size;
  int   max_y;
  char  buffmap[1048576];

  max_y = 0;
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    return (-1);
  size = read(fd, buffmap, 1048576);
  max_y = get_x_y(buffmap, max_x);
  if (buffmap[size - 1] != '\n')
    {
      printf("Error : there is no \\n at the end of the map\n");
      return (-1);
    }
  return (max_y);
}
