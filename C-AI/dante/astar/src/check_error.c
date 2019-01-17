/*
** check_error.c for check_error.c in /home/roye_v/delivery/dante/astar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 14 03:04:18 2017 Vincent Roye
** Last update Sun May 14 16:20:31 2017 Vincent Roye
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"astar.h"

int		check_wrong_arg(char **maze)
{
  int		i;
  int		line;

  line = 0;
  i = 0;
  while (maze[line] != NULL)
    {
      while (maze[line][i] != '\0')
	{
	  if (maze[line][i] != 'X' &&
	      maze[line][i] != '*' &&
	      maze[line][i] != '\n')
	    return (1);
	  i++;
	}
      i = 0;
      line++;
    }
  return (0);
}

int		no_rectangular(char **maze)
{
  int		line;
  size_t	max;

  max = strlen(maze[0]);
  line = 0;
  while (maze[line] != NULL)
    {
      if (strlen(maze[line]) != max)
	return (1);
      line++;
    }
  return (0);
}

int		check_error(char **maze)
{
  if (check_wrong_arg(maze) == 1)
    {
      fprintf(stderr, "bad character.\n");
      exit(84);
    }
  if (no_rectangular(maze) == 1)
    {
      fprintf(stderr, "Maze no rectangular.\n");
      exit(84);
    }
  return (0);
}
