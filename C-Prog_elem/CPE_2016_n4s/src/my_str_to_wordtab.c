/*
** my_str_to_wordtab.c for n4s in /home/DxCube/CPE_2016_n4s
** 
** Made by Victor Dubret
** Login   <DxCube@epitech.net>
** 
** Started on  Sun Jun  4 20:50:29 2017 Victor Dubret
** Last update Sun Jun  4 20:50:30 2017 Victor Dubret
*/

#include <stdlib.h>
#include "n4s.h"

static t_wordtab	init_struct()
{
  t_wordtab	count;

  count.idx = 0;
  count.line = 0;
  count.col = 0;
  return (count);
}

static int	newline(t_wordtab *count, char *str, char **tab)
{
  tab[count->line][count->col] = '\0';
  count->line++;
  count->col = 0;
  tab[count->line] = malloc(sizeof(char) * (my_strlen(str) + 1));
  if (tab[count->line] == NULL)
    return (84);
  return (0);
}

static int	copy_char(t_wordtab *count, char *str, char **tab)
{
  tab[count->line][count->col] = str[count->idx];
  count->col++;
  return (0);
}

char	**my_str_to_wordtab(char *str, char sep)
{
  t_wordtab	count;
  char		**tab;

  count = init_struct();
  tab = malloc(sizeof(char *) * (my_strlen(str) + 1));
  if (tab == NULL)
    return (NULL);
  tab[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
  if (tab[0] == NULL)
    return (NULL);
  while (str[count.idx] != '\0')
    {
      if (str[count.idx] == sep)
	newline(&count, str, tab);
      else
	copy_char(&count, str, tab);
      count.idx++;
    }
  tab[count.line] = NULL;
  return (tab);
}
