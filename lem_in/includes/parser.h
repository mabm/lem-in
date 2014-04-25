/*
** parser.h for parser in /home/merran_g/work/c_elem/lem-in/lem_in/includes
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr 22 15:02:56 2014 Geoffrey Merran
** Last update Fri Apr 25 20:26:02 2014 Geoffrey Merran
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
int	get_line_type(char *buffer);

/*
** Fill map
*/

void	get_nb_ants(char **tab, int *step, t_map *map);
void	get_room(char **tab, int *step, t_map *map);

/*
** Operation in list 
*/

void   	add_room(char **tab, t_map *map);

/*
** Error
*/

void	my_error(char *error);

/*
** Parsing
*/

void	parse_command(char *buffer, int *step, t_map *map);
void	parse_data2(char *buffer, int *step, t_map *map);
void	parse_data(char *buffer, int *step, t_map *map);
void	parse_type(int type, char *buffer, int *step, t_map *map);
t_map	*parse_lemin();

#endif /* PARSER_ */
