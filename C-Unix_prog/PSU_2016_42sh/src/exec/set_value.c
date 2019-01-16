/*
** set_value.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Fri May 19 09:31:54 2017 Lucas Dumy
** Last update Fri May 19 09:33:10 2017 Lucas Dumy
*/

#include	"mysh.h"

void		set_value(int *value, int first_val, int sec_val)
{
  value[0] = first_val;
  value[1] = sec_val;
}
