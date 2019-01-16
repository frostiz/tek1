/*
** core.c for core.c in /home/frostiz/CPE_2016_BSQ
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Tue Dec  6 12:51:25 2016 thibaut trouve
** Last update Wed Dec 14 20:53:19 2016 thibaut trouve
*/

#include "my.h"

void	init_struct(t_count *i)
{
  i->i = 0;
  i->j = 0;
  i->tmp = 0;
  i->max = 0;
  i->posx = 0;
  i->posy = 0;
}

void	algo(char **tab)
{
  t_count count;

  init_struct(&count);
  while (tab[count.i] != NULL)
    {
      while (tab[count.i][count.j] != '\0')
	{
	  if (tab[count.i][count.j] == '.')
	    {
	      count.tmp = check(tab, count.i, count.j);
	      if (count.tmp > count.max)
		{
		  count.max = count.tmp;
		  count.posx = count.j;
		  count.posy = count.i;
		}
	    }
	  (count.j)++;
	}
      count.j = 0;
      (count.i)++;
    }
  if (check_filled(tab) == 0)
    replace_point(count.posx, count.posy, count.max, tab);
}

int	count_lines(char **argv, int *line_len)
{
  int	fd;
  char	lign[100000];
  int	nb_line;

  nb_line = 0;
  fd = open(argv[1], O_RDONLY);
  if (fd == -1)
	  return (-1);
  read(fd, lign, 100000);
  close(fd);
  *line_len = lign_lenght(lign);
  fd = open(argv[1], O_RDONLY);
  read(fd, lign, beginning(argv));
  while (read(fd, lign, *line_len) != 0)
      nb_line++;
  close(fd);
  return (nb_line);
}

int	main(int argc, char **argv)
{
  char	**tab;
  int	i;

  i = 0;
  (void)argc;
  tab = stock(argv);
  if (tab == NULL)
    return (84);
  check_empty(tab);
  algo(tab);
  aff_loop(tab);
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
  return (0);
}
