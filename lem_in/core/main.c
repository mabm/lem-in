/*
** main.c for main in /home/merran_g/work/c_elem/lem-in/lem_in/core
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr 22 13:59:42 2014 Geoffrey Merran
** Last update Thu Apr 24 10:55:10 2014 Geoffrey Merran
*/

#include "main.h"

void	lem_in()
{
  t_map	*map;

  map = parse_lemin();
}

int	main(int ac, char **av)
{
  if (ac == 1)
    lem_in();
  else
    printf(VM_USAGE);
  return (EXIT_SUCCESS);
}
