/*
** player_one.c for Navy in /home/thibaut/Repository/PSU_2016_navy/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Feb 15 17:40:14 2017 
** Last update Sun Feb 19 18:40:09 2017 
*/

#include "my.h"

extern int	nb_sig[3];

int	game_one(char **my_positions, char **enemy_positions)
{
  while (check_end(my_positions, enemy_positions, 0) == NOT_FINISH)
    {
      show_map(my_positions, enemy_positions);
      wait_attack_position(enemy_positions);
      if (check_end(my_positions, enemy_positions, 1) != NOT_FINISH)
	return (check_end(my_positions, enemy_positions, 0));
      wait_ennemy_attack_positions();
      usleep(50);
      if (print_hit_status(my_positions) == 1)
	{
	  kill(nb_sig[2], SIGUSR2);
	  usleep(300);
	}
      kill(nb_sig[2], SIGUSR2);
      usleep(300);
      if (check_end(my_positions, enemy_positions, 1) != NOT_FINISH)
	return (check_end(my_positions, enemy_positions, 0));
    }
  return (0);
}

int	player_one(int fd)
{
  char	**enemy_positions;
  char	**my_positions;

  enemy_positions = get_map();
  my_positions = get_my_map(fd);
  if (my_positions == NULL)
    return (84);
  my_putstr("my_pid: ");
  my_put_nbr(getpid());
  my_putchar('\n');
  my_putstr("waiting for enemy connection...\n");
  pause();
  my_putstr("\nenemy connected\n\n");
  return (game_one(my_positions, enemy_positions));
  return (0);
}
