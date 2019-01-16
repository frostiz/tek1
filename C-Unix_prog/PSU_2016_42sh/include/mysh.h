/*
** 42sh.h for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
**
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
**
** Started on  Sat May 13 15:44:45 2017 dubret_v
** Last update Sun May 21 21:44:19 2017 dubret_v
*/

#ifndef MYSH_H_
# define MYSH_H_

typedef	struct		s_graph
{
  char			*command;
  int			limit;
  struct s_graph	*left;
  struct s_graph	*right;
}			t_graph;

void			my_prompt(int);
void			count_redir(int *, int, int *);
void			free_graph(t_graph *);
void			go_back(char ***, int *, int *);
void			go_home(char ***, int *, int *);
void			my_cd(char **, char ***, int *, int *);
void			my_which(char **, char ***, int *, int *);
void			my_where(char **, char ***, int *, int *);
void			my_echo(char **, char ***, int *, int *);
void			my_env(char **, char ***, int *, int *);
void			repeat(char **, char ***, int *, int *);
void			my_if(char **, char ***, int *, int *);
void			my_exit(char **, char ***, int *, int *);
void			my_free_tab(char **);
void			my_perror(char *);
void			my_putstr(char *);
void			my_setenv(char **, char ***, int *, int *);
void			my_show_wordtab(char **);
void			my_unsetenv(char **, char ***, int *, int *);
void			remove_character(char *, unsigned int);
void			remove_all_quotes(char **);
void			remove_spare_spaces(char *);
void			set_pwd(char ***, char *, char *);
void			set_term2();
void			set_value(int *, int, int);
void			show_graph(t_graph *, char *);
void			cpy_inside_quotes(char *, char *, int *);

int			check_builtin(char **, int *, char ***, int *);
int			check_clear(char *);
int			count_lines(char **);
int			find_limit(char **, int *);
int			for_error_checking(t_graph *);
int			get_backslash(char *);
int			glob_and_cmp(char *, char *, int *, int *);
int			invalid_and(t_graph *);
int			invalid_pipe(t_graph *);
int			invalid_redir(t_graph *);
int			is_and(t_graph *);
int			is_pipe(t_graph *);
int			is_redir(t_graph *);
int			mode(int);
int			my_access(char *, int, int);
int			my_has_slash(char *);
int			my_is_alphanum(char *);
int			my_is_glob(char *);
int			my_put_error(char *, int);
int			is_only_parentheses(char *);
int			find_parentheses(int *, char **, int, int);
int			go_through_quotes(char *, int, char);

char			*my_epur_str(char *, int *);
char			*my_strcat(char *, char *);
char			*modify_for_redir(char *, int *, int);
char			*read_command();

char			**my_envdup(char **, int, int *);
char			**create_builtins_array();
char			**globbing(char **);
char			***create_pwd(char ***, int *);
char			**replace_tab(char **, char *, char);
char			**malloc_tab(char **, char *, char);
char			**malloc_tabfirst(char *, char);

t_graph			*add_node(char *);
t_graph			*create_graph(char *);

int			*wait_all(int *);
int			*create_value(int);
void			fd_reset(int *, int *, int);

int			split_command(t_graph *, char ***);
int			*and_bin(t_graph *, char ***, int *, void **);
int			*cat_values(int *, int *);
int			*coma_bin(t_graph *, char ***, int *, void **);
int			*command_sep(t_graph *, char ***, int *, void **);
int			*d_left(t_graph *, char ***, int *, void **);
int			*d_redir(t_graph *, char ***, int *, void **);
int			*left_redir(t_graph *, char ***, int *, void **);
int			*or_bin(t_graph *, char ***, int *, void **);
int			*parse_to_exec(t_graph *, char ***, int *, void **);
int			*pipe_split(t_graph *, char ***, int *, void **);
int			*right_redir(t_graph *, char ***, int *, void **);

#endif /* !MYSH_H_  */
