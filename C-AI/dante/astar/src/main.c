/*
** main.c for main.c in /home/roye_v/delivery/dante/solver
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May  7 23:12:04 2017 Vincent Roye
** Last update Sun May 14 22:37:30 2017 Vincent Roye
*/

#include	<fcntl.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"astar.h"

static void	get_exit()
{
  fprintf(stderr, "Invalid file name.\n");
  exit(84);
}

int		get_map_size(char *file)
{
  FILE		*fd;
  int		line;
  char		*str;
  size_t	len;

  str = NULL;
  line = 0;
  len = 0;
  fd = fopen(file, "r");
  if (fd == NULL)
    get_exit();
  while ((getline(&str, &len, fd)) != -1)
    line++;
  if (line == 0)
    {
      fprintf(stderr, "Empty file.\n");
      exit(84);
    }
  return (line);
}

char		**get_data(char *file)
{
  FILE		*fd;
  char		**maze;
  char		*str;
  int		line;
  size_t	len;

  line = 0;
  str = NULL;
  len = 0;
  maze = malloc(sizeof(char *) * (get_map_size(file) + 1));
  if (maze == NULL)
    exit(84);
  fd = fopen(file, "r");
  while ((getline(&str, &len, fd)) != -1)
    {
      if (str[strlen(str) - 1] == '\n')
	str[strlen(str) - 1] = '\0';
      maze[line] = strdup(str);
      line++;
    }
  maze[line] = malloc(sizeof(char *));
  if (maze[line] == NULL)
    exit(84);
  maze[line] = NULL;
  return (maze);
}

int		main(int ac, char **argv)
{
  t_pos		*pos;

  pos = malloc(sizeof(t_pos));
  if (pos == NULL)
    exit(84);
  pos->line = 0;
  pos->col = 0;
  if (ac != 2)
    {
      fprintf(stderr, "Usage: ./solver [map].\n");
      exit(84);
    }
  pos->maze = get_data(argv[1]);
  check_error(pos->maze);
  astar(pos);
  return (0);
}
