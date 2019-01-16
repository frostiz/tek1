/*
** stock_map.c for stock_map.c in /home/frostiz/PSU_2016_my_sokoban
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Fri Dec 16 12:31:58 2016 thibaut trouve
** Last update Tue Dec 20 04:25:23 2016 thibaut trouve
*/

#include "my.h"

void	init_counts(t_count *count)
{
  count->i = 0;
  count->j = 0;
  count->k = 0;
}

char	**stock_map(char **argv, int col_max, int row_max)
{
  char          **map;
  char          buffer[1048576];
  t_count       count;
  int           fd;

  if ((fd = open(argv[1], O_RDONLY)) == -1)
    exit(84);
  read(fd, buffer, 1048576);
  init_counts(&count);
  if ((map = (void*)malloc(sizeof(char*) * row_max + 1)) == NULL)
    return (NULL);
  if ((map[count.j] = (void*)malloc(sizeof(char) * col_max + 1)) == NULL)
    return (NULL);
  while (buffer[count.i] != '\0')
    {
      map[count.j][count.k] = buffer[count.i];
      count.i++;
      count.k++;
      if (buffer[count.i] == '\n' && buffer[count.i + 1] != '\0')
	end_map_line(&count, map, col_max);
    }
  map[count.j][count.k] = '\0';
  map[count.j + 1] = NULL;
  close(fd);
  return (map);
}

void	end_map_line(t_count *count, char **map, int col_max)
{
  (map)[count->j][count->k] = '\0';
  count->k = 0;
  count->i++;
  count->j++;
  if ((map[count->j] = (void*)malloc(sizeof(char) * col_max + 1)) == NULL)
    return ;
}

void	stock_position(int *nb_p, int i, int j, int *pos)
{
  (*nb_p)++;
  pos[0] = i;
  pos[1] = j;
}

void	stock_position_restart(t_maps maps, int i, int j, int *pos)
{
  maps.map[i][j] = 'P';
  pos[0] = i;
  pos[1] = j;
}
