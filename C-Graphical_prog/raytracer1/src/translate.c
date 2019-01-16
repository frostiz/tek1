/*
** translate.c for raytracer in /home/thibaut/Repository/raytracer1
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Thu Feb 23 11:05:53 2017 
** Last update Sun Mar 19 18:29:14 2017 
*/

#include "my.h"

static void		modify_translate_matrix
(float translate_matrix[4][4], float coord_matrix[4][1],
 sfVector3f translations, sfVector3f to_translate)
{
  translate_matrix[0][0] = 1;
  translate_matrix[0][1] = 0;
  translate_matrix[0][2] = 0;
  translate_matrix[0][3] = translations.x;
  translate_matrix[1][0] = 0;
  translate_matrix[1][1] = 1;
  translate_matrix[1][2] = 0;
  translate_matrix[1][3] = translations.y;
  translate_matrix[2][0] = 0;
  translate_matrix[2][1] = 0;
  translate_matrix[2][2] = 1;
  translate_matrix[2][3] = translations.z;
  translate_matrix[3][0] = 0;
  translate_matrix[3][1] = 0;
  translate_matrix[3][2] = 0;
  translate_matrix[3][3] = 1;
  coord_matrix[0][0] = to_translate.x;
  coord_matrix[1][0] = to_translate.y;
  coord_matrix[2][0] = to_translate.z;
  coord_matrix[3][0] = 1;
}

static void	prod_next_line(t_prod_matrix *count,
			       float **matrix_result, float *result)
{
  count->col++;
  matrix_result[count->stock_y][count->stock_x] = *result;
  count->stock_x++;
  *result = 0;
  count->linecol = 0;
  if (count->col == 1)
    {
      count->stock_y++;
      count->col = 0;
      count->stock_x = 0;
      count->line++;
    }
}

float	**product_m(float translate_matrix[4][4],
		    float coord_matrix[4][1], t_prod_matrix count)
{
  float	result;
  float	**matrix_result;

  if ((matrix_result = malloc(sizeof(float *) * 4)) == NULL ||
      (matrix_result[0] = malloc(sizeof(float) * 4)) == NULL ||
      (matrix_result[1] = malloc(sizeof(float) * 4)) == NULL ||
      (matrix_result[2] = malloc(sizeof(float) * 4)) == NULL ||
      (matrix_result[3] = malloc(sizeof(float) * 4)) == NULL)
    return (NULL);
  result = 0;
  while (count.line != 4)
    {
      result += translate_matrix[count.line][count.linecol] *
	coord_matrix[count.linecol][count.col];
      count.linecol++;
      if (count.linecol == 4)
	{
	  prod_next_line(&count, matrix_result, &result);
	}
    }
  return (matrix_result);
}

sfVector3f	translate(sfVector3f to_translate,
			  sfVector3f translations)
{
  sfVector3f	resultc;
  t_prod_matrix	count;
  float		translate_matrix[4][4];
  float		coord_matrix[4][1];
  float		**matrix_result;

  modify_translate_matrix
    (translate_matrix, coord_matrix, translations, to_translate);
  count.line = 0;
  count.col = 0;
  count.linecol = 0;
  count.stock_y = 0;
  count.stock_x = 0;
  matrix_result = product_m(translate_matrix, coord_matrix, count);
  resultc.x = matrix_result[0][0];
  resultc.y = matrix_result[1][0];
  resultc.z = matrix_result[2][0];
  return (resultc);
}
