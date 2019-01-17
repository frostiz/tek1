/*
** get_data.c for get_data.c in /home/roye_v/delivery/maze_solver
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Thu May 11 21:02:35 2017 Vincent Roye
** Last update Sun May 14 21:11:24 2017 Vincent Roye
*/

#include	<string.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<string.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	"breadth.h"

int		array_len(char **stock)
{
  int		line;

  line = 0;
  while (stock[line] != NULL)
    {
      line++;
    }
  return (line);
}

static void	get_exit()
{
  fprintf(stderr, "Invalid file name.\n");
  exit(84);
}

int		get_maze_height(char *file)
{
  FILE		*fd;
  char		*str;
  size_t	len;
  int		size;

  str = NULL;
  len = 0;
  size = 0;
  fd = fopen(file, "r");
  if (fd == NULL)
    return (-1);
  while ((getline(&str, &len, fd)) != -1)
    size++;
  if (size == 0)
    {
      fprintf(stderr, "Empty file.\n");
      exit(84);
    }
  return (size);
}

static void	init_values(int *line, size_t *len)
{
  *line = 0;
  *len = 0;
}

char		**stock_file(char *file, t_coord *coord)
{
  char		**maze;
  char		*str;
  int		line;
  size_t	len;
  FILE		*fd;

  init_values(&line, &len);
  str = NULL;
  fd = fopen(file, "r");
  if (fd == NULL)
    get_exit();
  if ((maze = malloc(sizeof(char *) * (get_maze_height(file) + 1))) == NULL)
    exit(84);
  while ((getline(&str, &len, fd)) != -1)
    {
      if (str[strlen(str) - 1] == '\n')
	str[strlen(str) - 1] = '\0';
      maze[line] = strdup(str);
      line++;
    }
  if ((maze[line] = malloc(sizeof(char *))) == NULL)
    exit(84);
  maze[line] = NULL;
  check_error(maze, coord);
  return (maze);
}
