/*
** my_perror.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Mon May 15 09:53:28 2017 Lucas Dumy
** Last update Sun May 21 16:37:35 2017 Lucas Dumy
*/

#include	<unistd.h>
#include	<string.h>
#include	"mysh.h"

void		my_perror(char *str)
{
  write(2, str, strlen(str));
}

int		my_put_error(char *str, int ret)
{
  my_perror(str);
  return (ret);
}
