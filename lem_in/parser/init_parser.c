/*
** init_parser.c for init_parser in /home/merran_g/work/c_elem/lem-in/lem_in
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu Apr 24 10:48:21 2014 Geoffrey Merran
** Last update Fri Apr 25 20:18:14 2014 Geoffrey Merran
*/

#include "parser.h"

void	init_map(t_map **map)
{
  (*map) = my_xmalloc(sizeof(**map));
  (*map)->nb_ants = 0;
  (*map)->nb_room = 0;
  (*map)->start = NULL;
  (*map)->end = NULL;
  (*map)->head = NULL;
  (*map)->tail = NULL;
}
