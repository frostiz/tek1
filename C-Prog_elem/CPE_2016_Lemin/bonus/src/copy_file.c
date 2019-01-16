/*
** copy_file.c for lemin in /home/thibaut/Repository/CPE_2016_Lemin
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Thu Apr 13 20:28:30 2017 Thibaut Trouvé
** Last update Sun Apr 30 15:57:38 2017 dubret_v
*/

#include "gnl.h"
#include "lemin.h"
#include "my.h"

int	array_len(char **stock)
{
  int	i;

  i = 0;
  while (stock[i] != NULL)
    i++;
  return (i);
}

char	**realloc_tab(char **stock, char *str)
{
  char	**tmp;
  int	line;

  line = 0;
  tmp = malloc(sizeof(char *) * (array_len(stock) + 2));
  if (tmp == NULL)
    return (NULL);
  while (stock[line] != NULL)
    {
      tmp[line] = my_strdup(stock[line]);
      if (tmp[line] == NULL)
        return (NULL);
      free(stock[line]);
      line++;
    }
  free(stock);
  tmp[line] = my_strdup(str);
  if (tmp[line] == NULL)
    return (NULL);
  tmp[line + 1] = NULL;
  return (tmp);
}

char	**copy_file()
{
  char	*str;
  char	**stock;

  stock = malloc(sizeof(char *) * 1);
  stock[0] = NULL;
  while ((str = get_next_line(0)) != NULL)
    {
      stock = realloc_tab(stock, str);
      if (stock == NULL)
	return (NULL);
    }
  return (stock);
}
