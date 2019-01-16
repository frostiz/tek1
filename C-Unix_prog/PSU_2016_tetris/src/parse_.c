/*
** parse_.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris/src/flags
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Wed Mar  1 20:54:38 2017 Sahel
** Last update Sun Mar 19 20:58:40 2017 Sahel
*/

#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include "basic.h"

char	**parse_(char *str, char c)
{
  char	**tab;
  int	tab_i;
  int	tab_i_i;
  int	str_i;

  tab_i = 0;
  str_i = 0;
  if (!str || !*str || !(tab = malloc(sizeof(char *) * (strlen_(str) + 1))))
    return (NULL);
  while (str[str_i])
    {
      tab_i_i = 0;
      if (!(tab[tab_i] = malloc(sizeof(char) * strlen_(str) + 1)))
	return (NULL);
      while (str[str_i] && str[str_i] == c)
	str_i++;
      while (str[str_i] && str[str_i] != c)
	tab[tab_i][tab_i_i++] = str[str_i++];
      tab[tab_i++][tab_i_i] = '\0';
    }
  tab[tab_i] = NULL;
  return (tab);
}
