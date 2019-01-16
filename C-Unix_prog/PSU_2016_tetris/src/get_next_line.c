/*
** get_next_line.c for  in /home/sahel/rendu
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Feb 24 18:59:18 2017 Sahel
** Last update Sat Mar 18 17:29:25 2017 Sahel
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "basic.h"
#include "get_next_line.h"
#include "main.h"

char	*concat_free(char *str1, char *str2);

static void	set_buffer(t_buffer *new, t_buffer *actual, int need_free)
{
  new->fd = actual->fd;
  new->buffer = strdup_(actual->buffer);
  new->next = actual->next;
  new->previous = actual->previous;
  if (need_free)
    {
      free(actual->buffer);
      free(actual);
    }
}

static t_buffer	*init_(int fd, t_buffer *previous)
{
  t_buffer	*buffer;

  if (!(buffer = malloc(sizeof(t_buffer))))
    return (NULL);
  buffer->fd = fd;
  buffer->buffer = NULL;
  buffer->next = NULL;
  if (previous)
    {
      buffer->previous = previous;
      previous->next = buffer;
    }
  else
    buffer->previous = NULL;
  return (buffer);
}

static t_buffer	*take_buffer(int fd, t_buffer *actual)
{
  t_buffer	*new;

  if (fd == actual->fd)
    return (actual);
  if (!(new = malloc(sizeof(t_buffer))))
    return (NULL);
  set_buffer(new, actual, 0);
  while (fd != new->fd && new->previous)
    new = new->previous;
  if (fd != new->fd)
    set_buffer(new, actual, 1);
  while (new->fd != fd && new->next)
    new = new->next;
  if (fd != new->fd)
    new = init_(fd, new);
  return (new);
}

static int		update_actual(t_buffer *actual)
{
  char			*buffer;
  int			size;

  if ((actual->buffer && sp_len_(actual->buffer, '\n') !=
       strlen_(actual->buffer)) ||
      !(buffer = malloc(sizeof(char) * (READSIZE + 1))))
    return (0);
  while ((size = read(actual->fd, buffer, READSIZE)) > 0)
    {
      buffer[size] = '\0';
      actual->buffer = concat_free(actual->buffer, buffer);
      if (sp_len_(actual->buffer, '\n') != strlen_(actual->buffer))
	return (0);
    }
  if (size <= 0 && (!actual->buffer || size == -1 || !*actual->buffer))
    return (1);
  return (0);
}

char			*getnextline_(int fd)
{
  static t_buffer	*fd_;
  char			*line;

  if (fd < 0)
    return (NULL);
  if (!fd_)
    fd_ = init_(fd, NULL);
  fd_ = take_buffer(fd, fd_);
  if (update_actual(fd_) == 1)
    return (NULL);
  line = strndup_(fd_->buffer, sp_len_(fd_->buffer, '\n'));
  fd_->buffer = strdupn_(fd_->buffer, sp_len_(fd_->buffer, '\n') + 1);
  return (line);
}
