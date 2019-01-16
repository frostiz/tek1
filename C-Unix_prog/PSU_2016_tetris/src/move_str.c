/*
** move_str.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Thu Mar  9 16:01:12 2017 Sahel
** Last update Thu Mar  9 16:04:20 2017 Sahel
*/

void	move_str(char *s1, char *s2)
{
  int	str_i;

  str_i = 0;
  while (s2[str_i])
    {
      s1[str_i] = s2[str_i];
      str_i++;
    }
  s1[str_i] = '\0';
}
