/*
** count_redir.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Sun May 21 16:51:01 2017 Lucas Dumy
** Last update Sun May 21 16:57:07 2017 Lucas Dumy
*/

#include	"mysh.h"

static void	init_nb_redir(int nb_redir[], int my_fd[])
{
  nb_redir[0] = 0;
  nb_redir[1] = 0;
  nb_redir[2] = 0;
  my_fd[0] = 0;
  my_fd[1] = 0;
}

void		count_redir(int nb_redir[], int limit, int my_fd[])
{
  if (limit == 0 || limit == 8)
    init_nb_redir(nb_redir, my_fd);
  else if (limit == 4 || limit == 6)
    nb_redir[0] += 1;
  else if (limit == 5 || limit == 7)
    nb_redir[1] += 1;
}
