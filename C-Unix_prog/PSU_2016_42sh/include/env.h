/*
** exec.h for  in /home/bastien/delivery/PSU/PSU_2016_42sh
**
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
**
** Started on  Tue May 16 16:21:30 2017 bastien bedu
** Last update Sat May 20 13:04:01 2017 bastien bedu
*/

#ifndef ENV_H_
# define ENV_H_

char	*get_mod_str(char **, char *);
char	*my_strdup_to(char *, int);
char	*value_of(char **, char *);
int	add_var(char *, char *, char *, int *);
int	get_env_of(char *, int, char **, char **);
int	my_strcomp(char *, char *);
int	is_alphanum(char);
int	is_char_alphanum(char);

#endif /* ENV_H_ */
