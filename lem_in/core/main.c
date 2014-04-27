/*
** main.c for main in /home/merran_g/work/c_elem/lem-in/lem_in/core
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr 22 13:59:42 2014 Geoffrey Merran
** Last update Sun Apr 27 13:37:37 2014 Geoffrey Merran
*/

#include "main.h"

void		aff_access(t_access *access)
{
  t_access	*tmp;

  tmp = access;
  while (tmp != NULL)
    {
      printf("--> Access to %s\n", tmp->name);
      tmp = tmp->next;
    }
}

void		aff_map(t_map *map)
{
  t_room	*tmp;

  tmp = map->head;
  printf("\n== AFFICHAGE MAP (DEBUG) ==\n\n");
  while (tmp != NULL)
    {
      printf("-> Salle %s", tmp->name);
      if (map->start == tmp)
	printf(" -- ENTRANCE");
      if (map->end == tmp)
	printf(" -- OUTSIDE");
      printf("\n");
      aff_access(tmp->access);
      tmp = tmp->next;
    }
}

void	lem_in()
{
  t_map	*map;

  map = parse_lemin();
  aff_map(map);
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
