/*
** core.h for core in /home/merran_g/work/c_elem/lem-in
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun May  4 15:13:55 2014 Geoffrey Merran
** Last update Sun May  4 15:13:56 2014 Geoffrey Merran
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
void		put_in_path(t_way **ways, t_way *new);
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
