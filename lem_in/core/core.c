/*
** core.c for  in /home/nicolas/Workspace/lem_in/lem_in/core
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sun Apr 27 13:00:58 2014 Nicolas Ades
** Last update Sun Apr 27 16:47:03 2014 Jeremy Mediavilla
*/

#include "lem_in.h"
#include "main.h"

void		find_short_way(t_map *map)
{
  t_room	*tmp;

  printf("\nshort way\n");
  tmp = map->start;
  tmp->val = 0;
  while (tmp->access->name != NULL)
    {
      printf("%s\n", tmp->access->name);
      tmp->access = tmp->access->next;
    }
}

void		launch_fct(t_map *map)
{
  
}
