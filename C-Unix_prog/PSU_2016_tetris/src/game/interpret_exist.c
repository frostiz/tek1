/*
** interpret_exist.c for tetris in /home/thibaut/Repository/PSU_2016_tetris
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Mar 19 21:59:30 2017 
** Last update Sun Mar 19 22:02:24 2017 
*/

#include <time.h>
#include "main.h"

void	interpret_exist(int exist, char **tab_seq,
			char **final_seq, t_datamap *game)
{
  int	first;

  first = 0;
  if (*final_seq[0] == '\0')
    first = 1;
  if (exist != 0)
    *final_seq[0] = '\0';
  else
    {
      if (first == 1)
	{
	  game->timeout = clock() / CLOCKS_PER_SEC;
	  first = 0;
	}
      if (clock() / CLOCKS_PER_SEC > game->timeout + 1)
	{
	  game->timeout = clock() / CLOCKS_PER_SEC + 1;
	  exist = is_sequence(final_seq, tab_seq);
	  *final_seq[0] = '\0';
	}
    }
  if (exist >= 1)
    interpret_sequence(exist, game);
}
