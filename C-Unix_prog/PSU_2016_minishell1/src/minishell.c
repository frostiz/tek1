/*
** minishell.c for minishell.c in /home/frostiz/PSU_2016_minishell1
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Sat Jan 14 15:27:19 2017 thibaut trouve
** Last update Sun Jan 22 23:13:40 2017 thibaut trouve
*/

#include "my.h"

void	sighand(int sign)
{
  (void)sign;
}

int	my_isatty(int fd)
{
  if (isatty(fd) == 1)
    my_putstr("$>");
  return (0);
}

void	free_my_env(char **my_env)
{
  int	i;

  i = 0;
  while (my_env[i] != NULL)
    {
      free(my_env[i]);
      i++;
    }
  free(my_env);
  return ;
}

int	minishell_1(char **argv, char **env)
{
  char	*input;
  char	**tab;
  char	**my_env;

  my_env = NULL;
  tab = NULL;
  my_env = get_env(env);
  input = argv[0];
  while ((my_isatty(0) == 0) && (input = get_next_line(0)) != NULL)
    {
      tab = get_args(input);
      basic_programs(tab, &my_env, argv);
      free(input);
      free(tab);
    }
  free_my_env(my_env);
  return (0);
}

int	main(int argc, char **argv, char **env)
{
  (void)argc;
  signal(SIGINT, sighand);
  minishell_1(argv, env);
  return (0);
}
