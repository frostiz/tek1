/*
** sequences.c for tetris in /home/thibaut/Repository/PSU_2016_tetris
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri Mar 10 17:12:12 2017 
** Last update Sun Mar 19 20:11:19 2017 
*/

#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include "main.h"
#include "basic.h"

#define KEY_PRESSED_READ_SIZE 10
#define NB_KEYS 6

int	interpret_sequence(int exist, t_datamap *game)
{
  if (exist == 1 && game->pause == 0)
    move_left(game);
  if (exist == 2 && game->pause == 0)
    move_right(game);
  if (exist == 3)
    turn(game);
  if (exist == 6)
    game->pause = (game->pause == 0) ? (1) : (0);
  return (0);
}

int	find_key_pressed(char **tab_seq, char *final_seq)
{
  int	i;

  i = 0;
  while (tab_seq[i] != NULL)
    {
      if (strcmp_(tab_seq[i], final_seq) == 0)
	return (i + 1);
      i++;
    }
  return (0);
}

int	is_sequence(char **final_seq, char **tab_seq)
{
  int	i;

  i = 0;
  while (tab_seq[i] != NULL)
    {
      if (strcmp_(*final_seq, tab_seq[i]) == 0)
	return (i + 1);
      i++;
    }
  return (-1);
}

int	check_sequence_validity(char *final_seq, char **tab_seq)
{
  int	nb_sol;
  int	i;

  nb_sol = 0;
  i = 0;
  while (tab_seq[i] != NULL)
    {
      if (strncmp_(tab_seq[i], final_seq, strlen_(final_seq) - 1) == 0)
	nb_sol++;
      i++;
    }
  if (nb_sol <= 0)
    return (-1);
  else if (nb_sol == 1)
    return (find_key_pressed(tab_seq, final_seq));
  return (0);
}

char	*cat_key_pressed(char **final_seq)
{
  int	size;
  char	seq_read[KEY_PRESSED_READ_SIZE];

  size = KEY_PRESSED_READ_SIZE;
  while (size <= KEY_PRESSED_READ_SIZE && size > 0)
    {
      size = read(0, seq_read, KEY_PRESSED_READ_SIZE);
      seq_read[size] = '\0';
      *final_seq = realloc_(*final_seq, strlen_(*final_seq) + 1
                            + strlen_(seq_read));
      if (*final_seq == NULL)
	return (NULL);
      strcat_(*final_seq, seq_read);
    }
  return (*final_seq);
}
