/*
** main.c for Visu in /home/jobertomeu/Work/lemin/visu
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Apr 30 15:33:38 2014 Joris Bertomeu
** Last update Fri May  2 09:19:03 2014 Joris Bertomeu
*/

#include "visu.h"

void	write_info(char *name_box, int x, int y, t_system *sys)
{
  TTF_Font	*font;
  SDL_Rect	pos;
  SDL_Surface	*txt;

  TTF_Init();
  font = TTF_OpenFont("font.ttf", 15);
  txt = TTF_RenderText_Blended(font, "[BoxX] 0 fourmis",
				 (SDL_Color) {255, 255, 255});
  pos.x = x;
  pos.y = y - 30;
  SDL_BlitSurface(txt, NULL, sys->screen, &pos);
  SDL_Flip(sys->screen);
}

void	place_box(char *name_box, int x, int y, t_system *sys)
{
  SDL_Rect	pos;
  SDL_Surface	*box;

  pos.x = x;
  pos.y = y;
  write_info(name_box, x, y, sys);
  printf("Placement de la box %s à x = %d et y = %d\n", name_box, x, y);
  box = SDL_LoadBMP("box.bmp");
  SDL_BlitSurface(box, NULL, sys->screen, &pos);

  SDL_Flip(sys->screen);
}

void	tread_line(char *str, int x, int y, t_system *sys)
{
  int	i;
  int	j;
  char	name[4096];
  int	cmptr;

  j = 0;
  i = 0;
  cmptr = 0;
  while (str[i])
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
	name[j++] = str[i];
      else if (str[i] == ' ')
	cmptr++;
      else if (str[i] >= '0' && str[i] <= '9')
	if (cmptr == 1)
	  x = x * 10 + (str[i] - '0');
	else if (cmptr == 2)
	  y = y * 10 + (str[i] - '0');
	else if (((str[i - 1] >= 'a' && str[i - 1] <= 'z')
		  || (str[i - 1] >= 'A' && str[i - 1] <= 'Z')))
	  name[j++] = str[i];
      i++;
    }
  place_box(name, x, y, sys);
}

void	parse(t_system *sys)
{
  int	fd;
  char	*tmp;

  sys->current = 0;
  tmp = malloc(4096 * sizeof(*tmp));
  fd = open("out", O_RDONLY);
  while ((tmp = get_next_line(fd)) != NULL)
    {
      tread_line(tmp, 0, 0, sys);
      sys->current++;
    }
}

int main(int argc, char *argv[])
{
  SDL_Event	event;
  int		continuef;
  pthread_t	thread;
  t_system	*sys;

  sys = malloc(sizeof(*sys));
  SDL_Init(SDL_INIT_VIDEO);
  atexit(SDL_Quit);
  continuef = 1;
  SDL_WM_SetCaption("Lem-In - Visu", NULL);
  sys->screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE);

  /* glMatrixMode( GL_PROJECTION ); */
  /* glLoadIdentity( ); */
  /* gluOrtho2D(0, WIDTH, 0, HEIGHT); */
  SDL_EnableKeyRepeat(10,10);
  /* Dessiner(255); */
  parse(sys);
  while (continuef)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	continuef = 0;
    }
  SDL_Quit();
  return 0;
}

void draw_bg(double largeur, double hauteur)
{
  glTranslated(0, 0, 0);
  glBegin(GL_QUADS);
  glColor3ub(157, 18, 8);
  glVertex2d(0, -hauteur);
  glColor3ub(0, 34, 4);
  glVertex2d(0, hauteur);
  glColor3ub(88, 38, 0);
  glVertex2d(largeur, hauteur);
  glColor3ub(57, 66, 29);
  glVertex2d(largeur, -hauteur);
  glEnd();
}

void Dessiner(int day)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  draw_bg(1024, 768);
  /* draw_grass(1024, 100, day); */
  glFlush();
  SDL_GL_SwapBuffers();
}
