/*
** my_cd.c for 42sh in /home/Lucas/delivery/PSU
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Thu May 18 09:16:53 2017 Lucas Dumy
** Last update Mon May 22 14:54:39 2017 Lucas Dumy
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"mysh.h"
#include	"exec.h"

char		***create_pwd(char ***env, int *fd)
{
  char		**path;
  char		*buf;
  int		ret_val_tmp;
  int		i;

  i = 0;
  while ((*env)[i] != NULL && strncmp("PWD=", (*env)[i], 4) != 0)
    i++;
  if ((*env)[i] == NULL)
    {
      buf = get_current_dir_name();
      if (buf != NULL)
	{
	  path = my_split(my_strcat("setenv PWD ", buf), ' ');
	  free(buf);
	  my_setenv(path, env, &ret_val_tmp, fd);
	  my_free_tab(path);
	}
    }
  return (env);
}

static char	***recreate_oldpwd(char ***env, int *fd)
{
  char		**path;
  int		return_value;
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  k = 0;
  while ((*env)[i] != NULL && strncmp("OLDPWD=", (*env)[i], 7) != 0)
    i++;
  while ((*env)[k] != NULL && strncmp("PWD=", (*env)[k], 4) != 0)
    k++;
  if ((*env)[i] == NULL && (*env)[k] != NULL)
    {
      while ((*env)[j] != NULL && strncmp("PWD=", (*env)[j], 4) != 0)
	j++;
      path = my_split(my_strcat("setenv OLDPWD ", &(*env)[j][4]), ' ');
      my_setenv(path, env, &return_value, fd);
      my_free_tab(path);
      path = my_split(strdup("unsetenv PWD"), ' ');
      my_unsetenv(path, env, &return_value, fd);
      my_free_tab(path);
    }
  return (env);
}

static void	change_dir(char ***env, char *str, int *return_value,
			   __attribute__ ((unused)) int *fd)
{
  if (access(str, X_OK) != 0)
    {
      my_perror(str);
      my_perror(": Permission denied.\n");
      *return_value = 1;
    }
  else if (chdir(str) < 0)
    {
      my_perror(str);
      my_perror(": No such file or directory.\n");
      *return_value = 1;
    }
  else
    {
      set_pwd(env, "OLDPWD=", "PWD=");
      *return_value = 0;
    }
}

static void	check_dir(char ***env, char **tab, int *return_value, int *fd)
{
  struct stat	statbuf;

  if (stat(tab[1], &statbuf) == -1)
    {
      my_perror(tab[1]);
      my_perror(": No such file or directory.\n");
      *return_value = 1;
    }
  else if (fd[2] != -1 && S_ISDIR(statbuf.st_mode))
    return ;
  else if (S_ISDIR(statbuf.st_mode))
    change_dir(env, tab[1], return_value, fd);
  else
    {
      my_perror(tab[1]);
      my_perror(": Not a directory.\n");
      *return_value = 1;
    }
}

void		my_cd(char **tab, char ***env, int *return_value, int *fd)
{
  if (tab[1] == NULL || (tab[1] != NULL && tab[2] == NULL))
    env = create_pwd(env, fd);
  if (tab[1] == NULL)
    go_home(env, return_value, fd);
  else if (tab[2] != NULL)
    {
      my_perror("cd: Too many arguments.\n");
      *return_value = 1;
    }
  else if (strcmp(tab[1], "-") == 0 && tab[2] == NULL)
    go_back(env, return_value, fd);
  else
    check_dir(env, tab, return_value, fd);
  env = recreate_oldpwd(env, fd);
  env = create_pwd(env, fd);
}
