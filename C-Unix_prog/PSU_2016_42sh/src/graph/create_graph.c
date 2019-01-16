/*
** create_graph.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Sun May 21 15:45:52 2017 Lucas Dumy
** Last update Sun May 21 23:34:17 2017 Thibaut Trouvé
*/

#include		<stdlib.h>
#include		<string.h>
#include		"mysh.h"

static t_graph		*split_graph(t_graph *new_node, char *str, int i)
{
  if (new_node->limit >= 4 && new_node->limit < 8)
    {
      str = modify_for_redir(str, &i, new_node->limit);
      if (str == NULL)
	return (new_node);
    }
  str[i] = '\0';
  new_node->left = add_node(str);
  if (new_node->limit == 1 || new_node->limit == 2 ||
      new_node->limit == 4 || new_node->limit == 5)
    i++;
  new_node->right = add_node(&str[i + 1]);
  return (new_node);
}

t_graph			*add_node(char *str)
{
  t_graph		*new_node;
  int			i;

  i = 0;
  new_node = malloc(sizeof(t_graph));
  if (new_node == NULL)
    return (NULL);
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->limit = find_limit(&str, &i);
  if (new_node->limit == -1)
    return (NULL);
  new_node->command = strdup(str);
  if (new_node->command == NULL)
    return (NULL);
  remove_spare_spaces(new_node->command);
  if (new_node->command == NULL)
    return (NULL);
  if (new_node->limit != 8)
    split_graph(new_node, str, i);
  return (new_node);
}

t_graph			*create_graph(char *str)
{
  t_graph		*graph;

  graph = NULL;
  graph = add_node(str);
  if (graph == NULL)
    return (NULL);
  free(str);
  return (graph);
}
