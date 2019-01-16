/*
** set_pwd.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Thu May 18 17:41:04 2017 Lucas Dumy
** Last update Thu May 18 17:42:12 2017 Lucas Dumy
*/

#include	<stdlib.h>
#include	<string.h>
#include	"mysh.h"

void		set_pwd(char ***env, char *str1, char *str2)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while ((*env)[i] != NULL && strncmp(str1, (*env)[i], strlen(str1)) != 0)
    i++;
  while ((*env)[j] != NULL && strncmp(str2, (*env)[j], strlen(str2)) != 0)
    j++;
  if ((*env)[i] != NULL && (*env)[j] != NULL)
    {
      free((*env)[i]);
      (*env)[i] = my_strcat(str1, &(*env)[j][strlen(str2)]);
    }
}
