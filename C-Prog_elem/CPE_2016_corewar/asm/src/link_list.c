/*
** link_list.c for link_list.c in /home/roye_v/delivery/CPE_2016/CPE_2016_corewar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue Mar 28 20:28:53 2017 Vincent Roye
** Last update Thu Mar 30 20:36:56 2017 Vincent Roye
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"

void		display_list(t_elem *list)
{
  t_elem	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->value);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

void		display_label(t_label *list)
{
  t_label	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_printf("%s\n", tmp->value);
      my_printf("%d\n", tmp->line);
      tmp = tmp->next;
    }
}

t_elem		*addlist(t_elem *list, char *str)
{
  t_elem	*new_elem;
  t_elem	*tmp;

  new_elem = malloc(sizeof(t_elem));
  if (new_elem == NULL)
    return (NULL);
  tmp = list;
  new_elem->value = my_strdup(str);
  new_elem->next = NULL;
  if (list == NULL)
    return (new_elem);
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new_elem;
      return (list);
    }
}

t_label		*addlabel(t_label *list, char *str, int i)
{
  t_label	*new_elem;
  t_label	*tmp;

  new_elem = malloc(sizeof(t_label));
  if (new_elem == NULL)
    return (NULL);
  tmp = list;
  new_elem->value = my_strdup(str);
  new_elem->line = i;
  new_elem->next = NULL;
  if (list == NULL)
    return (new_elem);
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new_elem;
      return (list);
    }
}
