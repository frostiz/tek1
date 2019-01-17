//
// 106bombyx.cpp for 106bombyx in /home/thibaut/Repository/106bombyx
// 
// Made by 
// Login   <thibaut.trouve@epitech.eu>
// 
// Started on  Thu Feb  9 20:33:58 2017 
// Last update Sun Feb 19 18:49:49 2017 
//

#include <iostream>
using namespace std;

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}

int	growth(int n, double k)
{
  int	i;
  double	xi;

  xi = (double)n;
  i = 0;
  while (i < 100)
    {
      if (xi > 0.0)
	{
	  printf("%d %.2f\n", i + 1, xi);
	}
      else
	{
	  printf("0.0\n");
	}
      xi = k * xi * (1000 - xi) / 1000;
      i++;
    }
}

double	get(int i0, int n, double k)
{
  int	i;
  double	xi;
  
  xi = (double)n;
  i = 0;
  while (i < i0)
    {
      xi = k * xi * (1000 - xi) / 1000;
      i++;
    }
  return (xi);
}

int	special_gen(int n, int i0, int i1)
{
  int	i;
  double	k;
  double	xi;
  int	a;

  xi = n;
  k = 1.0;
  while (k < 4.0)
    {
      a = 0;
      i = i0;
      while (a < i0)
	{
	  xi = k * xi * (1000 - xi) / 1000;
	  a++;
	}
      while (i <= i1)
	{
	  xi = k * xi * (1000 - xi) / 1000;
	  if (xi > 0.0)
	    {
	      printf("%.2f %.2f\n", k, xi);
	    }
	  else
	    {
	      printf("0.0\n");
	    }
	  i++;
	}
      k += 0.01;
    }
}

int	is_digit(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i++;
    }
  return (1);
}

int	is_double(char *str)
{
  int	i;
  int	p;

  i = 0;
  p = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '.')
	p++;
      if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
	return (0);
      i++;
    }
  if (p == 1)
    return (1);
  if (p == 0)
    {
      return (1);
    }
  return (0);
}

int	main(int argc, char **argv)
{
  int n;

  if (argc < 3)
    {
      printf("Not enough arguments");
      return (84);
    }
  if (argc > 4)
    {
      printf("Too much arguments");
      return (84);
    }
  if (is_digit(argv[1]) == 1)
    n = atoi(argv[1]);
  else
    {
      printf("n must be an integer !\n");
      return (84);
    }
  if (n < 0)
    return (84);
  if (argc == 3)
    {
      double k;

      if (is_double(argv[2]) == 1)
	k = atof(argv[2]);
      else
	{
	  printf("k must be a double !\n");
	  return (84);
	}
      if (k < 1.0 || k > 4.0)
	{
	  printf("k must vary from 1.0 to 4.0 !\n");
	  return (84);
	}
      growth(n, k);
    }
  else if (argc == 4)
    {
      int i0;
      int i1;
      if (is_digit(argv[2]) == 1)
	i0 = atoi(argv[2]);
      else
	{
	  printf("i0 must be an integer !\n");
	  return (84);
	}
      if (is_digit(argv[3]) == 1)
	i1 = atoi(argv[3]);
      else
	{
	  printf("i1 must be an integer !\n");
	  return (84);
	}
      if (i0 < 0 || i1 < i0)
	return (84);
      if (i1 < 0)
	return (0);
      special_gen(n, i0, i1);
    }
}
