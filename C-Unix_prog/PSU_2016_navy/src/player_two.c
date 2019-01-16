/*
** player_two.c for Navy in /home/thibaut/Repository/PSU_2016_navy/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Feb 15 17:41:47 2017 
** Last update Sun Feb 19 18:35:13 2017 
*/

#include "my.h"

int	game_two(char **my_positions, char **enemy_positions, char **argv)
{
  while (check_end(my_positions, enemy_positions, 0) == NOT_FINISH)
    {
      wait_ennemy_attack_positions();
      usleep(500);
      if (print_hit_status(my_positions) == 1)
	kill(my_getnbr(argv[1]), SIGUSR2);
      usleep(300);
      kill(my_getnbr(argv[1]), SIGUSR2);
      usleep(300);
      if (check_end(my_positions, enemy_positions, 1) != NOT_FINISH)
	return (check_end(my_positions, enemy_positions, 0));
      wait_attack_position(enemy_positions);
      if (check_end(my_positions, enemy_positions, 1) != NOT_FINISH)
	return (check_end(my_positions, enemy_positions, 0));
      show_map(my_positions, enemy_positions);
    }
  return (0);
}

int	player_two(char **argv)
{
  char	**enemy_positions;
  char	**my_positions;
  int	fd;

  if ((fd = open(argv[2], O_RDONLY)) == -1)
    {
      my_putstr("Invalid map\n");
      return (84);
    }
  enemy_positions = get_map();
  my_positions = get_my_map(fd);
  if (my_positions == NULL)
    return (84);
  my_putstr("my_pid:");
  my_put_nbr(getpid());
  my_putchar('\n');
  if ((kill(my_getnbr(argv[1]), SIGUSR2)) == -1)
    return (84);
  my_putstr("successfully connected\n\n");
  show_map(my_positions, enemy_positions);
  return (game_two(my_positions, enemy_positions, argv));
  return (0);
}
