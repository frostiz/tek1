/*
** list.c for minishell1 in /home/dubret_v/delivery/Unix/PSU_2016_minishell1
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu@epitech.net>
** 
** Started on  Thu Jan 19 08:36:03 2017 dubret_v
** Last update Tue Mar 28 19:27:31 2017 dubret_v
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

t_elem	*free_list(t_elem *list)
{
  t_elem	*tmp;
  t_elem	*tmpnext;

  tmp = list;
  while (tmp != NULL)
    {
      tmpnext = tmp->next;
      free(tmp->value);
      free(tmp);
      tmp = tmpnext;
    }
  free(tmp);
  return (NULL);
}

int	len_list(t_elem *list)
{
  int		i;
  t_elem	*tmp;

  i = 0;
  tmp = list;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}

t_elem	*remove_elem(t_elem *list)
{
  t_elem	*tmp;
  t_elem	*ptmp;

  if (list == NULL)
    return (NULL);
  tmp = list;
  ptmp = list;
  while (tmp->next != NULL)
    {
      ptmp = tmp;
      tmp = tmp->next;
    }
  ptmp->next = NULL;
  free(tmp);
  return (list);
}

t_elem		*rmlist(t_elem *list, char *str)
{
  t_elem	*tmp;
  int		lenght;

  if (list == NULL)
    return (NULL);
  lenght = 0;
  while (list->value[lenght] != '\0')
    lenght++;
  if (my_strcmp(list->value, str) == 0)
    {
      tmp = list->next;
      free(list);
      tmp = rmlist(tmp, str);
      return (tmp);
    }
  else
    {
      list->next = rmlist(list->next, str);
      return (list);
    }
}
