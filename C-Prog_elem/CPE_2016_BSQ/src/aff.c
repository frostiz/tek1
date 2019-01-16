/*
** aff.c for aff.c in /home/frostiz/CPE_2016_BSQ
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Dec 14 19:33:10 2016 thibaut trouve
** Last update Sun Dec 18 17:04:01 2016 thibaut trouve
*/

#include "my.h"

void	aff(int *k, int *j, char buff_aff[BUF_SIZE])
{
  (*k)++;
  if (*k >= BUF_SIZE - 1)
    {
      write(1, buff_aff, *k);
      *k = 0;
    }
  (*j)++;
}

void	aff_loop(char **buf)
{
  int   i;
  int   j;
  int   k;
  char  buff_aff[BUF_SIZE];

  i = 0;
  j = 0;
  k = 0;
  while (buf[i] != NULL)
    {
      while (buf[i][j] != '\0')
	{
	  buff_aff[k] = buf[i][j];
	  aff(&k, &j, buff_aff);
	}
      buff_aff[k] = '\n';
      k++;
      j = 0;
      i++;
    }
  if (k < BUF_SIZE)
    write(1, buff_aff, k - 1);
}

void	replace_point(int j, int i, int max, char **tab)
{
  int   k;
  int   l;

  k = 0;
  l = 0;
  while (k < max)
    {
      while (l < max)
	{
	  tab[i][j + l] = 'x';
	  l++;
	}
      l = 0;
      i++;
      k++;
    }
}

void	aff_empty(char **tab)
{
  int	i;
  int	j;
  int	tmp;

  j = 0;
  i = 0;
  while (tab[i][j] != '\0')
    {
      i++;
      j++;
    }
  if (i < j)
    tmp = i;
  else
    tmp = j;
  replace_point(0, 0, tmp, tab);
  aff_loop(tab);
  exit(0);
}
