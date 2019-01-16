/*
** main.c for main.c in /home/thibaut/Repository/PSU_2016_navy
** 
** Made by thibaut trouve
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Tue Jan 31 12:24:09 2017 
** Last update Sun Feb 19 18:32:31 2017 
*/

#include "gnl.h"
#include "my.h"

int	nb_sig[3];

void	sign_handler(int sig, siginfo_t *info, void *context)
{
  static int	bool = 1;

  (void)context;
  if (bool == 1)
    {
      bool = 0;
      nb_sig[2] = info->si_pid;
    }
  if (sig == SIGUSR2)
    {
      nb_sig[1]++;
    }
  else if (sig == SIGUSR1)
    {
      nb_sig[0]++;
    }
}

int	check_end(char **my_positions, char **enemy_positions, int opt)
{
  int	nb_hit;

  nb_hit = 0;
  count_x(my_positions, &nb_hit);
  if (nb_hit == 14)
    {
      if (opt == 1)
	{
	  show_map(my_positions, enemy_positions);
	  my_putstr("Enemy won\n");
	}
      return (1);
    }
  nb_hit = 0;
  count_x(enemy_positions, &nb_hit);
  if (nb_hit == 14)
    {
      if (opt == 1)
	{
	  show_map(my_positions, enemy_positions);
	  my_putstr("I won\n");
	}
      return (0);
    }
  return (NOT_FINISH);
}

int	battleship(int argc, char **argv)
{
  struct sigaction	sig;
  int			fd;

  sig.sa_sigaction = &sign_handler;
  sig.sa_flags = SA_SIGINFO;
  sigemptyset(&sig.sa_mask);
  sigaction(SIGUSR1, &sig, NULL);
  sigaction(SIGUSR2, &sig, NULL);
  if (argc == 2)
    {
      if ((fd = open(argv[1], O_RDONLY)) == -1)
	return (84);
      return (player_one(fd));
    }
  else if (argc == 3)
    return (player_two(argv));
  else
    return (84);
  return (0);
}

int	main(int argc, char **argv)
{
  if (argc > 3)
    return (84);
  return (battleship(argc, argv));
  return (0);
}
