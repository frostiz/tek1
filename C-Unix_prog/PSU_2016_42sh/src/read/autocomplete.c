/*
** autocomplete.c for 42sh in /home/thibaut/Repository/PSU_2016_42sh
**
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
**
** Started on  Sun May 21 16:27:09 2017 Thibaut Trouvé
** Last update Sun May 21 23:00:01 2017 Lucas Dumy
*/

#include <sys/stat.h>
#include <stdio.h>
#include <term.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"
#include "mysh.h"

void	print_file(char **file, char *str, char *word)
{
  int	i;
  char	*tmp;

  i = 0;
  write(1, "\n", 1);
  while (file[i])
    {
      if (file[i][0] != '.')
	{
	  my_putstr(file[i]);
	  tmp = strdup(word);
	  tmp = realloc(tmp, strlen(tmp) + strlen(file[i]) + 1);
	  strcat(tmp, file[i]);
	  if (is_dir(tmp) == 1)
	    write(1, "/", 1);
	  free(tmp);
	  write(1, "\n", 1);
	}
      i++;
    }
  my_putstr("$> ");
  my_putstr(str);
}

static t_autocomplete	*init_string(char *str, int *cursor)
{
  t_autocomplete	*string;

  string = malloc(sizeof(t_autocomplete));
  if (string == NULL)
    return (NULL);
  string->before = get_before_word(str, cursor);
  if (string->before == NULL)
    return (NULL);
  string->word = get_word(str, cursor);
  if (string->word == NULL)
    return (NULL);
  string->after = get_after_word(str, cursor);
  if (string->after == NULL)
    return (NULL);
  return (string);
}

int	modify_line(char **str, t_autocomplete *string,
		    char *name, int *cursor)
{
  *str[0] = '\0';
  *str = realloc(*str, strlen(string->before) + strlen(string->after) +
		 strlen(name) + 2);
  if (*str == NULL)
    return (84);
  strcat(*str, string->before);
  strcat(*str, name);
  string->path = realloc(string->path,
			 strlen(string->path) + strlen(name) + 1);
  if (string->path == NULL)
    return (84);
  strcat(string->path, name);
  if (is_dir(string->path) == 1)
    strcat(*str, "/");
  *cursor = strlen(*str);
  return (0);
}

int	display_promptstr(char *str)
{
  char	*seq;

  seq = tgetstr("dl", NULL);
  if (seq == NULL)
    return (84);
  my_putstr(seq);
  my_putstr("$> ");
  my_putstr(str);
  return (0);
}

int	autocomplete(char **str, int *cursor)
{
  t_autocomplete	*string;
  char			**file;
  int			idx;

  idx = 0;
  string = init_string(*str, cursor);
  if (string == NULL)
    return (84);
  file = get_file(string);
  if (file == NULL)
    return (84);
  if (no_match(file, str, string, &idx) == 1)
    {
      my_free_tab(file);
      free(string->before);
      free(string->path);
      free(string->after);
      free(string->word);
      free(string);
      return (0);
    }
  if (modify_line(str, string, file[idx], cursor) == 84 ||
      display_promptstr(*str) == 84)
    return (84);
  return (0);
}
