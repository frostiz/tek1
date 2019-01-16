/*
** add_parse_w.c for corewar in /home/dubret_v/delivery/semestre2/CPE/CPE_2016_corewar/asm/src
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu@epitech.net>
** 
** Started on  Sun Apr  2 11:11:53 2017 dubret_v
** Last update Sun Apr  2 11:22:52 2017 dubret_v
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"
#include "asm.h"

static	int		which_code(t_parse parse)
{
  int			i;

  i = 0;
  while (my_strcmp(parse.first_word, op_tab[i].mnemonique) != 0)
    i++;
  return ((int)op_tab[i].code);
}

static	int		how_bytes(char	**param, char *str)
{
  int			i;
  int			count;

  i = 0;
  count = 1;
  while (param[i] != NULL)
    {
      if (param[i][0] == 'r')
	count++;
      else if ((param[i][0] == DIRECT_CHAR) &&
	       (my_strcmp(str, "zjmp") != 0) &&
	       (my_strcmp(str, "ldi") != 0) &&
	       (my_strcmp(str, "lldi") != 0))
	count += DIR_SIZE;
      else
	count += IND_SIZE;
      i++;
    }
  return (count);
}

t_parse_write	*add_parse_w(t_parse_write *parse_w,
			     t_parse parse, char **stock)
{
  t_parse_write	*tmp;
  t_parse_write	*new_elem;

  new_elem = malloc(sizeof(t_parse_write));
  if (new_elem == NULL)
    return (NULL);
  tmp = parse_w;
  new_elem->command = my_strdup(parse.first_word);
  if (new_elem->command == NULL)
    return (NULL);
  new_elem->command_size = which_code(parse);
  new_elem->param = my_str_to_wordtab(stock[parse.idx_line] +
				      (my_strlen(parse.first_word) + 1),
				      SEPARATOR_CHAR);
  if (new_elem->param == NULL)
    return (NULL);
  new_elem->bytes = how_bytes(new_elem->param, new_elem->command);
  new_elem->next = NULL;
  if (parse_w == NULL)
    return (new_elem);
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_elem;
  return (parse_w);
}
