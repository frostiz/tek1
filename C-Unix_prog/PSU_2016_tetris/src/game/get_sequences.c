/*
** get_sequences.c for tetris in /home/thibaut/Repository/PSU_2016_tetris/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Mar 19 20:07:36 2017 
** Last update Sun Mar 19 20:09:55 2017 
*/

#include <stdlib.h>
#include "main.h"
#include "basic.h"

#define NB_KEYS 6

char	**get_sequences(t_keys key)
{
  char	**tab_seq;

  tab_seq = malloc(sizeof(char *) * (NB_KEYS + 1));
  if (tab_seq == NULL)
    return (NULL);
  if ((tab_seq[0] = strdup_(key.left)) == NULL ||
      (tab_seq[1] = strdup_(key.right)) == NULL ||
      (tab_seq[2] = strdup_(key.turn)) == NULL ||
      (tab_seq[3] = strdup_(key.drop)) == NULL ||
      (tab_seq[4] = strdup_(key.quit)) == NULL ||
      (tab_seq[5] = strdup_(key.pause)) == NULL)
    return (NULL);
  tab_seq[6] = NULL;
  return (tab_seq);
}
