/*
** init_types.c for corewar in /home/thibaut/Repository/CPE_2016_corewar
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Apr  2 19:21:50 2017 Thibaut Trouvé
** Last update Sun Apr  2 19:31:51 2017 Thibaut Trouvé
*/

#include "asm.h"
#include "op.h"

t_type	init_reg(t_type type)
{
  type.a = T_REG;
  type.b = T_DIR;
  type.c = T_IND;
  return (type);
}

t_type	init_dir(t_type type)
{
  type.a = T_DIR;
  type.b = T_REG;
  type.c = T_IND;
  return (type);
}

t_type	init_ind(t_type type)
{
  type.a = T_IND;
  type.b = T_REG;
  type.c = T_DIR;
  return (type);
}
