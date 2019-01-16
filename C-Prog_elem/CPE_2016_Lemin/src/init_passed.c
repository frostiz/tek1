/*
** init_passed.c for Lemin in /home/dubret_v/delivery/semestre2/CPE/CPE_2016_Lemin
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Thu Apr 27 14:30:12 2017 dubret_v
** Last update Sun Apr 30 21:53:41 2017 dubret_v
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

static	t_ever_passed	*create_new_elem(char **tab, char *name)
{
  t_ever_passed		*new_elem;
  int			i;
  int			len;

  new_elem = malloc(sizeof(t_ever_passed));
  if (new_elem == NULL)
    return (NULL);
  i = 1;
  len = array_len(tab);
  new_elem->room_name = my_strdup(name);
  new_elem->is_passed = malloc(sizeof(char *) * (len + 2));
  if (new_elem->is_passed == NULL)
    return (NULL);
  new_elem->next = NULL;
  new_elem->is_passed[0] = my_strdup(name);
  while (i < len + 2)
    {
      new_elem->is_passed[i] = NULL;
      i++;
    }
  return (new_elem);
}

static	t_ever_passed	*connect(t_ever_passed *stru1, t_ever_passed *stru2)
{
  stru2->next = stru1;
  return (stru2);
}

void		add_new_name(char **tab, char *name)
{
  int			i;

  i = 0;
  while (tab[i] && my_strcmp(tab[i], name))
    i++;
  if (tab[i] == NULL)
    tab[i] = my_strdup(name);
}

t_ever_passed		*init_passed(t_ever_passed *passed, char **tab,
				     char *name, char *dest)
{
  t_ever_passed		*tmp;

  if (passed == NULL)
    {
      passed = create_new_elem(tab, name);
      return (passed);
    }
  else
    {
      tmp = passed;
      while (tmp && my_strcmp(tmp->room_name, name) != 0)
	tmp = tmp->next;
      if (tmp == NULL)
	{
	  passed = connect(passed, create_new_elem(tab, name));
	  if (my_strcmp(name, dest) != 0)
	    passed->is_passed[1] = my_strdup(dest);
	}
      else
	add_new_name(passed->is_passed, dest);
    }
  return (passed);
}
