/*
** search_path.c for lemin in /home/dubret_v/delivery/semestre2/CPE/CPE_2016_Lemin
**
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
**
** Started on  Tue Apr 25 18:54:41 2017 dubret_v
** Last update Sun Apr 30 17:48:01 2017 dubret_v
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

static	char			**tab_realloc(char **tab)
{
  int				i;
  char				**tmp;

  i = 0;
  tmp = malloc(sizeof(char *) * (array_len(tab) + 2));
  if (tmp == NULL)
    return (NULL);
  while (tab[i] != NULL)
    {
      tmp[i] = my_strdup(tab[i]);
      if (tmp[i] == NULL)
	return (NULL);
      i++;
    }
  tmp[i] = NULL;
  return (tmp);
}

static	t_path			*modif_path(t_path *paths, char **path)
{
  if (paths->path != NULL)
    free_tab(paths->path);
  paths->path = my_tabdup(path);
  if (paths->path == NULL)
    return (NULL);
  return (paths);
}

static	char		**actual_path(t_map *graph, char **path)
{
  int			i;

  i = 0;
  if (path == NULL)
    {
      path = malloc(sizeof(char *) * 2);
      if (path == NULL)
	return (NULL);
      path[0] = my_strdup(graph->data.name);
      path[1] = NULL;
    }
  else
    {
      path = tab_realloc(path);
      if (path == NULL)
	return (NULL);
      while (path[i] != NULL)
	i++;
      path[i] = my_strdup(graph->data.name);
      path[i + 1] = NULL;
    }
  return (path);
}

/*
** Vérifie si le premier maillon est déjà passer par là fin.
** Si oui alors créer un nouveau maillon.
** Si non modifie le maillon existant.
*/
static	t_path		*is_new_good_path(t_path *paths, char **path)
{
  if (paths->over == 0)
    {
      paths = modif_path(paths, path);
      if (paths == NULL)
	return (NULL);
    }
  return (paths);
}

t_path			*search_path(t_map *graph, t_name_path path,
				     t_path *paths, t_ever_passed *ever_passed)
{
  t_ever_passed		*tmp;

  if (paths->over == 1)
    return (paths);
  ever_passed = init_ever_passed(ever_passed, graph, path);
  if (ever_passed == NULL)
    return (NULL);
  tmp = ever_passed;
  while (tmp && my_strcmp(tmp->room_name, graph->data.name) != 0)
    tmp = tmp->next;
  if (tmp)
    {
      path.path = actual_path(graph, path.path);
      if (path.path == NULL)
	return (NULL);
      paths = is_new_good_path(paths, path.path);
      if (paths == NULL)
	return (NULL);
      paths = go_through_graph(graph, tmp, paths, path);
      if (paths == NULL)
	return (NULL);
    }
  return (paths);
}
