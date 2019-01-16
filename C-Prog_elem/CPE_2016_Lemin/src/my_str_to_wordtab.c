/*
** my_str_to_wordtab.c for my_str_to_wortab.c in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr 30 15:35:48 2017 Vincent Roye
** Last update Sun Apr 30 19:11:41 2017 Vincent Roye
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "lemin.h"

int	nb_words(char *str)
{
  int	i;
  int	nb;

  nb = 1;
  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9') &&
	  (str[i] < 'A' || str[i] > 'Z') &&
	  (str[i] < 'a' || str[i] > 'z') &&
	  str[i] != '\0')
	{
	  while ((str[i] < '0' || str[i] > '9') &&
		 (str[i] < 'A' || str[i] > 'Z') &&
		 (str[i] < 'a' || str[i] > 'z') &&
		 str[i] != '\0')
	    i++;
	  nb++;
	  i--;
	}
      i++;
    }
  return (nb);
}

static int	alpha_numeric(char *str, int i)
{
  if (((str[i] >= '0' && str[i] <= '9') ||
       (str[i] >= 'A' && str[i] <= 'Z') ||
       (str[i] >= 'a' && str[i] <= 'z')) &&
      (str[i] != '\0'))
    return (0);
  return (1);
}

static int	init_values(t_wordtab *wt, char *str)
{
  wt->i = 0;
  wt->j = 0;
  wt->k = 0;
  wt->tab = malloc(sizeof(char *) * (nb_words(str) + 1));
  if (wt->tab == NULL)
    return (1);
  return (0);
}

static void	new_line(t_wordtab *wt)
{
  wt->tab[wt->k][wt->j] = '\0';
  (wt->k)++;
  (wt->i)--;
}

char		**my_str_to_wordtab(char *str)
{
  t_wordtab	wt;

  if (init_values(&wt, str) == 1)
    return (NULL);
  while (str[wt.i] != '\0')
    {
      wt.j = 0;
      if (alpha_numeric(str, wt.i) == 0)
	{
	  wt.tab[wt.k] = malloc(sizeof(char) * my_strlen(&str[wt.i]) + 1);
	  if (wt.tab[wt.k] == NULL)
	    return (NULL);
	  while (alpha_numeric(str, wt.i) == 0)
	    {
	      wt.tab[wt.k][wt.j] = str[wt.i];
	      (wt.j)++;
	      (wt.i)++;
	    }
	  new_line(&wt);
	}
      wt.i++;
    }
  wt.tab[wt.k] = NULL;
  return (wt.tab);
}
