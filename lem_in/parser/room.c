/*
** room.c for room in /home/merran_g/work/c_elem/lem-in/lem_in/parser
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Fri Apr 25 20:09:30 2014 Geoffrey Merran
** Last update Fri Apr 25 20:27:03 2014 Geoffrey Merran
*/

#define _BSD_SOURCE
#include "parser.h"

void		add_room(char **tab, t_map *map)
{
  t_room	*new;

  new = my_xmalloc(sizeof(*new));
  new->val = 0;
  new->name = strdup(tab[0]);
  new->access = NULL;
  new->next = NULL;
  if (map->tail == NULL)
    {
      new->prev = NULL;
      map->head = new;
      map->tail = new;
    }
  else
    {
      map->tail->next = new;
      new->prev = map->tail;
      map->tail = new;
    }
  map->nb_room++;
}
