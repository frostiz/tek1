/*
** show_map.c for Navy in /home/thibaut/Repository/PSU_2016_navy/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Feb 15 17:38:57 2017 
** Last update Sun Feb 19 18:38:42 2017 
*/

#include "my.h"

void	aff_map(char **tab)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  my_putstr(" |A B C D E F G H\n");
  my_putstr("-+---------------\n");
  while (tab[i] != NULL)
    {
      my_put_nbr(i + 1);
      my_putchar('|');
      while (tab[i][j] != '\0')
	{
	  my_putchar(tab[i][j]);
	  if (j < 7)
	    my_putchar(' ');
	  j++;
	}
      my_putchar('\n');
      i++;
      j = 0;
    }
  my_putchar('\n');
}

void	show_map(char **tab, char **enemy_tab)
{
  my_putstr("my positions:\n");
  aff_map(tab);
  my_putstr("enemy's positions:\n");
  aff_map(enemy_tab);
}
