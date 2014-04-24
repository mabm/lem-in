/*
** main.c for Visu in /home/jobertomeu/Work/lemin/visu
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Mon Apr 21 18:58:35 2014 Joris Bertomeu
** Last update Mon Apr 21 19:27:59 2014 Joris Bertomeu
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	printe(char *msg)
{
  printf("%s", msg);
  exit (0);
}

void	tread_line(char *line, int start, int end, int flag)
{
  int	i;
  char	str[1][16];
  int	j;

  j = 0;
  i = 0;
  memset(str[0], 0, 16);
  memset(str[1], 0, 16);
  while (line[i])
    {
      if (line[i] >= '0' && line[i] <= '9' && flag == 0)
	str[0][j++] = line[i];
      else if (line[i] >= '0' && line[i] <= '9' && flag == 1)
	str[1][j++] = line[i];
      else if (line[i] == '-')
	{
	  j = 0;
	  flag = 1;
	}
      else
	printe("Syntax Error\n");
      i++;
    }
  printf("Entree : %s - Sortie : %s\n", str[0], str[1]);
}

void	read_map(int ac, char **argv)
{
  int	fd;
  char	*tmp;

  tmp = malloc(4096 * sizeof(*tmp));
  if (ac <= 1)
    printe("Usage : ./visu <Input_file>\n");
  fd = open(argv[1], O_RDONLY);
  while ((tmp = get_next_line(fd)) != NULL)
    tread_line(tmp, 0, 0, 0);
}

int	main(int ac, char *argv[])
{
  read_map(ac, argv);
  return (0);
}
