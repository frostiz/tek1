/*
** list.c for  in /home/sahel/rendu/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Mar 18 16:26:02 2017 Sahel
** Last update Sat Mar 18 16:52:36 2017 Sahel
*/

#include <unistd.h>
#include "main.h"

void		stock_in_list(t_datamap *game, t_tetriminos *tetri)

{
  t_tetriminos	*tmp;

  if (!game->tetriminos)
    {
      tetri->next = NULL;
      tetri->previous = NULL;
      game->tetriminos = tetri;
    }
  else
    {
      tmp = game->tetriminos;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = tetri;
      tetri->next = NULL;
      tetri->previous = tmp;
    }
}

void		list_circu(t_datamap *game)
{
  t_tetriminos	*tetri;

  if (!game->tetriminos)
    return ;
  tetri = game->tetriminos;
  while (game->tetriminos->next)
    game->tetriminos = game->tetriminos->next;
  game->tetriminos->next = tetri;
  game->tetriminos = game->tetriminos->next;
}
