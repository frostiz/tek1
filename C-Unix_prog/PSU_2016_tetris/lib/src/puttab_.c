/*
** puttab_.c for  in /home/sahel/rendu/PSU/PSU_2016_bstetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Tue Feb 21 09:25:43 2017 Sahel
** Last update Tue Feb 21 09:38:26 2017 Sahel
*/

#include "basic.h"

void	puttab_(char **tab, int fd)
{
  int	tab_i;

  tab_i = 0;
  while (tab[tab_i])
    {
      putstr_(tab[tab_i], fd);
      putstr_("\n", fd);
      tab_i++;
    }
}
