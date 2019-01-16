/*
** sp_len_.c for  in /home/sahel/rendu
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Feb 25 17:15:32 2017 Sahel
** Last update Sat Feb 25 17:16:15 2017 Sahel
*/

int	sp_len_(char *str, char c)
{
  int	str_i;

  str_i = 0;
  while (str[str_i] && str[str_i] != c)
    str_i++;
  return (str_i);
}
