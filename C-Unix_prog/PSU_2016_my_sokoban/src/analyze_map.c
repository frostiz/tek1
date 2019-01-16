/*
** analyze_map.c for analyze_map.c in /home/frostiz/PSU_2016_my_sokoban
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Thu Dec 15 23:59:32 2016 thibaut trouve
** Last update Tue Dec 20 04:22:57 2016 thibaut trouve
*/

#include "my.h"

int	get_col_and_raw_max(int *col_max, char **argv)
{
  FILE          *stream;
  char          *line;
  size_t        len;
  ssize_t       read;
  int           i;

  line = NULL;
  len = 0;
  *col_max = 0;
  stream = fopen(argv[1], "r");
  if (stream == NULL)
    exit(84);
  i = 0;
  while ((read = getline(&line, &len, stream)) != -1)
    {
      if (my_strlen(line) > *col_max)
	*col_max = my_strlen(line);
      i++;
    }
  fclose(stream);
  return (i);
}
int	interpret_nb_p(int nb_p)
{
  if (nb_p != 1)
    {
      endwin();
      exit(84);
    }
  return (0);
}
int	*find_p(char **map)
{
  int   i;
  int   j;
  int   *pos;
  int   nb_p;

  nb_p = 0;
  i = 0;
  j = 0;
  pos = malloc(sizeof(int) * 2);
  if (pos == NULL)
    return (NULL);
  while (map[i] != NULL)
    {
      while (map[i][j] != '\0')
	{
	  if (map[i][j] == 'P')
	    stock_position(&nb_p, i, j, pos);
	  j++;
	}
      j = 0;
      i++;
    }
  interpret_nb_p(nb_p);
  return (pos);
}

int	count_o(char **map_o)
{
  int   i;
  int   j;
  int   nb_o;

  i = 0;
  j = 0;
  nb_o = 0;
  while (map_o[i] != NULL)
    {
      while (map_o[i][j] != '\0')
	{
	  if (map_o[i][j] == 'O')
	    nb_o++;
	  j++;
	}
      j = 0;
      i++;
    }
  return (nb_o);
}

int	free_memory(char **map, int type)
{
  int   i;

  usleep(100000);
  i = 0;
  while (map[i] != NULL)
    {
      free(map[i]);
      i++;
    }
  endwin();
  if (type == 0)
    return (0);
  else
    return (1);
  return (0);
}
