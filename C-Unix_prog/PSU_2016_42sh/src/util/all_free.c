/*
** all_free.c for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
**
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
**
** Started on  Mon May 15 10:07:32 2017 dubret_v
** Last update Sat May 20 18:06:51 2017 dubret_v
*/

#include		<stdlib.h>
#include		"mysh.h"

void		free_graph(t_graph *graph)
{
  if (graph == NULL)
    return ;
  if (graph->left != NULL)
    free_graph(graph->left);
  if (graph->right != NULL)
    free_graph(graph->right);
  if (graph->command != NULL)
    free(graph->command);
  if (graph != NULL)
    free(graph);
}

void		my_free_tab(char **tab)
{
  unsigned int	i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  if (tab != NULL)
    free(tab);
}
