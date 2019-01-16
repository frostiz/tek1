/*
** prompt.c for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
** 
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
** 
** Started on  Sun May 21 21:31:16 2017 dubret_v
** Last update Sun May 21 21:34:06 2017 dubret_v
*/

#include	<unistd.h>

void		my_prompt(int i)
{
  (void)i;
  write(1, "\n$> ", 4);
}

