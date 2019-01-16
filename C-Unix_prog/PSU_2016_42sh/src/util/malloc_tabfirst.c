/*
** malloc_tabfirst.c for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
**
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
**
** Started on  Sun May 21 14:41:44 2017 dubret_v
** Last update Sun May 21 19:18:05 2017 dubret_v
*/

#include		<stdlib.h>
#include		"mysh.h"

static	int		is_quotes(char *str, int i, int *count, int *ver)
{
  i = go_through_quotes(str, i + 1);
  *count += 1;
  *ver = 1;
  return (i);
}

static	int		is_not_quotes(int i, int *ver, int count)
{
  if (i == 0 || *ver == 0)
    count++;
  *ver = 1;
  return (count);
}

char		**malloc_tabfirst(char *str, char c)
{
  char		**tab;
  int		i;
  int		count;
  int		ver;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '"')
	i = is_quotes(str, i, &count, &ver);
      else if (str[i] != c && str[i] != '\0')
	count = is_not_quotes(i, &ver, count);
      else
	ver = 0;
      if (str[i] != '\0' && str[i] != '"')
	i++;
    }
  tab = malloc(sizeof(char *) * (count + 1));
  if (tab == NULL)
    return (NULL);
  tab[count] = NULL;
  return (tab);
}
