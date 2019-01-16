/*
** header.c for corewar in /home/dubret_v/delivery/semestre2/CPE/CPE_2016_corewar/ASM/src
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 29 07:43:04 2017 dubret_v
** Last update Sun Apr  2 21:13:16 2017 dubret_v
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "my.h"
#include "asm.h"

static	char	*create_champ(char *champion)
{
  char		*champ;
  int		i;
  int		j;

  champ = malloc(sizeof(char) * (my_strlen(champion) + 3));
  i = my_strlen(champion);
  j = 0;
  while (i > 0 && champion[i] != '/')
    i--;
  if (i != 0)
    i++;
  while (champion[i] != '.' && champion[i] != '\0')
    {
      champ[j] = champion[i];
      j++;
      i++;
    }
  champ[j] = '\0';
  champ = my_strcat(champ, ".cor");
  return (champ);
}

int		header(char *champion, char **stock)
{
  t_header	*header;
  int		fd;
  char		*champ;

  header = malloc(sizeof(t_header));
  if (header == NULL)
    return (1);
  champ = create_champ(champion);
  fd = open(champ, O_CREAT| O_RDWR | O_TRUNC, 0777);
  if (fd == -1)
    {
      my_printf("Invalid file : %s\n", champ);
      return (1);
    }
  free(champ);
  if (fd == -1)
    {
      my_put_error("Could not create the champ\n");
      return (1);
    }
  header->magic = (int)COREWAR_EXEC_MAGIC;
  if (put_name_comment(fd, stock, header) == 1)
    return (1);
  return (0);
}
