#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

int main(int argc, char *argv[])
{
  int		flag;
  SDL_Surface	*ecran;
  SDL_Event	event;

  flag = 1;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Visu - Lem-In", NULL);
  ecran = SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);
  SDL_Flip(ecran);
  while (flag)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	flag = 0;
      glClear(GL_COLOR_BUFFER_BIT);
      glBegin(GL_TRIANGLES);
      glColor3ub(255,0,0);    glVertex2d(-0.75,-0.75);
      glColor3ub(0,255,0);    glVertex2d(0,0.75);
      glColor3ub(0,0,255);    glVertex2d(0.75,-0.75);
      glEnd();
      glFlush();
      SDL_GL_SwapBuffers();
    }
  SDL_Quit();
  return 0;
}
