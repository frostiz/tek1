/*
** chdir_path.c for chdir_path.c in /home/frostiz/PSU_2016_minishell1/src
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Tue Jan 24 15:04:00 2017 thibaut trouve
** Last update Tue Jan 24 15:08:11 2017 thibaut trouve
*/

#include "my.h"

int	is_folder(char *name)
{
  t_stat file;

  stat(name, &file);
  if (((file.st_mode & S_IFMT) != S_IFDIR) &&
      (access(name, F_OK) == 0))
    {
      return (84);
    }
  return (0);
}

int	test_chdirpath(char **tab)
{
  if (access(tab[1], F_OK) == 0)
    {
      if (is_folder(tab[1]) == 84)
	{
	  my_printf("%s: Not a directory.\n", tab[1]);
	  return (NOT_DIR);
	}
      chdir(tab[1]);
      return (0);
    }
  my_printf("%s: No such file or directory\n", tab[0]);
  return (INEXISTANT);
}

void	sign_handler(int wstatus)
{
  if (wstatus == 11)
    {
      my_printf("Segmentation fault\n");
      return ;
    }
  if (wstatus == 8)
    {
      my_printf("Floating exception\n");
      return ;
    }
  if (wstatus == 7)
    {
      my_printf("Bus error\n");
      return ;
    }
  if (wstatus == 4)
    {
      my_printf("Illegal instruction\n");
      return ;
    }
  if (wstatus == 6)
    {
      my_printf("Aborted\n");
      return ;
    }
}

void	check_status(int wstatus)
{
  if (wstatus == 139)
    {
      my_printf("Segmentation fault (core dumped)\n");
      return ;
    }
  else if (wstatus == 132)
    {
      my_printf("Illegal instruction (core dumped)\n");
      return ;
    }
  else if (wstatus == 134)
    {
      my_printf("Aborted (core dumped)\n");
      return ;
    }
  else if (wstatus == 135)
    {
      my_printf("Bus error (core dumped)\n");
      return ;
    }
  else if (wstatus == 136)
    {
      my_printf("Floating exception (core dumped)\n");
      return ;
    }
}
