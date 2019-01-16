/*
** my_putstr.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Mon May 15 10:04:11 2017 Lucas Dumy
** Last update Mon May 15 10:05:04 2017 Lucas Dumy
*/

#include	<unistd.h>
#include	<string.h>
#include	"mysh.h"

void		my_putstr(char *str)
{
  write(1, str, strlen(str));
}
