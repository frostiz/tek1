/*
** get_next_line.h for  in /home/sahel/bin/gnl
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Feb 25 17:22:10 2017 Sahel
** Last update Sun Mar 19 20:49:44 2017 
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# define READSIZE 1

typedef struct	buffer
{
  struct buffer	*next;
  struct buffer *previous;
  int		fd;
  char		*buffer;
}		t_buffer;

char	*getnextline_(int);

#endif /* !GET_NEXT_LINE_H_ */
