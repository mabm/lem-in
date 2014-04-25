/*
** parser.h for parser in /home/merran_g/work/c_elem/lem-in/lem_in/includes
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Tue Apr 22 15:02:56 2014 Geoffrey Merran
** Last update Thu Apr 24 17:32:51 2014 Geoffrey Merran
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
** Parsing
*/

t_map	*parse_lemin();

#endif /* PARSER_ */
