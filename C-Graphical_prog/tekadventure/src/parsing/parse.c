/*
** parse.c for tekadventure in /home/dubret_v/delivery/semestre2/infographie/tekadventure
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Tue May 23 16:26:36 2017 dubret_v
** Last update Sun May 28 13:49:32 2017 Victor Dubret
*/

#include	<stdio.h>

#include	<fcntl.h>
#include	<stdlib.h>
#include	"my.h"
#include	"get_next_line.h"
#include	"tekadventure.h"

t_map		*(*fill_graph[6])(t_map *, int *, char *) =
{create_node, add_background, add_walkzone, add_doorzone,
 add_object, add_characters};

static void	init_conf_words(char *conf_words[6])
{
  conf_words[0] = "Scene:";
  conf_words[1] = "Background";
  conf_words[2] = "Walk Zone";
  conf_words[3] = "Door Zone";
  conf_words[4] = "Object";
  conf_words[5] = "Character";
}

t_creating	init_create(int fd)
{
  t_creating	creat;

  creat.i = 0;
  init_conf_words(creat.conf_words);
  creat.str = get_next_line(fd);
  return (creat);
}

t_map		*creating(t_map *graph, int fd, int fill, int room)
{
  t_creating	creat;

  creat = init_create(fd);
  if (creat.str == NULL)
    return (graph);
  while (creat.i < 6)
    {
      if (my_strcmp(creat.str, creat.conf_words[creat.i]) == 0)
	{
	  fill = creat.i;
	  graph = creating(graph, fd, fill, room);
	  if (graph == NULL)
	    return (NULL);
	  creat.i = 10;
	}
      creat.i++;
    }
  if (creat.i < 8)
    {
      graph = fill_graph[fill](graph, &room, creat.str);
      if (graph == NULL)
	return (NULL);
    }
  graph = creating(graph, fd, fill, room);
  return (graph == NULL ? NULL : graph);
}

t_map		*create_graph(char *config_folder)
{
  t_map		*graph;
  int		fd;
  int		*ever_passed;
  int		check;

  fd = open(config_folder, O_RDONLY);
  if (fd == -1)
    {
      my_puterror("The file doesn't exist.\n");
      return (NULL);
    }
  graph = creating(NULL, fd, 0, 0);
  if (graph == NULL)
    return (NULL);
  check = 0;
  ever_passed = error_checking(graph, NULL, &check);
  if (ever_passed == NULL || check == 1)
    return (NULL);
  return (graph);
}
