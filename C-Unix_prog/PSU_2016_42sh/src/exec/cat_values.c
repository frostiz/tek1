/*
** cat_values.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Tue May 16 22:19:07 2017 Lucas Dumy
** Last update Tue May 16 23:13:34 2017 Lucas Dumy
*/

#include	<stdlib.h>
#include	"mysh.h"

static void	fill_list(int *first_list, int *second_list, int *new_list)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  j = 0;
  while (first_list[i] != -1)
    {
      new_list[i] = first_list[i];
      i++;
    }
  while (second_list[j] != -1)
    {
      new_list[i + j] = second_list[j];
      j++;
    }
  new_list[i + j] = -1;
}

static int	*create_list(int *first_list, int *second_list)
{
  int		*new_list;
  unsigned int	i;
  unsigned int	j;

  i = 0;
  j = 0;
  while (first_list[i] != -1)
    i++;
  while (second_list[j] != -1)
    j++;
  new_list = malloc(sizeof(int) * (i + j + 1));
  if (new_list == NULL)
    return (NULL);
  return (new_list);
}

int		*cat_values(int *first_list, int *second_list)
{
  int		*new_list;

  if (first_list == NULL)
    return (second_list);
  new_list = create_list(first_list, second_list);
  if (new_list == NULL)
    return (NULL);
  fill_list(first_list, second_list, new_list);
  free(first_list);
  free(second_list);
  return (new_list);
}
