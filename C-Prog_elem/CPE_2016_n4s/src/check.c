/*
** check.c for n4s in /home/frostiz/repository/CPE_2016_n4s
** 
** Made by thibaut trouve
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Jun  4 17:16:35 2017 thibaut trouve
** Last update Sun Jun  4 17:20:36 2017 thibaut trouve
*/

#include <string.h>
#include <stdlib.h>
#include "n4s.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      if (tab[i])
	free(tab[i]);
      i++;
    }
  if (tab)
    free(tab);
}

int	track_cleared(char *str)
{
  int	i;

  i = (int)strlen(str) - 1;
  while (i > 0 && str[i] != ':')
    i--;
  if (i > 0)
    i--;
  while (i > 0 && str[i] != ':')
    i--;
  if (strncmp(&str[i + 1], "Track Cleared", 13) == 0)
    return (1);
  return (0);
}

int	check_ko(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != ':')
    i++;
  if (str[i] == ':')
    i++;
  if (strncmp(&str[i], "KO", 2) == 0)
    return (1);
  return (0);
}

int	check_end(char *str)
{
  if (str == NULL)
    {
      launch_command("stop_simulation\n");
      return (1);
    }
  return (0);
}

int	is_zero(char **lidar)
{
  int	i;

  i = 0;
  while (lidar[i] != NULL && i < 32)
    {
      if (atof(lidar[i]) == 0.0)
	return (1);
      i++;
    }
  return (0);
}
