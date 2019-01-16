/*
** basic.h for  in /home/sahel/bin/lib
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Feb 17 08:26:47 2017 Sahel
** Last update Tue Mar 14 20:24:21 2017 Sahel
*/

#ifndef BASIC_H_
# define BASIC_H_

char	*strdup_(char *);
char	*strdupn_(char *, int);
char	*strndup_(char *, int);
char	*strcat_(char *, char *);
char	*strcpy_(char *, char *);
char	*strncat_(char *, char *, int);
char	*strstr_(char *, char *);
int	strcmp_(char *, char *);
int	strncmp_(char *, char *, int);
int	strlen_(char *);
int	tablen_(char **);
int	power_(int, int);
int	sqrt_(int);
int	getnbr_(char *);
int	match(char *, char *);
int	is_prime(int);
void	putnbr_(int);
void	putchar_(char);
void	putstr_(char *, int);
void	puttab_(char **, int);
void	free_(char *);

#endif /* !BASIC_H_ */
