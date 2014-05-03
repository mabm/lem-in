/*
** core.h for core in /home/merran_g/work/c_elem/lem-in/lem_in
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Wed Apr 30 08:10:21 2014 Geoffrey Merran
** Last update Sat May  3 17:09:34 2014 Jeremy Mediavilla
*/

#ifndef CORE_
# define CORE_
# include "lem_in.h"
# include "parser.h"
# include "debug.h"

/*
** Finds ways to end
*/

t_path		*find_ways(t_map *map);
void		travel_rooms(t_map *map, t_room *current, int value, t_path *path);
t_room		*find_room(t_map *map, char *room_name);
void		init_path(t_path **path);
void		get_path(t_path *path, int size_path);
void		fill_path(char ***path, t_access *access);
void		remove_last_access(t_access **access);
void		lem_in_take_a_selfie(t_path *, int);

/*
** Push ants to the end
*/

/*
** Lem_in
*/

void	lem_in();

#endif /* CORE_ */
