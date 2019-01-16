/*
** my_cd_back.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Thu May 18 17:50:34 2017 Lucas Dumy
** Last update Thu May 18 21:07:14 2017 Lucas Dumy
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"mysh.h"

static void	change_back(char ***env, char *str, int *return_value)
{
  char		*dup;
  int		i;

  i = 0;
  if (chdir(str) < 0)
    {
      my_perror("cd: Can't change to previous directory.\n");
      *return_value = 1;
      return ;
    }
  while (strncmp("OLDPWD=", (*env)[i], 7) != 0)
    i++;
  dup = strdup((*env)[i]);
  set_pwd(env, "OLDPWD=", "PWD=");
  i = 0;
  while ((*env)[i] != NULL && strncmp("PWD=", (*env)[i], 4) != 0)
    i++;
  if ((*env)[i] != NULL)
    {
      free((*env)[i]);
      (*env)[i] = my_strcat("PWD=", &dup[7]);
    }
  free(dup);
  *return_value = 0;
}

void		go_back(char ***env, int *return_value,
			__attribute__ ((unused)) int *fd)
{
  struct stat	statbuf;
  int		i;

  i = 0;
  while ((*env)[i] != NULL && strncmp("OLDPWD=", (*env)[i], 5) != 0)
    i++;
  if ((*env)[i] == NULL)
    {
      my_perror("cd: No previous directory.\n");
      *return_value = 1;
    }
  else if (stat(&(*env)[i][7], &statbuf) == -1 || !S_ISDIR(statbuf.st_mode))
    {
      my_perror("cd: Can't change to previous directory.\n");
      *return_value = 1;
    }
  else
    {
      change_back(env, &(*env)[i][7], return_value);
      *return_value = 0;
    }
}
