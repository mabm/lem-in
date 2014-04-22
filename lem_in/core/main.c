/*
** main.c for main in /home/merran_g/work/c_elem/lem-in/lem_in/core
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr 22 13:59:42 2014 Geoffrey Merran
** Last update Tue Apr 22 15:08:47 2014 Geoffrey Merran
*/

#include "main.h"

void	lem_in(char **av)
{
  t_map	*map;

  map = parse_lemin(av);
}

int	main(int ac, char **av)
{
  if (ac > 1)
    lem_in(av);
  else
    printf(VM_USAGE);
  return (EXIT_SUCCESS);
}
