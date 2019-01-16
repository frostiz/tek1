/*
** move.c for move.c in /home/frostiz/PSU_2016_my_sokoban
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Fri Dec 16 12:25:39 2016 thibaut trouve
** Last update Mon Dec 19 15:33:53 2016 thibaut trouve
*/

#include "my.h"

void	move_right(char **map, int *pos, char **map_o)
{
  if (map[pos[0]][pos[1] + 1] == 'X' && map[pos[0]][pos[1] + 2] == ' ')
    swap(&(map[pos[0]][pos[1] + 1]), &(map[pos[0]][pos[1] + 2]));
  else if (map[pos[0]][pos[1] + 1] == 'X' && map[pos[0]][pos[1] + 2] == 'O')
    swap(&(map[pos[0]][pos[1] + 2]), &(map[pos[0]][pos[1] + 1]));
  if (map[pos[0]][pos[1] + 1] != 'X' && map[pos[0]][pos[1] + 1] != '\n' &&
      map[pos[0]][pos[1] + 1] != '#' && map[pos[0]][pos[1] + 1] != '\0' )
    {
      if (map[pos[0]][pos[1] + 1] == 'O')
	map[pos[0]][pos[1] + 1] = ' ';
      swap(&(map[pos[0]][pos[1] + 1]), &(map[pos[0]][pos[1]]));
      pos[1] += 1;
    }
  if (map_o[pos[0]][pos[1] - 1] == 'O')
    map[pos[0]][pos[1] - 1] = 'O';
}

void	move_down(char **map, int *pos, char **map_o)
{
  if (map[pos[0] + 1][pos[1]] == 'X' && map[pos[0] + 2][pos[1]] == ' ')
    swap(&(map[pos[0] + 2][pos[1]]), &(map[pos[0] + 1][pos[1]]));
  else if (map[pos[0] + 1][pos[1]] == 'X' && map[pos[0] + 2][pos[1]] == 'O')
    swap(&(map[pos[0] + 2][pos[1]]), &(map[pos[0] + 1][pos[1]]));
  if (map[pos[0] + 1][pos[1]] != '#' && map[pos[0] + 1][pos[1]] != 'X' &&
      map[pos[0] + 1][pos[1]] != '\0' && map[pos[0] + 1][pos[1]] != '\n')
    {
      if (map[pos[0] + 1][pos[1]] == 'O')
	map[pos[0] + 1][pos[1]] = ' ';
      swap(&(map[pos[0]][pos[1]]), &(map[pos[0] + 1][pos[1]]));
      pos[0] += 1;
    }
  if (map_o[pos[0] - 1][pos[1]] == 'O')
    map[pos[0] - 1][pos[1]] = 'O';
}

void	move_left(char **map, int *pos, char **map_o)
{
  if (map[pos[0]][pos[1] - 1] == 'X' && map[pos[0]][pos[1] - 2] == ' ')
    swap(&(map[pos[0]][pos[1] - 2]), &(map[pos[0]][pos[1] - 1]));
  else if (map[pos[0]][pos[1] - 1] == 'X' && map[pos[0]][pos[1] - 2] == 'O')
    swap(&(map[pos[0]][pos[1] - 2]), &(map[pos[0]][pos[1] - 1]));
  if (map[pos[0]][pos[1] - 1] != '#' && map[pos[0]][pos[1] - 1] != 'X' &&
      map[pos[0]][pos[1] - 1] != '\0' && map[pos[0]][pos[1] - 1] != '\n')
    {
      if (map[pos[0]][pos[1] - 1] == 'O')
	map[pos[0]][pos[1] - 1] = ' ';
      swap(&(map[pos[0]][pos[1]]), &(map[pos[0]][pos[1] - 1]));
      pos[1] -= 1;
    }
  if (map_o[pos[0]][pos[1] + 1] == 'O')
    map[pos[0]][pos[1] + 1] = 'O';
}

void	move_up(char **map, int *pos, char **map_o)
{
  if (map[pos[0] - 1][pos[1]] == 'X' && map[pos[0] - 2][pos[1]] == ' ')
    swap(&(map[pos[0] - 2][pos[1]]), &(map[pos[0] - 1][pos[1]]));
  else if (map[pos[0] - 1][pos[1]] == 'X' && map[pos[0] - 2][pos[1]] == 'O')
    swap(&(map[pos[0] - 2][pos[1]]), &(map[pos[0] - 1][pos[1]]));
  if (map[pos[0] - 1][pos[1]] != '#' && map[pos[0] - 1][pos[1]] != 'X' &&
      map[pos[0] - 1][pos[1]] != '\0' && map[pos[0] - 1][pos[1]] != '\n')
    {
      if (map[pos[0] - 1][pos[1]] == 'O')
	map[pos[0] - 1][pos[1]] = ' ';
      swap(&(map[pos[0]][pos[1]]), &(map[pos[0] - 1][pos[1]]));
      pos[0] -= 1;
    }
  if (map_o[pos[0] + 1][pos[1]] == 'O')
    map[pos[0] + 1][pos[1]] = 'O';
}

