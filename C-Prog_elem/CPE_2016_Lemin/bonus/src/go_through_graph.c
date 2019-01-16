/*
** go_through_graph.c for lemin in /home/dubret_v/delivery/semestre2/CPE/CPE_2016_Lemin
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sun Apr 30 16:13:48 2017 dubret_v
** Last update Sun Apr 30 21:46:17 2017 dubret_v
*/

#include	<stdio.h>
#include	"lemin.h"
#include	"my.h"

int	is_passed(char **ever_passed, char *name)
{
  int		i;

  i = 0;
  while (ever_passed[i])
    {
      if (my_strcmp(ever_passed[i], name) == 0)
	return (1);
      i++;
    }
  return (0);
}

static	int		is_passed_(char **path, char *name)
{
  int			i;

  i = 0;
  while (path[i] != NULL)
    {
      if (my_strcmp(path[i], name) == 0)
	return (1);
      i++;
    }
  return (0);
}

static int	passed_is(char **tab, t_path *paths)
{
  int		i;
  t_path	*tmp;

  tmp = paths;
  if (path_len(paths) == 1)
    return (0);
  while (tmp != NULL)
    {
      i = 0;
      if (array_len(tab) != array_len(tmp->path))
	return (0);
      while (tab[i] != NULL)
	{
	  if (my_strcmp(tab[i], tmp->path[i]) != 0)
	    return (0);
	  i++;
	}
      tmp = tmp->next;
    }
  return (1);
}

static	t_path	*to_the_end(t_map *graph, t_name_path path,
			    t_path *paths, int *i)
{
  if (graph->data.pos == END &&
      passed_is(path.path, paths) == 0)
    paths->over = 1;
  *i += 1;
  return (paths);
}

t_path		*go_through_graph(t_map *graph, t_ever_passed *ever_passed,
				  t_path *paths, t_name_path path)
{
  int		i;

  i = 0;
  while (graph->link.link_address[i] != NULL)
    {
      if (graph->link.link_address != NULL &&
	  is_passed(ever_passed->is_passed, graph->link.link_name[i]) == 0 &&
	  is_passed_(path.path, graph->link.link_name[i]) == 0 &&
	  graph->data.pos != END)
	{
	  ever_passed = init_passed(ever_passed, graph->link.link_name,
				    graph->data.name, graph->link.link_name[i]);
	  if (ever_passed == NULL)
	    return (NULL);
	  path.name = my_strdup(graph->data.name);
	  if (path.name == NULL)
	    return (NULL);
	  paths = search_path(graph->link.link_address[i],
			      path, paths, ever_passed);
	  if (paths == NULL)
	    return (NULL);
	}
      paths = to_the_end(graph, path, paths, &i);
    }
  return (paths);
}
