/*
** tmp.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
**
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
**
** Started on  Sun May 21 19:19:42 2017 bastien bedu
** Last update Sun May 21 22:53:44 2017 Lucas Dumy
*/

#include	<stdlib.h>
#include	<string.h>

int		end_word(char *str, int i, int nb, int *status)
{
  *status = 0;
  str[i] = '\0';
  return (nb + 1);
}

static	int	init_values(int *status, int *i, char *quote)
{
  *status = 0;
  *i = 0;
  *quote = 0;
  return (1);
}

int		cut_at(char *str, char c)
{
  int		i;
  int		nb;
  int		status;
  char		quote;

  nb = init_values(&status, &i, &quote);
  while (str[i] != '\0')
    {
      if (quote != 0)
	{
	  if (quote == str[i])
	    quote = 0;
	}
      else if (str[i] == c && status == 1)
	nb = end_word(str, i, nb, &status);
      else if (str[i] != c)
	status = 1;
      if (str[i] == '\"' || (c != '`' && str[i] == '`'))
	quote = str[i];
      i++;
    }
  if (status == 0)
    nb--;
  return (nb);
}

void		fill_tab(char **tab, int nb, char *str, int i)
{
  int		j;

  j = 1;
  while (tab != NULL && nb > j)
    {
      if (str[i] == '\0')
	{
	  tab[j] = strdup(&str[i + 1]);
	  j++;
	}
      i++;
    }
}

char		**my_split(char *str, char c)
{
  char		**tab;
  int		nb;
  int		i;

  if (str == NULL)
    return (NULL);
  str = strdup(str);
  if (str == NULL)
    return (NULL);
  nb = cut_at(str, c);
  tab = malloc(sizeof(char *) * (nb + 1));
  if (tab != NULL)
    tab[nb] = NULL;
  i = 0;
  while (str[i] == c)
    i++;
  if (tab != NULL && nb != 0)
    tab[0] = strdup(&str[i]);
  fill_tab(tab, nb, str, i);
  free(str);
  return (tab);
}
