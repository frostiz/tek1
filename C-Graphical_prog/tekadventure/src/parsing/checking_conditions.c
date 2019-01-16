/*
** checking_conditions.c for tekadventure in /home/DxCube/delivery/tekadventure
** 
** Made by Victor Dubret
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sat May 27 10:04:29 2017 Victor Dubret
** Last update Sun May 28 19:09:20 2017 Victor Dubret
*/

#include "tekadventure.h"

int	check_background(t_map *graph)
{
  if (graph->background == NULL)
    return (1);
  return (0);
}

int	check_walkzone(t_map *graph)
{
  if (graph->walkzone == NULL)
    return (1);
  return (0);
}

int	checking_walkzone(t_map *graph)
{
  if (graph->walkzone[0][0] % 2 != 0)
    return (1);
  return (0);
}

int	check_doorzone(t_map *graph)
{
  if (graph->doorzone == NULL)
    return (1);
  return (0);
}

int	checking_doorzone(t_map *graph)
{
  if (graph->doorzone[0][0] % 3 != 0)
    return (1);
  return (0);
}
