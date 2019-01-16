/*
** redirection.c for redirection.c in /home/frostiz/PSU_2016_minishell1/src
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Sun Jan 22 23:12:54 2017 thibaut trouve
** Last update Tue Jan 24 15:08:12 2017 thibaut trouve
*/

#include "my.h"

int	findsign(char *str)
{
  int   i;
  int   count_less;

  i = 0;
  count_less = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '-')
	count_less++;
      i++;
    }
  if (count_less % 2 == 1)
    return (-1);
  else
    return (1);
}

int	builtin(char **tab, char ***my_env)
{
  if (my_strcmp("exit", tab[0]) == 0)
    {
      if (tab[1] != NULL)
	exit(my_getnbr(tab[1]));
      exit(0);
    }
  else if (my_strcmp("unsetenv", tab[0]) == 0 ||
	   my_strcmp("env", tab[0]) == 0 ||
	   my_strcmp("setenv", tab[0]) == 0)
    return (env_command(tab, my_env));
  else if (my_strcmp("cd", tab[0]) == 0)
    {
      change_directory(tab, my_env);
      return (0);
    }
  return (1);
}

void	execute(char *correct_path, char **tab, char **my_env)
{
  pid_t pid;
  int   wstatus;

  signal(SIGSEGV, sign_handler);
  signal(SIGFPE, sign_handler);
  signal(SIGABRT, sign_handler);
  signal(SIGTRAP, sign_handler);
  signal(SIGILL, sign_handler);
  if (is_existing_prog(tab[0], correct_path) == 1 &&
      correct_path != NULL)
    {
      pid = fork();
      if (pid == 0)
	execve(correct_path, &tab[0], my_env);
      else
	{
	  waitpid(pid, &wstatus, 0);
	  check_status(wstatus);
	}
    }
}

void	basic_programs(char **tab, char ***my_env, char **argv)
{
  char  *correct_path;

  (void)argv;
  if (tab == NULL || tab[0] == NULL || tab[0][0] == '\0')
    return ;
  correct_path = test_paths(tab, *my_env);
  if (builtin(tab, my_env) == 0)
    return ;
  if (is_existing_prog(tab[0], correct_path) == 1)
    execute(correct_path, tab, *my_env);
  else
    my_printf("%s: Command not found.\n", tab[0]);
}

int	my_getnbr(char *str)
{
  int   i;
  int   nb;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
	{
	  if (str[i] == '-')
	    nb = nb * (-1);
	  if (str[i] >= '0' && str[i] <= '9')
	    nb = (str[i] - 48) + (10 * nb);
	  i++;
	}
      if (str[i] < '0' || str[i] > '9')
	{
	  nb = nb * findsign(str);
	  return (nb);
	}
      i++;
    }
  return (nb);
}
