/*
** label_copy.c for label_copy.c in /home/roye_v/delivery/CPE_2016/CPE_2016_corewar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr  2 10:45:36 2017 Vincent Roye
** Last update Sun Apr  2 19:39:00 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

static void	copy_this(char *tmp, char *to_copy,
			  int *i, int *j)
{
  tmp[*j] = to_copy[*i];
  (*i)++;
  (*j)++;
}

static void	write_error(char *tmp)
{
  my_put_error("Label error : ");
  my_put_error(tmp);
  my_put_error("\n");
}

static	void	init_values(int *i, int *j)
{
  *i = 0;
  *j = 0;
}

int	my_label_copy(char *to_copy, t_label **label,
		      int line)
{
  int	i;
  int	j;
  char	*tmp;

  init_values(&i, &j);
  tmp = malloc(sizeof(char) * (my_strlen(to_copy) + 1));
  if (tmp == NULL)
    my_error_exit("Error while allocating memory\n");
  while ((to_copy[i] != '\0' && to_copy[i] == ' ') ||
	 (to_copy[i] != '\0' && to_copy[i] == '\t'))
    i++;
  while (to_copy[i] != '\0' && to_copy[i] != LABEL_CHAR)
    copy_this(tmp, to_copy, &i, &j);
  tmp[j] = '\0';
  if (valid_label(tmp) == 0)
    {
      *label = addlabel(*label, tmp, line);
      return (0);
    }
  else
    {
      write_error(tmp);
      return (1);
    }
  return (0);
}
