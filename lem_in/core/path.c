/*
** path.c for  in /home/mediav_j/mabm/lem-in/lem_in
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Fri May  2 16:06:34 2014 Jeremy Mediavilla
** Last update Fri May  2 19:05:52 2014 Geoffrey Merran
*/

#define _BSD_SOURCE
#include "core.h"

void		remove_last_access(t_access **access)
{
  t_access	*tmp;

  if (access != NULL)
    {
      tmp = (*access)->next;
      free((*access)->name);
      free(*access);
      *access = tmp;
    }
}

void		fill_path(char ***path, t_access *access)
{
  t_access	*tmp;
  int		i;

  i = 0;
  tmp = access;
  while (tmp != NULL)
    {
      (*path)[i] = strdup(tmp->name);
      i++;
      tmp = tmp->next;
    }
  (*path)[i] = NULL;
}

void		get_path(t_path *path, int size_path)
{
  t_way		*new;

  new = my_xmalloc(sizeof(*new));
  new->path = my_xmalloc((size_path + 1) * sizeof(char *));
  new->size = size_path;
  fill_path(&new->path, path->access);
  new->next = path->way;
  new->prev = NULL;
  if (path->way != NULL)
    path->way->prev = new;
  path->way = new;
}
