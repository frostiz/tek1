/*
** my.h for my.h in /home/roye_v/delivery/CPE_2016/CPE_2016_corewar/ASM
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue Mar 28 15:19:17 2017 Vincent Roye
** Last update Sun Apr  2 21:12:55 2017 dubret_v
*/

#ifndef ASM_H_
# define ASM_H_
# include "op.h"

typedef struct	s_elem
{
  char		*value;
  struct s_elem	*next;
}		t_elem;

typedef struct		s_label
{
  int			line;
  char			*value;
  struct s_label	*next;
}			t_label;

typedef struct	s_coord
{
  int		x;
  int		y;
}		t_coord;

typedef struct	s_parse
{
  int		idx_start;
  int		idx_line;
  int		idx_instruction;
  char		*line;
  char		*instruction;
  char		*first_word;
}		t_parse;

typedef struct  s_type
{
  int		a;
  int		b;
  int		c;
}               t_type;

typedef	struct		s_parse_write
{
  char			*command;
  int			command_size;
  char			**param;
  int			bytes;
  char			*label;
  int			line_label;
  int			nb_byte_label;
  struct s_parse_write	*next;
}			t_parse_write;

void		my_put_error(char *);
void		display_list(t_elem *);
void		display_label(t_label *);
void		init_struct(t_parse *);
t_parse_write	*add_parse_w(t_parse_write *, t_parse, char **);
void		my_put_err(char);
void		my_put_error(char *);
void		my_error_exit(char *);
int		get_start(int *, char *, char **);
int		fill_parse_w(t_parse_write *, char **);
char		*get_next_line(int);
char		*get_first_word(t_parse *, char **);
void		print_tab(char **);
int		header(char *, char **);
int		put_name_comment(int, char **, t_header *);
int		my_asm(char *);
char		**my_str_to_wordtab(char *, char);
int		check_files_extension(char **);
char		*get_next_line(int);
char		**my_chain_to_wordtab(t_elem *);
char		**my_label_to_wordtab(t_label *);
t_elem		*addlist(t_elem *, char *);
t_label		*addlabel(t_label *, char *, int);
int		check_multiple_comment(char *);
void		epure_str(char **);
char		*my_copy(char *, int);
void		check_comment_line(char **, int);
void		check_syntax(char *, int, int);
int		check_name(char *, int);
int		check_comment(char *);
int		multiple_label(t_label *);
int		my_label_copy(char *, t_label **, int);
int		check_label_char(char);
int		valid_label(char *);
int		check_files_extension(char **);
int		check_file_syntax(char **);
int		interpret_first_word(t_parse *);
int		check_instruction(t_parse *);
int		check_label(t_parse *);
int		write_invert(int, int);
int		count_apo(char *);
int		check_len(char *, int, char *);
char		*get_name_comment(char **, char *);
int		error_message(char *, char *, t_header *, char **);
int		check_instruction_arg_validity(t_parse *);
int		check_args_type(int, int, t_type);
int		interpret_args(char **, char *, int, int *);
t_type		init_reg(t_type);
t_type		init_dir(t_type);
t_type		init_ind(t_type);

#endif /* ASM_H_ */
