/*
** stockage.c for stockage.c in /home/frostiz/CPE_2016_BSQ
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Dec 14 20:49:19 2016 thibaut trouve
** Last update Wed Dec 14 21:12:27 2016 thibaut trouve
*/

#include "my.h"

char	**loop_stock(t_stock stk)
{
  while (read(stk.fd, stk.buffer, stk.line_len + 1) != 0)
    {
      while (stk.buffer[stk.i] != '\0')
	{
	  stk.tab[stk.k][stk.j] = stk.buffer[stk.i];
	  (stk.i)++;
	  (stk.j)++;
	  if (stk.buffer[stk.i] == '\n' && stk.buffer[stk.i + 1] == '\0')
	    {
	      stk.tab[stk.k][stk.j] = '\0';
	      (stk.i)++;
	      (stk.j) = 0;
	      (stk.k)++;
	      stk.tab[stk.k] = malloc(sizeof(char) * (stk.line_len + 1));
	      if (stk.tab[stk.k] == NULL)
		return (NULL);
	    }
	}
      stk.i = 0;
    }
  return (stk.tab);
}

char	**stock(char **argv)
{
  t_stock stk;

  stk.i = 0;
  stk.j = 0;
  stk.k = 0;
  stk.nb_line = count_lines(argv, &(stk.line_len));
  if (stk.line_len == 1)
    map_one_column(argv);
  else if (stk.line_len == -1)
    return (NULL);
  if ((stk.tab = (void *)malloc(sizeof(char*) * stk.nb_line + 1)) == NULL)
    return (NULL);
  if ((stk.tab[0] = (void *)malloc(sizeof(char) * (stk.line_len + 1))) == NULL)
    return (NULL);
  stk.fd = open(argv[1], O_RDONLY);
  read(stk.fd, stk.buffer, beginning(argv));
  stk.tab = loop_stock(stk);
  close(stk.fd);
  return (stk.tab);
}
