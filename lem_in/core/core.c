/*
** core.c for  in /home/nicolas/Workspace/lem_in/lem_in/core
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sun Apr 27 13:00:58 2014 Nicolas Ades
** Last update Fri May  2 14:03:27 2014 Jeremy Mediavilla
*/

#include "core.h"

t_room		*find_room(t_map *map, char *room_name)
{
  t_room	*tmp;

  tmp = map->head;
  while (tmp != NULL)
    {
      if (strcmp(room_name, tmp->name) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

int		get_room_value(t_map *map, char *room_name)
{
  t_room	*tmp;

  tmp = find_room(map, room_name);
  return (tmp->val);
}

void		aff_path(t_access *path)
{
  printf("\nPath :\n");
  while (path != NULL)
    {
      printf("%s\n", path->name);
      path = path->next;
    }
  my_putchar('\n');
}

int		nbr_of_access(t_map *map, t_room *room)
{
  int		i;

  (void)map;
  i = 0;
  while (room->access != NULL)
    {
      room->access = room->access->next;
      i++;
    }
  return (i);
}

void		aff_tiret(int val)
{
  int		i;

  i = -1;
  while (++i < val)
    {
      my_putchar('|');
      if ((i + 1) != val)
	my_putchar(' ');
    }
  my_putstr("__");
}

void		travel_rooms(t_map *map, t_room *current, int value)
{
  t_room	*access;
  t_access	*tmp;

  tmp = current->access;
  if (current == map->end)
    printf(" (END)");
  printf("\n");
  while (tmp != NULL && current != map->end)
    {
      access = find_room(map, tmp->name);
      if (access->val == -1 || access->val > value)
	{
	  access->val = value;
	  aff_tiret(value);
	  printf("%s [%i]", tmp->name, access->val);
	  travel_rooms(map, access, (value + 1));
	}
      tmp = tmp->next;
    }
}

void		room_backtracking(t_map *map, t_access **shortway)
{
  t_room	*current;

  if (map->end->val == -1)
    my_error(" ~ Error : No solution has been found to go outside ~\n");
  current = map->end;
  while (current != map->start)
    {
      while (get_room_value(map, current->access->name) != (current->val - 1))
	current->access = current->access->next;
      add_access(current->name, shortway);
      current = find_room(map, current->access->name);
    }
  add_access(map->start->name, shortway);
}

/* t_access	*room_backtracking2(t_map *map) */
/* { */
/*   t_room	*current; */
/*   t_access	*way; */
/*   int		val; */
/*   int		tmp_val; */
/*   t_access	*tmp; */
/*   t_access	*tmp2; */

/*   way = NULL; */
/*   if (map->end->val == -1) */
/*     my_error(" ~ Error : No solution has been found to go outside ~\n"); */
/*   current = map->end; */
/*   aff_access(current->access); */
/*   printf("DEBUG\n"); */
/*   tmp = current->access; */
/*   tmp2 = current->access; */
/*   val = current->val; */
/*   while (tmp2 != NULL) */
/*     { */
/*       if ((tmp_val = get_room_value(map, tmp2->name)) < val && tmp_val != -1) */
/*       	{ */
/*       	  val = tmp_val; */
/*       	  tmp = tmp2; */
/*       	} */
/*       tmp2 = tmp2->next; */
/*     } */
/*   if (tmp != NULL) */
/*     printf("[%s : %i]\n", tmp->name, val); */
/*   current = find_room(map, tmp->name); */
/*   while (current != map->start) */
/*     { */
/*       while (get_room_value(map, current->access->name) != (current->val - 1)) */
/* 	current->access = current->access->next; */
/*       /\* current->val = -1; *\/ */
/*       add_access(current->name,&way); */
/*       current = find_room(map, current->access->name); */
/*     } */
/*   add_access(map->start->name, &way); */
/*   return (way); */
/* } */

void		find_short_way(t_map *map)
{
  t_access	*shortway;
  int		nbr_ways;
  t_access	**ways;
  int		i;

  i = 0;
  shortway = NULL;
  printf("\n%s (start)", map->start->name);
  map->start->val = 0;
  travel_rooms(map, map->start, 1);
  room_backtracking(map, &shortway);
  /* nbr_ways = nbr_of_access(map, map->end); */
  nbr_ways = 3;
  aff_path(shortway);
  (void)ways;
  (void)i;
  (void)nbr_ways;
  /* ways = malloc(nbr_ways * sizeof(t_access *)); */
  /* ways[i] = room_backtracking2(map); */
  /* i++; */
  /* while (i < nbr_ways) */
  /*   { */
  /*     ways[i] = room_backtracking2(map); */
  /*     if (ways[i] != NULL) */
  /* 	aff_path(ways[i]); */
  /*     i++; */
  /*   } */
}
