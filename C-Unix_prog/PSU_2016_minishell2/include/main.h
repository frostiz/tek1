/*
** main.h for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Mon Apr  3 21:00:49 2017 Thibaut Trouvé
** Last update Wed May  3 06:19:22 2017 Thibaut Trouvé
*/

#ifndef MAIN_H_
# define MAIN_H_

# define SIMPLE_LEFT 10
# define DOUBLE_LEFT 11
# define PIPE 12
# define SIMPLE_RIGHT 13
# define DOUBLE_RIGHT 14

#include <unistd.h>

typedef struct  s_cmd
{
  struct s_cmd  *next;
  char		**args;
  char		*input;
  char		*output;
}               t_cmd;

typedef struct	s_split
{
  struct s_split	*next;
  char			**real_cmd;
}		t_split;

typedef struct	s_tabs
{
  struct s_cmd	*cmd;
  char		*input;
  char		**my_env;
  int		exit_value;
}		t_tab;

typedef struct	s_count
{
  int		col;
  int		line;
  int		idx;
}		t_count;

typedef struct	s_pipe
{
  int		save_fd;
  int		output_fd;
  int		input_fd;
  pid_t		*pid;
  int		**pipe_fdtab;
  int		status;
  char		*progname;
  int		idx_pipe;
}		t_pipe;

char	*get_next_line(const int fd);
void	interpret_status(int *);
int	interpret_path(char *, t_tab **, char **);
void	sign_handler(int);
char	**get_args(char *);
void	epure_space(char *);
int	check_cmd_error(t_cmd *, int *);
t_cmd	*get_commands(t_cmd *, char *);
int	check_syntax_error(char **);
int	exec_all_commands(t_tab **, int);
char	*epure_semicolon(char *);
int	interpret_args(t_tab **, char **);
void	catch_signals();
int	exec(char **, t_tab *, char *, char **);
int	exec_redirected_piped(char ***, t_tab **, int);
int	exec_simple_command(t_tab **, char **);
char	*get_var_env_value(char **, char *);
int	check_setenv_errors(char **, t_tab **);
int	check_cd_errors(char **);
char	*find_path(char **, char **);
int	is_in(char, char *);
int	count_separator(char *);
void	display_env(char **, t_tab **);
void	my_setenv(char **, t_tab **);
void	my_unsetenv(char **, t_tab **);
void	my_cd(char **, t_tab **);
void	my_exit(char **, t_tab **);
void	ill_without(int *);
void	abort_without(int *);
void	bus_without(int *);
void	float_without(int *);
void	seg_without(int *);
void	ill_with(int *);
void	abort_with(int *);
void	bus_with(int *);
void	float_with(int *);
void	seg_with(int *);
int	search_in_env(char *, char **);
int	check_builtin(char **);
char	***my_wordtab_to_arrtab(char **, char *);
int	exec_builtin(int, char **, t_tab **);
int	is_dir(char *);
int	start_piped(char **, t_tab **);
int	start_redirected(char **, t_tab **);
char	*check_redirect_pipe(char **);
char	**my_str_to_wordtab(char *, char *);
int	minishell2(char **, t_tab *);
int	mainloop(t_tab *);
char	*epure_input(char *);
int	is_left_double_redir(char **);
int	exec_double_left(t_split *, int *, t_tab **);
int	open_files(int *, int *, t_tab **, char **);
int	exec_complex_command(t_tab **, char **);
int	is_right_simple_redir(char **);
int	is_left_simple_redir(char **);
char	**extract_cmd(char **, int, char);
int	init_struct_pipe(t_pipe *, char **);
t_split	*split_cmd(t_split *, char **);
void	exec_builtin_middle(t_tab **, int *, t_split *);
int	exec_simple_left(t_split *, int, int *, t_tab **);
int	exec_simple_right(t_split *, int, int *, t_tab **);
int	open_failure(char *, t_tab **);
char	*get_file(char **, char *);
void	check_inverted(t_cmd *);
int	check_invalid_syntax(t_cmd *);
int	check_ambiguous(t_cmd *);
int	check_input(char **, int);
int	check_output(char **, int);
char	*interpret_truepath(char *);
char	**full_command_to_wordtab(char *, char);

#endif	/* MAIN_H_ */
