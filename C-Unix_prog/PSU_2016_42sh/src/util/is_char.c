/*
** is_char.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Sat May 20 12:32:07 2017 bastien bedu
** Last update Sat May 20 12:32:36 2017 bastien bedu
*/

int		is_char_alphanum(char c)
{
  if ((c < '0' || (c > '9' && c < 'A') ||
       (c > 'Z' && c < 'a') || c > 'z') && c != '_')
    return (0);
  return (1);
}
