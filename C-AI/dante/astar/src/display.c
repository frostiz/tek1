/*
** display.c for display.c in /home/roye_v/delivery/dante/astar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 14 03:02:55 2017 Vincent Roye
** Last update Sun May 14 15:36:06 2017 Vincent Roye
*/

#include	<stdio.h>
#include	"astar.h"

void		print_tab(char **stock)
{
  int		line;

  line = 0;
  while (stock[line] != '\0')
    {
      printf("stock[%d] = [%s]\n", line, stock[line]);
      line++;
    }
}

void		print_map(char **stock)
{
  int		line;
  int		i;

  i = 0;
  line = 0;
  while (stock[line] != NULL)
    {
      while (stock[line][i] != '\0')
	{
	  if (stock[line][i] == 'o')
	    printf("\033[32;40m%c\033[0m", '*');
	  else if (stock[line][i] == 'X')
	    printf("%c", 'X');
	  else
	    printf("%c", '*');
	  i++;
	}
      printf("\n");
      i = 0;
      line++;
    }
  printf("\n");
}

void		write_tab(char **stock)
{
  int		line;
  int		i;

  i = 0;
  line = 0;
  while (stock[line] != NULL)
    {
      while (stock[line][i] != '\0')
	{
	  if (stock[line][i] == 'o')
	    printf("o");
	  else if (stock[line][i] == 'X')
	    printf("%c", 'X');
	  else
	    printf("%c", '*');
	  i++;
	}
      i = 0;
      line++;
      if (stock[line] != NULL)
	printf("\n");
    }
}

void		print_final_tab(char **maze, int f_line, int f_col)
{
  while (maze[f_line][f_col] != 'o')
    {
      if (maze[f_line][f_col] == 'L')
	{
	  maze[f_line][f_col] = 'o';
	  f_col--;
	}
      else if (maze[f_line][f_col] == 'N')
	{
	  maze[f_line][f_col] = 'o';
	  f_line--;
	}
      else if (maze[f_line][f_col] == 'S')
	{
	  maze[f_line][f_col] = 'o';
	  f_line++;
	}
      else if (maze[f_line][f_col] == 'R')
	{
	  maze[f_line][f_col] = 'o';
	  f_col++;
	}
    }
  write_tab(maze);
}
