/*
** main.c for main.c in /home/roye_v/delivery/CPE_2016_n4s
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Fri Jun  2 14:29:44 2017 Vincent Roye
** Last update Tue Jun  6 14:12:08 2017 thibaut trouve
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"n4s.h"

char	*launch_command(char *command)
{
  char		*ret;
  size_t	len;

  ret = NULL;
  len = 0;
  dprintf(1, command);
  getline(&ret, &len, stdin);
  if (track_cleared(ret) == 1)
    return (NULL);
  if (check_ko(ret) == 1)
    return (NULL);
  return (ret);
}

char	**init_speed(char *str, char *str_lidar)
{
  char	**lidar;

  str = launch_command("wheels_dir:0.0\n");
  if (check_end(str) == 1)
    return (NULL);
  str_lidar = launch_command("get_info_lidar\n");
  if (check_end(str_lidar) == 1)
    return (NULL);
  lidar = my_str_to_wordtab(str_lidar, ':');
  if (lidar == NULL)
    return (NULL);
  if (lidar[0] == NULL)
    return (NULL);
  lidar = &lidar[3];
  return (lidar);
}

int	mainloop()
{
  char	*str;
  char	*str_lidar;
  char	**lidar;

  str = NULL;
  str_lidar = NULL;
  lidar = init_speed(str, str_lidar);
  if (lidar == NULL)
    return (1);
  while (atof(lidar[15]) > 500.0 && atof(lidar[16]) > 500.0)
    {
      lidar = move_forward(lidar);
      if (lidar == NULL)
	return (1);
    }
  if (is_zero(lidar) == 1)
    {
      if (move_backwards() == 1)
	return (1);
    }
  if (turn(lidar) == 1)
    return (1);
  return (0);
}

int	n4s()
{
  char	*str;

  str = launch_command("start_simulation\n");
  if (check_end(str) == 1)
    return (0);
  str = launch_command("car_forward:0.3\n");
  if (check_end(str) == 1)
    return (0);
  while (1)
    {
      if (mainloop() == 1)
	return (0);
    }
  return (0);
}

int	main()
{
  if (n4s() == 1)
    return (84);
  return (0);
}
