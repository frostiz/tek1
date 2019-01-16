/*
** show_graph.c for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Mon May 15 10:07:04 2017 dubret_v
** Last update Mon May 15 14:06:57 2017 dubret_v
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"mysh.h"

void		show_graph(t_graph *graph, char *name)
{
  printf("----------------\n");
  printf("from : %s\n", name);
  printf("command: %s\n", graph->command);
  printf("limiteur: %d\n", graph->limit);
  if (graph->left != NULL)
    show_graph(graph->left, graph->command);
  if (graph->right != NULL)
    show_graph(graph->right, graph->command);
}
