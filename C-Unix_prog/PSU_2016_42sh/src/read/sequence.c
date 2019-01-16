/*
** sequence.c for sequence.c in /home/roye_v/delivery/PSU_2016_42sh
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 21 14:37:09 2017 Vincent Roye
** Last update Sun May 21 22:01:21 2017 Thibaut Trouvé
*/

#include	<stdlib.h>
#include	<string.h>
#include	"read.h"

int		which_sequences(t_keys *keys, char *buff)
{
  char		*sequences[6];
  int		i;

  sequences[0] = keys->up;
  sequences[1] = keys->right;
  sequences[2] = keys->down;
  sequences[3] = keys->left;
  sequences[4] = keys->remove;
  sequences[5] = NULL;
  i = 0;
  while (sequences[i] != NULL)
    {
      if (strcmp(sequences[i], buff) == 0)
	return (i);
      i++;
    }
  return (-1);
}

char		*known_sequences(int ret, int *cursor,
				 char *str, t_hist *hist)
{
  char		*(*keys_tab[5])(char *, int *, t_hist *);

  keys_tab[0] = keys_up;
  keys_tab[1] = keys_right;
  keys_tab[2] = keys_down;
  keys_tab[3] = keys_left;
  keys_tab[4] = keys_remove;
  if ((str = keys_tab[ret](str, cursor, hist)) == NULL)
    return (NULL);
  return (str);
}

int		which_control_sequences(char *buff)
{
  int		sequences[10];
  int		i;

  i = 0;
  sequences[0] = BACKLINE;
  sequences[1] = CTRL_A;
  sequences[2] = CTRL_E;
  sequences[3] = CTRL_D;
  sequences[4] = CTRL_L;
  sequences[5] = DEL;
  sequences[6] = CTRL_G;
  sequences[7] = CTRL_N;
  sequences[8] = CTRL_O;
  sequences[9] = CTRL_H;
  while (i <= 9)
    {
      if (buff[0] == sequences[i] && buff[1] == 0)
	return (i);
      i++;
    }
  return (-1);
}

int		control_sequences(int ret, int *cursor, char *str)
{
  int		value;
  int		(*control_tab[10])(char *, int *);

  control_tab[0] = control_backline;
  control_tab[1] = control_a;
  control_tab[2] = control_e;
  control_tab[3] = control_d;
  control_tab[4] = control_l;
  control_tab[5] = control_del;
  control_tab[6] = control_g;
  control_tab[7] = control_n;
  control_tab[8] = control_o;
  control_tab[9] = control_h;
  value = control_tab[ret](str, cursor);
  return (value);
}
