/*
** basic_functions.c for basic_functions.c in /home/frostiz/PSU_2016_minishell1/src
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Tue Jan 17 22:47:59 2017 thibaut trouve
** Last update Sun Jan 22 23:31:40 2017 thibaut trouve
*/

#include <unistd.h>
#include <stdlib.h>

int	my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int	nb_env_var(char **env)
{
  int   i;

  i = 0;
  while (env[i] != NULL)
    i++;
  return (i);
}

int	getnb_args(char *str)
{
  int   i;
  int   nb_args;

  nb_args = 1;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	nb_args++;
      i++;
    }
  return (nb_args);
}
