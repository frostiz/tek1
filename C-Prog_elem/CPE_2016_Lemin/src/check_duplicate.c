/*
** check_duplicate.c for lemin in /home/thibaut/Repository/CPE_2016_Lemin
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Apr 30 21:39:32 2017 Thibaut Trouvé
** Last update Sun Apr 30 21:44:38 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

t_dup	*add_duplicate(t_dup *dup, char *name, char *with)
{
  t_dup	*new;

  new = malloc(sizeof(t_dup));
  if (new == NULL)
    return (NULL);
  if (dup == NULL)
    new->next = NULL;
  else
    new->next = dup;
  new->duplicate = malloc(sizeof(char *) * 3);
  if (new->duplicate == NULL)
    return (NULL);
  new->duplicate[0] = my_strdup(name);
  if (new->duplicate[0] == NULL)
    return (NULL);
  new->duplicate[1] = my_strdup(with);
  if (new->duplicate[1] == NULL)
    return (NULL);
  new->duplicate[2] = NULL;
  return (new);
}

int	is_duplicate(char *name, char *with, t_dup *dup)
{
  t_dup	*tmp;

  tmp = dup;
  while (tmp != NULL)
    {
      if (my_strcmp(name, tmp->duplicate[0]) == 0 &&
          my_strcmp(with, tmp->duplicate[1]) == 0)
	return (1);
      else if (my_strcmp(name, tmp->duplicate[1]) == 0 &&
	       my_strcmp(with, tmp->duplicate[0]) == 0)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}
