/*
** main.c for main.c in /home/roye_v/delivery/dante
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Wed Apr 12 12:27:51 2017 Vincent Roye
** Last update Sun May 14 20:13:05 2017 Thibaut Trouvé
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "generator.h"

static int	init_struct(t_maze *data, char **argv)
{
  data->width = atoi(argv[1]);
  data->height = atoi(argv[2]);
  if (data->height < 1 || data->width < 1)
    return (84);
  if (data->height * data->width <= 0)
    {
      printf("Ca overflow pas\n");
      return (84);
    }
  data->maze = malloc(sizeof(char) * data->width * data->height);
  if (data->maze == NULL)
    return (84);
  data->maze = memset(data->maze, '?', data->width * data->height);
  data->front_len = 0;
  return (0);
}

int	algo(t_maze *data, char **argv, int opt)
{
  if (opt == 1)
    {
      if (init_struct(data, argv) == 84)
	return (84);
      if (perfect_maze(data) == -1)
	algo(data, argv, 1);
    }
  else
    {
      if (init_struct(data, argv) == 84)
	return (84);
      if (imperfect(data) == -1)
	algo(data, argv, 0);
    }
  return (0);
}

int	generate_maze(int ac, char **argv)
{
  t_maze	*data;

  data = malloc(sizeof(t_maze));
  if (data == NULL)
    return (84);
  if (ac == 3)
    algo(data, argv, 0);
  else if (ac == 4 && strcmp(argv[3], "perfect") == 0)
    algo(data, argv, 1);
  else
    return (84);
  return (0);
}

int	main(int ac, char **argv)
{
  if (ac != 3 && ac != 4)
    {
      printf("Usage: ./generate x y [perfect]\n");
      return (84);
    }
  if (generate_maze(ac, argv) == 84)
    {
      printf("Error occurred\n");
      printf("Usage: ./generate x y [perfect]\n");
      return (84);
    }
  return (0);
}
