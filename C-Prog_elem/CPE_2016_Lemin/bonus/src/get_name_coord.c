/*
** get_name_coord.c for lemin in /home/thibaut/Repository/CPE_2016_Lemin
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Thu Apr 13 21:19:02 2017 Thibaut Trouvé
** Last update Sun Apr 30 23:35:35 2017 Vincent Roye
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return ;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

static int	stock_data(t_dataroom *data, char **tab, int idx)
{
  char		**tmp;

  if (tab[idx] == NULL)
    return (-1);
  tmp = my_str_to_wordtab(tab[idx]);
  if (tmp == NULL)
    return (-1);
  if (array_len(tmp) != 3)
    {
      free_tab(tmp);
      return (-1);
    }
  data->name = my_strdup(tmp[0]);
  if (data->name == NULL)
    return (-1);
  data->x = my_getnbr(tmp[1]);
  data->y = my_getnbr(tmp[2]);
  free_tab(tmp);
  return (0);
}

static void	check_pos(char **tab, int *idx, t_dataroom *data)
{
  while (my_strncmp(tab[*idx], "##start", 7) == 0 && tab[*idx])
    {
      data->pos = START;
      (*idx)++;
    }
  while (my_strncmp(tab[*idx], "##end", 5) == 0 && tab[*idx])
    {
      data->pos = END;
      (*idx)++;
    }
}

t_dataroom	*get_data(char **tab, int *idx)
{
  t_dataroom	*data;

  data = malloc(sizeof(t_dataroom));
  if (data == NULL)
    return (NULL);
  data->name = NULL;
  data->pos = 0;
  data->x = 0;
  data->y = 0;
  while (tab[*idx] != NULL)
    {
      if (tab[*idx][0] != '\0')
	{
	  check_pos(tab, idx, data);
	  if (stock_data(data, tab, *idx) == -1)
	    return (NULL);
	  (*idx)++;
	  return (data);
	}
      (*idx)++;
    }
  return (NULL);
}
