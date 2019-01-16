/*
** my_cd_home.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Thu May 18 17:43:56 2017 Lucas Dumy
** Last update Fri May 19 08:09:50 2017 Lucas Dumy
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"mysh.h"
#include	"exec.h"

static char	***create_home(char ***env, int *return_value, int *fd)
{
  char		**path;
  char		*buf;
  int		i;

  i = 0;
  while ((*env)[i] != NULL && strncmp("HOME=", (*env)[i], 5) != 0)
    i++;
  if ((*env)[i] == NULL)
    {
      buf = get_current_dir_name();
      if (buf != NULL)
	{
	  path = my_split(my_strcat("setenv HOME ", buf), ' ');
	  free(buf);
	  my_setenv(path, env, return_value, fd);
	  my_free_tab(path);
	}
    }
  return (env);
}

static void	change_to_home(char ***env, char *str,
			       int *return_value, int *fd)
{
  env = create_pwd(env, fd);
  if (chdir(str) < 0)
    {
      my_perror("cd: Can't change to home directory.\n");
      *return_value = 1;
    }
  else
    {
      set_pwd(env, "OLDPWD=", "PWD=");
      env = create_home(env, return_value, fd);
      *return_value = 0;
    }
}

void		go_home(char ***env, int *return_value, int *fd)
{
  struct stat	statbuf;
  int		i;

  i = 0;
  while ((*env)[i] != NULL && strncmp("HOME=", (*env)[i], 5) != 0)
    i++;
  if ((*env)[i] == NULL)
    {
      my_perror("cd: No home directory.\n");
      *return_value = 1;
    }
  else if (stat(&(*env)[i][5], &statbuf) == -1 || !S_ISDIR(statbuf.st_mode))
    {
      my_perror("cd: Can't change to home directory.\n");
      *return_value = 1;
    }
  else
    change_to_home(env, &(*env)[i][5], return_value, fd);
}
