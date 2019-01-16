/*
** asm.c for corewar in /home/dubret_v/delivery/semestre2/CPE/CPE_2016_corewar/ASM/src
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu@epitech.net>
** 
** Started on  Tue Mar 28 17:14:57 2017 dubret_v
** Last update Sun Apr  2 20:55:01 2017 Vincent Roye
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include "op.h"
#include "asm.h"
#include "my.h"
#include "get_next_line.h"

static void	init_values(int *i, int *line, int *first_dot)
{
  *i = 0;
  *line = 0;
  *first_dot = 0;
}

void	check_name_comment(char **stock)
{
  int	line;
  int	i;
  int	first_dot;

  init_values(&i, &line, &first_dot);
  while (stock[line] != NULL && first_dot != 1)
    {
      while (stock[line][i] != '\0')
	{
	  if (stock[line][i] == NAME_CMD_STRING[0])
	    {
	      first_dot += 1;
	      if (check_name(stock[line], i) == 0)
		check_comment_line(stock, line + 1);
	    }
	  else if (stock[line][i] != ' ' &&
		   stock[line][i] != '\t' &&
		   stock[line][i] != '\0' &&
		   first_dot == 0)
	    my_error_exit("Your champion hasn't name :(\n");
	  i++;
	}
      i = 0;
      line++;
    }
}

int		fill_label(t_label **label, char **stock)
{
  int		i;
  int		line;
  int		ok;

  ok = 0;
  i = 0;
  line = 0;
  while (stock[line] != NULL)
    {
      while (stock[line][i] != '\0')
	{
	  if (i > 0)
	    {
	      if (stock[line][i] == LABEL_CHAR && stock[line][i - 1] != '%')
		{
		  if (my_label_copy(stock[line], &*label, line + 1) == 1)
		    ok = 1;
		}
	    }
	  i++;
	}
      i = 0;
      line++;
    }
  return (ok);
}

static int	checker(t_label *label, char **stock,
			char *champion, t_parse_write parse_w)
{
  if (fill_label(&label, stock) == 1)
    return (1);
  if (multiple_label(label) == 1)
    return (1);
  if (check_file_syntax(stock) == 1)
    return (1);
  if (fill_parse_w(&parse_w, stock) == 1)
    return (1);
  if (header(champion, stock) == 1)
    return (1);
  return (0);
}

int		my_asm(char *champion)
{
  t_parse_write	parse_w;
  t_label	*label;
  t_elem	*list;
  int		fd;
  char		*s;
  char		**stock;

  fd = open(champion, O_RDONLY);
  if (fd == -1)
    {
      my_printf("%s doesn't exist\n", champion);
      return (1);
    }
  label = NULL;
  list = NULL;
  while ((s = get_next_line(fd)) != NULL)
    list = addlist(list, s);
  close(fd);
  stock = my_chain_to_wordtab(list);
  if (stock == NULL)
    return (1);
  epure_str(stock);
  check_name_comment(stock);
  return (checker(label, stock, champion, parse_w));
}
