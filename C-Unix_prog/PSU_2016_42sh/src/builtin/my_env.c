/*
** env.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Wed May 17 14:26:21 2017 Lucas Dumy
** Last update Thu May 18 20:49:17 2017 Lucas Dumy
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"mysh.h"

void		my_env(char **tab, char ***env, int *return_value,
		       __attribute__ ((unused)) int *fd)
{
  struct stat	statbuf;

  if (tab[1] == NULL)
    {
      my_show_wordtab(*env);
      *return_value = 0;
    }
  else if (stat(tab[1], &statbuf) == -1)
    {
      my_perror("env: '");
      my_perror(tab[1]);
      my_perror("’: No such file or directory\n");
      *return_value = 1;
    }
  else
    {
      my_perror("env: ‘");
      my_perror(tab[1]);
      my_perror("’: Permission denied\n");
      *return_value = 1;
    }
}
