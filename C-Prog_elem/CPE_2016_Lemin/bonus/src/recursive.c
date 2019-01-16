/*
** recursive.c for Lemin in /home/dubret_v/delivery/semestre2/CPE/CPE_2016_Lemin
**
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
**
** Started on  Tue Apr 25 11:35:22 2017 dubret_v
** Last update Sun Apr 30 19:16:08 2017 Vincent Roye
*/

#include <stdio.h>
#include <stdlib.h>
#include "lemin.h"
#include "my.h"

static	t_path	*init_paths()
{
  t_path	*paths;

  paths = malloc(sizeof(t_path));
  if (paths == NULL)
    return (NULL);
  paths->path = NULL;
  paths->over = 0;
  paths->next = NULL;
  return (paths);
}

void		print_paths(t_path *paths)
{
  t_path	*tmp;

  tmp = paths;
  while (tmp != NULL)
    {
      print_tab(tmp->path);
      my_printf("-------------\n");
      tmp = tmp->next;
    }
}

void	print_ants(char **path, int i, int nb_ants, int *coef)
{
  int	j;

  j = i - *coef;
  if (i >= (array_len(path)))
    *coef += 1;
  while (j >= 0)
    {
      if (i - j <= nb_ants && (j == 0))
	my_printf("P%d-%s", i - j, path[j]);
      else if (i - j <= nb_ants)
	{
	  my_printf("P%d-%s", i - j, path[j]);
	}
      j--;
      if (i - j <= nb_ants && j >= 0)
	my_printf(" ");
    }
}

void	display_moves(char **path, int nb_ants)
{
  int	i;
  int	coef;

  i = 1;
  coef = 1;
  while (i < nb_ants + array_len(path))
    {
      print_ants(path, i, nb_ants, &coef);
      my_printf("\n");
      i++;
    }
}

int		recursive_functions(t_map *graph, int nb_ants)
{
  t_name_path	path;
  t_path	*paths;

  path.name = NULL;
  path.path = NULL;
  paths = init_paths();
  if (paths == NULL)
    return (-1);
  paths = search_path(graph, path, paths, NULL);
  if (paths == NULL)
    return (-1);
  if (paths->over != 1)
    {
      my_put_error("No good path\n");
      return (-1);
    }
  display_moves(paths->path, nb_ants);
  return (0);
}
