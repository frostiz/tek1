/*
** path_len.c for lemin in /home/dubret_v/delivery/semestre2/CPE/CPE_2016_Lemin
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sun Apr 30 16:17:45 2017 dubret_v
** Last update Sun Apr 30 16:19:05 2017 dubret_v
*/

#include	<stdlib.h>
#include	"lemin.h"

int			path_len(t_path *paths)
{
  int				i;
  t_path			*tmp;

  i = 0;
  tmp = paths;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}
