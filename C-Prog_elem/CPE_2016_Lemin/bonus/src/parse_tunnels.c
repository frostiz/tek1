/*
** parse_tunnels.c for lemin in /home/thibaut/Repository/CPE_2016_Lemin
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sat Apr 29 22:30:11 2017 Thibaut Trouvé
** Last update Sun Apr 30 21:46:38 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

static int	is_tunnel(char **stock, int *idx)
{
  int	i;
  int	space;
  int	dash;

  while (stock[*idx] != NULL)
    {
      i = 0;
      space = 0;
      dash = 0;
      if (stock[*idx][0] != '\0')
	{
	  while (stock[*idx][i] != '\0')
	    {
	      if (stock[*idx][i] == ' ' || stock[*idx][i] == '\t')
		space++;
	      else if (stock[*idx][i] == '-')
		dash++;
	      i++;
	    }
	  return (my_strlen(stock[*idx]) >= 3 &&
		  dash == 1 && space == 0 ? 1 : -1);
	}
      (*idx)++;
    }
  return (-1);
}

t_rooms	*get_tunnels(t_rooms *rooms, char **stock, int *idx, int idx_error)
{
  t_rooms	*tmp;

  tmp = rooms;
  while (tmp != NULL)
    {
      tmp->tunnel = stock_tunnel2(stock, *idx, tmp->data->name, idx_error);
      if (tmp->tunnel == NULL)
	return (rooms);
      tmp = tmp->next;
    }
  return (rooms);
}

void	display_tunnels(t_rooms *rooms)
{
  t_rooms	*tmp;
  int		i;
  t_dup	*dup;

  dup = malloc(sizeof(t_dup));
  if (dup == NULL)
    return ;
  dup = NULL;
  tmp = rooms;
  while (tmp != NULL && tmp->tunnel != NULL)
    {
      i = 0;
      while (tmp->tunnel[i] != NULL)
	{
	  if (is_duplicate(tmp->data->name, tmp->tunnel[i], dup) == 0)
	    {
	      dup = add_duplicate(dup, tmp->data->name, tmp->tunnel[i]);
	      my_printf("%s-%s\n", tmp->data->name, tmp->tunnel[i]);
	    }
	  i++;
	}
      tmp = tmp->next;
    }
}

int	check_end_tunnel(t_rooms *rooms)
{
  t_rooms	*tmp;

  tmp = rooms;
  while (tmp != NULL)
    {
      if (tmp->data->pos == END ||
	  tmp->data->pos == START)
	{
	  if (tmp->tunnel == NULL)
	    {
	      my_put_error("No tunnel with start // end room(s)\n");
	      return (-1);
	    }
	  else if (tmp->tunnel[0] == NULL)
	    {
	      my_put_error("No tunnel with start // end room(s)\n");
	      return (-1);
	    }
	}
      tmp = tmp->next;
    }
  return (0);
}

t_rooms	*parse_tunnels(t_rooms *rooms, char **stock, int *idx)
{
  int	idx_error;

  my_printf("#tunnels\n");
  if (is_tunnel(stock, idx) == -1)
    return (NULL);
  idx_error = get_idx_error(stock, *idx, rooms);
  rooms = get_tunnels(rooms, stock, idx, idx_error);
  if (rooms == NULL)
    return (NULL);
  display_tunnels(rooms);
  return (rooms);
}
