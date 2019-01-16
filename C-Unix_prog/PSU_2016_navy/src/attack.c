/*
** attack.c for Navy in /home/thibaut/Repository/PSU_2016_navy/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Feb 15 17:52:14 2017 
** Last update Sun Feb 19 18:34:28 2017 
*/

#include "my.h"
#include "gnl.h"

extern int nb_sig[3];

int	wait_attack_position(char **enemy_positions)
{
  char	*input;

  my_putstr("attack: ");
  input = get_next_line(0);
  if (input == NULL)
    return (0);
  if ((check_input_validity(input)) == 84)
    {
      my_putstr("wrong position\n");
      wait_attack_position(enemy_positions);
    }
  else
    replace_map_coord(input, enemy_positions);
  return (0);
}

int	wait_ennemy_attack_positions()
{
  struct timespec time;

  time.tv_nsec = 1000000;
  time.tv_sec = 0;
  my_putstr("waiting for enemy's attack...\n");
  pause();
  while (nanosleep(&time, NULL) == -1);
  return (0);
}

int	print_hit_status(char **my_positions)
{
  my_putchar(nb_sig[0] + 65 - 1);
  my_putchar(nb_sig[1] + 48 - 1);
  if (my_positions[nb_sig[1] - 1 - 1][nb_sig[0] - 1] != '.' &&
      my_positions[nb_sig[1] - 1 - 1][nb_sig[0] - 1] != 'o')
    {
      my_putstr(": hit\n\n");
      my_positions[nb_sig[1] - 1 - 1][nb_sig[0] - 1] = 'x';
      nb_sig[0] = 0;
      nb_sig[1] = 0;
      return (1);
    }
  else
    {
      my_putstr(": missed\n\n");
      my_positions[nb_sig[1] - 1 - 1][nb_sig[0] - 1] = 'o';
      nb_sig[0] = 0;
      nb_sig[1] = 0;
      return (0);
    }
  return (0);
}

int	send_signals(char *input, int pid)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (input[i] != '\0')
    {
      while (j <= input[i] - 65)
	{
	  kill(pid, SIGUSR1);
	  usleep(100);
	  j++;
	}
      j = 0;
      i++;
      while (j <= input[i] - 48)
	{
	  kill(pid, SIGUSR2);
	  usleep(100);
	  j++;
	}
      j = 0;
      i++;
    }
  return (0);
}

void	replace_map_coord(char *input, char **enemy_positions)
{
  send_signals(input, nb_sig[2]);
  nb_sig[0] = 0;
  nb_sig[1] = 0;
  pause();
  while (usleep(20000) == -1);
  my_putstr(input);
  if (nb_sig[1] == 2)
    {
      enemy_positions[input[1] - 48 - 1][input[0] - 65] = 'x';
      my_putstr(": hit\n\n");
    }
  else
    {
      enemy_positions[input[1] - 48 - 1][input[0] - 65] = 'o';
      my_putstr(": missed\n\n");
    }
  nb_sig[0] = 0;
  nb_sig[1] = 0;
}
