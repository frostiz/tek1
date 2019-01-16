/*
** head_name.c for corewar in /home/dubret_v/delivery/semestre2/CPE/CPE_2016_corewar
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 29 07:45:14 2017 dubret_v
** Last update Sun Apr  2 21:13:34 2017 dubret_v
*/

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "op.h"

int	count_apo(char *name)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (name[i] != '\0')
    {
      if (name[i] == '"')
	count++;
      i++;
    }
  if (count != 2)
    return (1);
  return (0);
}

int	check_len(char *stock, int len, char *name)
{
  int		i;
  int		count;

  i = my_strlen(name);
  count = 0;
  while (stock[i] != '"' && stock[i] != '\0')
    i++;
  i++;
  while (stock[i] != '"' && stock[i] != '\0')
    {
      count++;
      i++;
    }
  if (count > len)
    {
      my_put_error("Programme ");
      my_put_error(name);
      my_put_error(" is too long\n");
      return (1);
    }
  return (0);
}

static	void	stock_zero(char str[], int prog_len)
{
  int		i;

  i = 0;
  while (i < prog_len)
    {
      str[i] = '\0';
      i++;
    }
}

int	my_header(char **stock, t_header *head)
{
  char	*name;
  char	*comment;

  stock_zero(head->prog_name, PROG_NAME_LENGTH);
  stock_zero(head->comment, COMMENT_LENGTH);
  name = get_name_comment(stock, NAME_CMD_STRING);
  comment = NULL;
  if (error_message(comment, name, head, stock) == 1)
    return (1);
  return (0);
}

int		put_name_comment(int fd, char **stock, t_header	*head)
{
  if (my_header(stock, head) == 1)
    return (1);
  head->prog_size = 0;
  write_invert(fd, head->magic);
  write(fd, head->prog_name, PROG_NAME_LENGTH);
  head->prog_size = 0;
  write(fd, &head->prog_size, sizeof(int));
  head->prog_size = 151;
  write_invert(fd, head->prog_size);
  write(fd, head->comment, COMMENT_LENGTH);
  head->prog_size = 0;
  write(fd, &head->prog_size, sizeof(int));
  return (0);
}
