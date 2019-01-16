/*
** fill_parse_w.c for corewar in /home/dubret_v/delivery/semestre2/CPE/CPE_2016_corewar
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 29 22:42:45 2017 dubret_v
** Last update Sun Apr  2 11:19:20 2017 dubret_v
*/

#include <stdlib.h>
#include "asm.h"
#include "op.h"
#include "my.h"

static int	after_comment(char **stock, t_parse *parse)
{
  init_struct(parse);
  parse->idx_line = 0;
  if (get_start(&parse->idx_start, stock[parse->idx_line], &parse->line) == 1)
    {
      my_printf("Invalid comment\n");
      return (1);
    }
  while (my_strcmp(get_first_word(parse, stock), COMMENT_CMD_STRING) != 0
	 && stock[parse->idx_line] != NULL)
    {
      parse->idx_line++;
      get_start(&parse->idx_start, stock[parse->idx_line], &parse->line);
    }
  if (stock[parse->idx_line] == NULL)
    {
      my_printf("Invalid comment\n");
      return (1);
    }
  parse->idx_line++;
  return (0);
}

void	get_second_start(int *start, char *line, char **cleaned_line)
{
  while (line[*start] != '\0' &&
	 (line[*start] == ' ' ||
     	  line[*start] == '\t'))
    (*start)++;
  *cleaned_line = &line[*start];
}

static	void	check_is_label(t_parse *parse, char **stock)
{
  int		i;
  int		len;

  i = 0;
  len = my_strlen(parse->first_word);
  while (stock[parse->idx_line][i] != LABEL_CHAR &&
	 stock[parse->idx_line][i] != '\0')
    i++;
  if (len == 0)
    return ;
  if (parse->first_word[len - 1] == LABEL_CHAR)
    {
      parse->idx_start = i + 1;
      get_second_start(&parse->idx_start,
		       stock[parse->idx_line], &parse->line);
      parse->first_word = get_first_word(parse, stock);
    }
}

int		fill_parse_w(t_parse_write *parse_w, char **stock)
{
  t_parse	parse;

  if (after_comment(stock, &parse) == 1)
    return (1);
  parse_w = NULL;
  while (stock[parse.idx_line] != NULL)
    {
      get_start(&parse.idx_start, stock[parse.idx_line], &parse.line);
      parse.first_word = get_first_word(&parse, stock);
      if (parse.first_word == NULL)
	return (1);
      check_is_label(&parse, stock);
      if (my_strlen(parse.first_word) != 0)
	parse_w = add_parse_w(parse_w, parse, stock);
      parse.idx_line++;
    }
  return (0);
}
