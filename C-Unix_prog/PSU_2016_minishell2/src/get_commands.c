/*
** get_commands.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Mon May  1 12:14:20 2017 Thibaut Trouvé
** Last update Wed May  3 06:05:59 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "main.h"

t_cmd	*add_commands(t_cmd *cmd, char *str_args)
{
  t_cmd	*tmp;
  t_cmd	*new;

  epure_space(str_args);
  new = malloc(sizeof(t_cmd));
  if (new == NULL)
    return (NULL);
  new->output = NULL;
  new->input = NULL;
  new->next = NULL;
  new->args = full_command_to_wordtab(str_args, ' ');
  if (new->args == NULL)
    return (NULL);
  if (cmd == NULL)
    return (new);
  tmp = cmd;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (cmd);
}

t_cmd	*get_commands(t_cmd *cmd, char *str)
{
  char	**split_semicolon;
  int	i;

  i = 0;
  split_semicolon = full_command_to_wordtab(str, ';');
  if (split_semicolon == NULL)
    return (NULL);
  while (split_semicolon[i])
    {
      cmd = add_commands(cmd, split_semicolon[i]);
      i++;
    }
  return (cmd);
}
