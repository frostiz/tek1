/*
** my_cd_error.c for minishell2 in /home/frostiz/Backup/minishell2
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Sun Apr  9 16:59:33 2017 thibaut trouve
** Last update Wed May  3 05:29:17 2017 Thibaut Trouvé
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"
#include "my.h"

int		is_slash(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	return (1);
      i++;
    }
  return (0);
}

static int	check_existing_path(char *path, struct stat file,
				    char **args)
{
  my_strcat(path, "/");
  lstat(path, &file);
  if ((file.st_mode & S_IFMT) != S_IFDIR)
    {
      my_putstr(args[1]);
      my_putstr(": Not a directory.\n");
      return (-1);
    }
  return (0);
}

static int	check_nb_cd_args(char *path, char **args)
{
  my_strcpy(path, args[1]);
  if (my_tablen(args) > 2)
    {
      my_putstr("cd: Too many arguments.\n");
      return (-1);
    }
  return (0);
}

int	check_cd_errors(char **args)
{
  struct stat	file;
  char		*path;

  if (args[1] != NULL)
    {
      path = malloc(sizeof(char) * (my_strlen(args[1]) + 2));
      if (path == NULL)
	return (-1);
      if (check_nb_cd_args(path, args) == -1)
	return (-1);
      if (args[1][0] == '-')
	return (0);
      if (lstat(path, &file) == -1)
	{
	  my_putstr(args[1]);
	  my_putstr(": No such file or directory.\n");
	  return (-1);
	}
      else if ((file.st_mode & S_IFMT) != S_IFDIR)
	return (check_existing_path(path, file, args));
    }
  return (0);
}
