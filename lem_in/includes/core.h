/*
** core.h for core in /home/merran_g/work/c_elem/lem-in/lem_in
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Apr 30 08:10:21 2014 Geoffrey Merran
** Last update Fri May  2 18:40:57 2014 Geoffrey Merran
*/

#ifndef CORE_
# define CORE_
# include "lem_in.h"
# include "parser.h"
# include "debug.h"

void		find_short_way(t_map *);
void		aff_access(t_access *);
void		remove_last_access(t_access **);
void		get_path(t_path *path, int size_path);

#endif /* CORE_ */
