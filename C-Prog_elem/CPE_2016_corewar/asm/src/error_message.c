/*
** error_message.c for corewar in /home/dubret_v/delivery/semestre2/CPE/CPE_2016_corewar
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu@epitech.net>
** 
** Started on  Sun Apr  2 11:59:54 2017 dubret_v
** Last update Sun Apr  2 21:13:56 2017 dubret_v
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"
#include "my.h"

static char	*my_name(char **stock, char *name_comment,
			 char *name, int i)
{
  name = my_strdup(&stock[i][my_strlen(name_comment) + 1]);
  if (name == NULL)
    return (NULL);
  return (name);
}

static char	*format_name_comment(char *str)
{
  char	*name_comment;
  int	i;
  int	j;

  i = 0;
  j = 0;
  name_comment = malloc(sizeof(char) * my_strlen(str) + 1);
  if (name_comment == NULL)
    return (NULL);
  while (str[i] != '"' && str[i] != '\0')
    i++;
  if (str[i] == '\0')
    return (NULL);
  i++;
  while (str[i] != '"' && str[i] != '\0')
    {
      name_comment[j] = str[i];
      i++;
      j++;
    }
  name_comment[j] = '\0';
  if (str[i] == '\0')
    return (NULL);
  return (name_comment);
}

char	*get_name_comment(char **stock, char *name_comment)
{
  int	i;
  int	j;
  char	*name;

  i = 0;
  name = NULL;
  while (stock[i] != NULL)
    {
      j = 0;
      while ((stock[i][j] == '\t' || stock[i][j] == ' ')
	     && stock[i][j] != '\0')
	j++;
      if (name_comment[0] == '\0')
	return (NULL);
      if (my_strncmp(&stock[i][j], name_comment,
		     my_strlen(name_comment) - 1) == 0)
	return (my_name(stock, name_comment, name, i));
      i++;
    }
  if (stock[i] == NULL)
    return (NULL);
  if (count_apo(name) == 1)
    return (NULL);
  return (name);
}

int	my_printf_error(char *str)
{
  my_printf(str);
  return (1);
}

int	error_message(char *comment, char *name, t_header *head, char **stock)
{
  if (name == NULL)
    return (my_printf_error("Invalid name\n"));
  comment = get_name_comment(stock, COMMENT_CMD_STRING);
  if (comment == NULL)
    return (my_printf_error("Invalid comment\n"));
  name = format_name_comment(name);
  if (name == NULL)
    return (my_printf_error("Invalid name\n"));
  comment = format_name_comment(comment);
  if (comment == NULL)
    return (my_printf_error("Invalid comment\n"));
  if (name[0] == '\0' || comment[0] == '\0')
    return (my_printf_error("Name and comment should'nt be NULL\n"));
  if (my_strlen(name) > PROG_NAME_LENGTH)
    return (my_printf_error("Invalid program name length\n"));
  if (my_strlen(comment) > COMMENT_LENGTH)
    return (my_printf_error("Invalid comment name length\n"));
  my_strcpy(head->prog_name, name);
  my_strcpy(head->comment, comment);
  if (check_len(head->prog_name, PROG_NAME_LENGTH, "name") == 1)
    return (my_printf_error("Invalid program name length\n"));
  if (check_len(head->comment, COMMENT_LENGTH, "comment") == 1)
    return (my_printf_error("Invalid comment name length\n"));
  return (0);
}
