/*
** print_map.c for print_map.c in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Thu Apr 20 20:18:07 2017 Vincent Roye
** Last update Sun Apr 30 23:20:45 2017 Vincent Roye
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "graph.h"
#include "lemin.h"
#include "my.h"

static int	init_values(t_graph *ant, t_rooms *rooms)
{
  ant->k = 0;
  ant->base_connect = 0;
  ant->dont_print = 0;
  ant->max = get_max_size(rooms);
  ant->tab.stock = malloc(sizeof(char *) * (count_linked(rooms)));
  if (ant->tab.stock == NULL)
    return (1);
  ant->tab.base_pos = malloc(sizeof(int *) * (count_linked(rooms)));
  if (ant->tab.base_pos == NULL)
    return (1);
  return (0);
}

void		is_good_base(t_graph *ant, t_rooms *tmp)
{
  if ((my_strcmp(ant->tab.stock[ant->base_connect],
		 tmp->tunnel[ant->k]) != 0))
    ant->base_connect++;
  else
    ant->dont_print = 1;
}

void	search_connection(t_graph *ant, t_rooms *tmp)
{
  while (ant->tab.stock[ant->base_connect] != NULL &&
	 tmp->tunnel[ant->k] != NULL && ant->dont_print != 1)
    is_good_base(ant, tmp);
}

void		draw_maze(t_rooms *rooms, t_my_framebuffer* framebuffer)
{
  t_graph	ant;
  t_rooms	*tmp;

  if (init_values(&ant, rooms) == 1)
    return ;
  tmp = rooms;
  stock_data(&ant.tab, rooms, ant.max);
  while (tmp != NULL)
    {
      draw_square(tmp->data->x * ant.max, tmp->data->y * ant.max,
		  framebuffer, tmp->data->pos);
      while (tmp->tunnel[ant.k] != NULL)
	{
	  ant.base_connect = 0;
	  ant.dont_print = 0;
	  if (ant.tab.stock[ant.base_connect] != NULL)
	    search_connection(&ant, tmp);
	  if (ant.dont_print == 1)
	    print_this(&ant, framebuffer, tmp);
	  ant.k++;
	}
      ant.k = 0;
      tmp = tmp->next;
    }
}

int			print_map(t_rooms *rooms)
{
  sfRenderWindow	*window;
  t_my_framebuffer*	framebuffer;
  sfTexture*		texture;
  sfSprite*		sprite;

  framebuffer = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  draw_maze(rooms, framebuffer);
  window = create_window();
  sprite = sfSprite_create();
  texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfTexture_updateFromPixels(texture, framebuffer->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  while (sfRenderWindow_isOpen(window))
    {
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	sfRenderWindow_close(window);
      sfRenderWindow_clear(window, sfBlack);
      sfSprite_setTexture(sprite, texture, sfTrue);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
  return (0);
}
