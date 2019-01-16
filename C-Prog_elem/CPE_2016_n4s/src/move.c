/*
** move.c for n4s in /home/frostiz/repository/CPE_2016_n4s
** 
** Made by thibaut trouve
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Jun  4 17:09:55 2017 thibaut trouve
** Last update Sun Jun  4 20:31:44 2017 Victor Dubret
*/

#include <stdlib.h>
#include "n4s.h"

int	move_backwards()
{
  char	*str;

  str = launch_command("car_backwards:1.0\n");
  if (check_end(str) == 1)
    return (1);
  str = launch_command("cycle_wait:5\n");
  if (check_end(str) == 1)
    return (1);
  str = launch_command("car_forward:0.3\n");
  if (check_end(str) == 1)
    return (1);
  return (0);
}

int	turn(char **lidar)
{
  char	*str;

  if (atof(lidar[0]) > atof(lidar[31]))
    str = launch_command("wheels_dir:1.0\n");
  else
    str = launch_command("wheels_dir:-1.0\n");
  if (check_end(str) == 1)
    return (1);
  str = launch_command("cycle_wait:1\n");
  if (check_end(str) == 1)
    return (1);
  return (0);
}

char	**move_forward(char **lidar)
{
  char	*str;
  char	*str_lidar;

  if (atof(lidar[15]) > 900.0 && atof(lidar[16]) > 900.0)
    str = launch_command("car_forward:0.6\n");
  else
    str = launch_command("car_forward:0.3\n");
  if (check_end(str) == 1)
    return (NULL);
  str_lidar = launch_command("get_info_lidar\n");
  if (check_end(str_lidar) == 1)
    return (NULL);
  lidar = my_str_to_wordtab(str_lidar, ':');
  lidar = &lidar[3];
  if (atof(lidar[0]) > atof(lidar[31]))
    str = launch_command("wheels_dir:0.1\n");
  else
    str = launch_command("wheels_dir:-0.1\n");
  if (check_end(str) == 1)
    return (NULL);
  return (lidar);
}
