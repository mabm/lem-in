/*
** main.c for main in /home/merran_g/work/c_elem/lem-in/lem_in/core
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr 22 13:59:42 2014 Geoffrey Merran
** Last update Fri May  2 18:37:29 2014 Geoffrey Merran
*/

#include "main.h"

void	lem_in()
{
  t_map	*map;

  map = parse_lemin();
  aff_map(map);
  find_short_way(map);
}

int	main(int ac, char **av)
{
  (void) av;
  if (ac == 1)
    lem_in();
  else
    printf(VM_USAGE);
  return (EXIT_SUCCESS);
}
