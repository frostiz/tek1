/*
** is_num.c for is_alphanum.c in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Tue Apr  4 20:27:06 2017 Thibaut Trouvé
** Last update Tue Apr  4 20:33:04 2017 Thibaut Trouvé
*/

int	is_alphanum(char c)
{
  if ((c < '0' || c > '9') &&
      (c < 'A' || c > 'Z') &&
      (c < 'a' || c > 'z') &&
      c != '\0')
    return (0);
  else
    return (1);
}
