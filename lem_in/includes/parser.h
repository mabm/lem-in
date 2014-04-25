/*
** parser.h for parser in /home/merran_g/work/c_elem/lem-in/lem_in/includes
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr 22 15:02:56 2014 Geoffrey Merran
** Last update Fri Apr 25 21:24:58 2014 Geoffrey Merran
*/

#ifndef PARSER_
# define PARSER_
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "lem_in.h"
# include "my.h"
# include "gnl.h"

/*
** Initialisation
*/

void	init_map(t_map **map);

/*
** Check type
*/

typedef enum	e_type
  {
    COMMAND_TYPE,
    COMMENTARY_TYPE,
    OTHER_TYPE
  }		t_type;

int	is_command(char *buffer);
int	is_commentary(char *buffer);
int	is_valid_room_name(char *str);
int    	is_existing_room(char *new, t_room *list);
int	get_line_type(char *buffer);

/*
** Fill map
*/

void	get_nb_ants(char **tab, int *step, t_map *map);
void	get_room(char **tab, int *step, t_map *map);
void	get_access(char **tab, int *step, t_map *map);


/*
** Operation in list 
*/

void   	add_room(char **tab, t_map *map);
void   	add_access(char *name, t_access **access);
int    	give_access(char *room, char *access, t_map *map);

/*
** Error
*/

void	my_error(char *error);

/*
** Free
*/

void	free_tab(char **tab);

/*
** Parsing
*/

int	parse_command(char *buffer, int *step, t_map *map);
void	parse_data2(char *buffer, int *step, t_map *map);
void	parse_data(char *buffer, int *step, t_map *map);
int	parse_type(int type, char *buffer, int *step, t_map *map);
t_map	*parse_lemin();

#endif /* PARSER_ */
