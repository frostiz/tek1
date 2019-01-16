/*
** AI.c for matchstick in /home/thibaut/Repository/CPE_2016_matchstick
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Feb 26 14:41:01 2017 
** Last update Sun Feb 26 16:48:27 2017 
*/

#include "my.h"

static void	aff_ai_removed_and_del(int nb_stick, int line, t_map2 info)
{
  my_putstr("\nAI's turn...\n");
  my_putstr("AI removed ");
  my_put_nbr(nb_stick);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putchar('\n');
  while (nb_stick > 0)
    {
      del_last_elem(line, info.map);
      nb_stick--;
    }
  return ;
}

static int	lines_not_inferior_to_delmax(t_map2 info,
					     int nb_stick, int line)
{
  if (is_sup_del_max(info.map, info.del_max) == 1)
    {
      line = find_sup_del_max(info.map, info.del_max);
      if (next_space(info.map[line - 1]) - info.del_max > info.del_max)
	nb_stick = info.del_max;
      else
	nb_stick = next_space(info.map[line - 1]) - info.del_max;
    }
  else
    {
      if (info.actual_nbline % 2 == 0)
	{
	  line = find_longest_line(info.map);
	  nb_stick = (next_space(info.map[line - 1]));
	}
      else
	{
	  line = find_longest_line(info.map);
	  nb_stick = (next_space(info.map[line - 1]) - 1);
	}
    }
  if (nb_stick <= 0)
    nb_stick = 1;
  aff_ai_removed_and_del(nb_stick, line, info);
  return (1);
}

static int	one_line_remaining(t_map2 info)
{
  int	line;
  int	nb_stick;

  if (info.actual_nbline == 1)
    {
      line = find_longest_line(info.map);
      if (next_space(info.map[line - 1]) <= info.del_max)
	{
	  nb_stick = next_space(info.map[line - 1]) - 1;
	  if (nb_stick <= 0)
	    nb_stick = 1;
	  aff_ai_removed_and_del(nb_stick, line, info);
	  return (1);
	}
      if (next_space(info.map[line - 1]) - info.del_max > info.del_max)
	nb_stick = info.del_max;
      else
	nb_stick = next_space(info.map[line - 1]) - info.del_max - 1;
      if (nb_stick <= 0)
	nb_stick = 1;
      return (1);
    }
  return (0);
}

static int	last_line_inferior_to_delmax(t_map2 info)
{
  int	line;
  int	nb_stick;

  if (info.init_nbline * 2 - 1 <= info.del_max)
    {
      if (info.actual_nbline % 2 == 0)
	{
	  line = find_longest_line(info.map);
	  nb_stick = (next_space(info.map[line - 1]));
	}
      else
	{
	  line = find_longest_line(info.map);
	  nb_stick = (next_space(info.map[line - 1]) - 1);
	}
      if (nb_stick <= 0)
	nb_stick = 1;
      aff_ai_removed_and_del(nb_stick, line, info);
      return (1);
    }
  return (0);
}

void	ai_turn(t_map2 info)
{
  int	nb_stick;
  int	line;

  nb_stick = 0;
  line = 0;
  if (one_line_remaining(info) == 1)
    return ;
  else if (last_line_inferior_to_delmax(info) == 1)
    return ;
  else if (lines_not_inferior_to_delmax(info, nb_stick, line) == 1)
    return ;
  return ;
}
