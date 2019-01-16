/*
** check_instructions.c for corewar in /home/thibaut/Repository/CPE_2016_corewar
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Mar 29 01:27:07 2017 
** Last update Sun Apr  2 11:16:36 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"
#include "op.h"
#include "asm.h"

char	*get_first_word(t_parse *parse, char **tab)
{
  char	c;
  char	*first_word;

  if (tab == NULL || tab[parse->idx_line] == NULL)
    return (NULL);
  while (tab[parse->idx_line][parse->idx_start] != '\0' &&
	 tab[parse->idx_line][parse->idx_start] != ' ' &&
	 tab[parse->idx_line][parse->idx_start] != '\t')
    parse->idx_start++;
  c = tab[parse->idx_line][parse->idx_start];
  tab[parse->idx_line][parse->idx_start] = '\0';
  first_word = my_strdup(parse->line);
  if (first_word == NULL)
    return (NULL);
  tab[parse->idx_line][parse->idx_start] = c;
  return (first_word);
}

void	init_struct(t_parse *parse)
{
  parse->idx_start = 0;
  parse->idx_line = 0;
  parse->idx_instruction = 0;
  parse->line = NULL;
  parse->instruction = NULL;
  parse->first_word = NULL;
}

int	get_start(int *start, char *line, char **cleaned_line)
{
  if (line == NULL)
    return (1);
  *start = 0;
  while ((line[*start] != '\0' &&
	  line[*start] == ' ') ||
	 (line[*start] != '\0' &&
	  line[*start] == '\t'))
    (*start)++;
  *cleaned_line = &line[*start];
  return (0);
}

int	check_file_syntax(char **tab)
{
  t_parse	*parse;

  parse = malloc(sizeof(t_parse));
  init_struct(parse);
  parse->idx_line = 0;
  while (tab[parse->idx_line] != NULL)
    {
      if (get_start(&parse->idx_start, tab[parse->idx_line],
		    &parse->line) == 1)
	return (1);
      if ((parse->first_word = get_first_word(parse, tab)) == NULL)
	return (1);
      if (interpret_first_word(parse) == 1)
	return (1);
      parse->idx_line++;
    }
  return (0);
}
