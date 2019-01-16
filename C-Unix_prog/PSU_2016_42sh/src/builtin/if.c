/*
** if.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Sun May 21 10:56:00 2017 bastien bedu
** Last update Sun May 21 13:04:17 2017 bastien bedu
*/

#include	<stdlib.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"exec.h"

void		my_if(char **args, char ***env, int *return_value, int *fd)
{
  int		nb;

  if (my_tablen(args) < 2)
    {
      my_perror("if: Too few arguments.\n");
      *return_value = 1;
      return ;
    }
  if (is_int(args[1]) == 1)
    nb = atoi(args[1]);
  else
    {
      my_perror("if: Expression Syntax.\n");
      *return_value = 1;
      return ;
    }
  if (my_tablen(args) < 3)
    {
      *return_value = 1;
      my_perror("if: Empty if.\n");
    }
  else if (nb != 0)
    parse_built(&args[2], env, return_value, fd);
}
