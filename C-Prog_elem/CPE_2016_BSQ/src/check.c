/*
** check.c for check.c in /home/frostiz/CPE_2016_BSQ
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Dec 14 19:41:04 2016 thibaut trouve
** Last update Sun Dec 18 17:02:57 2016 thibaut trouve
*/

#include "my.h"

int	check_square(char **tab, int i, int j, int m)
{
  int   k;
  int   l;

  k = 0;
  l = 0;
  while (k <= m)
    {
      while (l <= m)
	{
	  if (tab[i][j + l] != '.' || tab[i][j + l] == '\0')
	    return (-1);
	  l++;
	}
      l = 0;
      i++;
      k++;
    }
  return (0);
}

int	check(char **tab, int i, int j)
{
  int   m;

  m = 0;
  while (tab[i + m][j] == '.' && tab[i][j + m] == '.')
    {
      if (check_square(tab, i, j, m) == -1)
	return (m);
      m++;
    }
  return (m);
}

int	check_empty(char **tab)
{
  int   i;
  int   j;
  int	empty;

  empty = 1;
  i = 0;
  j = 0;
  while (tab[i] != NULL)
    {
      while (tab[i][j] != '\0')
        {
          if (tab[i][j] != '.')
            empty = 0;
          j++;
	}
      i++;
      j = 0;
    }
  if (empty == 1)
    {
      aff_empty(tab);
      exit(0);
    }
  return (0);
}

