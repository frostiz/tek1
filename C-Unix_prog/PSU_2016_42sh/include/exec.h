/*
** exec.h for  in /home/bastien/delivery/PSU/PSU_2016_42sh
**
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
**
** Started on  Tue May 16 16:21:30 2017 bastien bedu
** Last update Mon May 22 15:33:52 2017 Vincent Roye
*/

#ifndef EXEC_H_
# define EXEC_H_

char	*get_current_dir_name();
char	**my_split(char *, char);
char	**get_path(char **);
char	*my_str_in_str(char *, char *);
char	*my_strcat_path(char **, char *);
char	*which_access(char *, char **);
char	*where_access(char *, char **);
char	*backticks(char *, char ***);
int	pipe2(int *, int);
int	is_slash(char *);
int	my_access(char *, int, int);
int	compare_builtin(char *, char **);
int	check_which_error(char **, char **, int *);
int	check_where_error(char **, char **, int *);
int	signal_handle(int, int);
int	array_len(char **);
int	my_tablen(char **);
int	my_strlen(char *);
int	is_int(char *);
int	move(char *, int *, int);
int	execute_command(char **, int *, char **, char *);
int	check_builtin(char **, int *, char ***, int *);
void	epur_line(char *);
void	parse_built(char **, char ***, int *, int *);
void	my_swap(char **, char **);
void	my_close(int);
void	my_perror(char *);
void	my_free_tab(char **);

#endif /* EXEC_H_ */
