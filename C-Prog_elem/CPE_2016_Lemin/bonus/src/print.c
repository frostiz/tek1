/*
** print.c for print.c in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin/bonus
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr 30 23:10:33 2017 Vincent Roye
** Last update Sun Apr 30 23:10:56 2017 Vincent Roye
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "graph.h"
#include "lemin.h"
#include "my.h"

void	print_this(t_graph *ant, t_my_framebuffer* framebuffer,
		   t_rooms *tmp)
{
  ant->from.x = tmp->data->x * ant->max;
  ant->from.y = tmp->data->y * ant->max;
  ant->to.x = ant->tab.base_pos[ant->base_connect][0];
  ant->to.y = ant->tab.base_pos[ant->base_connect][1];
  my_draw_line(framebuffer, ant->from, ant->to, sfBlue);
}
