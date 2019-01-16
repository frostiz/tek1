/*
** my_show_wordtab.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Mon May 15 09:57:16 2017 Lucas Dumy
** Last update Mon May 15 10:03:43 2017 Lucas Dumy
*/

#include	<stdlib.h>
#include	"mysh.h"

void		my_show_wordtab(char **tab)
{
  unsigned int	i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putstr("\n");
      i++;
    }
}
