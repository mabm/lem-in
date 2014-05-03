/*
** main.c for main in /home/merran_g/work/c_elem/lem-in/lem_in/core
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr 22 13:59:42 2014 Geoffrey Merran
** Last update Sat May  3 17:54:26 2014 Jeremy Mediavilla
*/

#include "main.h"

void		reinit_map_vals(t_map *map)
{
  t_room	*tmp;

  tmp = map->head;
  while (tmp != NULL)
    {
      tmp->val = 0;
      tmp = tmp->next;
    }
}

void		lem_in()
{
  t_map		*map;
  t_path	*path;

  map = parse_lemin();
  path = find_ways(map);
  reinit_map_vals(map);
  lem_in_take_a_selfie(path, map->nb_ants);
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
