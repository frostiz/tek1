/*
** is_char.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Apr  9 17:16:46 2017 Thibaut Trouvé
** Last update Sun Apr  9 17:17:26 2017 Thibaut Trouvé
*/

int	is_in(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (c == str[i])
	return (1);
      i++;
    }
  return (0);
}
