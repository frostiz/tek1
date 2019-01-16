/*
** aff_map.c for matchstick in /home/thibaut/Repository/CPE_2016_matchstick
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Feb 26 14:36:09 2017 
** Last update Sun Feb 26 15:53:38 2017 
*/

#include "my.h"

void	get_mapinfo(t_map *info, int nb_line)
{
  info->line_size = (nb_line * 2) + 1;
  info->nb_stick = info->line_size - 2;
  info->nb_space = 2;
  while (nb_line > 1)
    {
      nb_line--;
      info->nb_space += 2;
      info->nb_stick -= 2;
    }
  return ;
}

void	aff_map(t_map2 data)
{
  t_map	info;
  int	i;
  int	j;

  get_mapinfo(&info, data.init_nbline);
  i = 0;
  j = 0;
  print_starline(info);
  while (data.map[i] != NULL)
    {
      my_putchar('*');
      while (j++ < info.nb_space / 2 - 1)
	my_putchar(' ');
      my_putstr(data.map[i]);
      while (j++ < info.nb_space - 1)
	my_putchar(' ');
      my_putchar('*');
      my_putchar('\n');
      j = 0;
      info.nb_space -= 2;
      i++;
    }
  print_starline(info);
  return ;
}
