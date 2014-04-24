#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

#define HEIGHT 768
#define WIDTH 1024

int angle1 = 45;
int angle2 = -20;
int longueur = 50;

void	*dayn()
{
  int	status;
  int	day;

  day = 255;
  status = 1;
  while (1)
    {
      if (status == 1 && day <= 5)
	status = 0;
      else if (status == 0 && day >= 255)
	status = 1;
      if (status == 1)
	day--;
      else if (status == 0)
	day++;
      Dessiner(day);
      usleep(100000);
    }
}

int main(int argc, char *argv[])
{
  SDL_Event event;
  int	continuef;
  pthread_t thread;

  SDL_Init(SDL_INIT_VIDEO);
  atexit(SDL_Quit);
  continuef = 1;
  SDL_WM_SetCaption("Lem-In - Visu", NULL);
  SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL);

  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  gluOrtho2D(0, WIDTH, 0, HEIGHT);
  SDL_EnableKeyRepeat(10,10);
  Dessiner(255);
  pthread_create(&thread, NULL, dayn, NULL);
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

SDL_Surface * flipSurface(SDL_Surface * surface)
{
  int current_line,pitch;
  SDL_Surface * fliped_surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
						      surface->w,surface->h,
						      surface->format->BitsPerPixel,
						      surface->format->Rmask,
						      surface->format->Gmask,
						      surface->format->Bmask,
						      surface->format->Amask);
  SDL_LockSurface(surface);
  SDL_LockSurface(fliped_surface);
  pitch = surface->pitch;
  for (current_line = 0; current_line < surface->h; current_line ++)
    {
      memcpy(&((unsigned char* )fliped_surface->pixels)[current_line*pitch],
	     &((unsigned char* )surface->pixels)[(surface->h - 1  -
						  current_line)*pitch],
	     pitch);
    }
  SDL_UnlockSurface(fliped_surface);
  SDL_UnlockSurface(surface);
  return fliped_surface;
}

GLuint loadTexture(const char	*filename, int useMipMap)
{
  GLuint glID;
  SDL_Surface * picture_surface = NULL;
  SDL_Surface *gl_surface = NULL;
  SDL_Surface * gl_fliped_surface = NULL;
  Uint32 rmask, gmask, bmask, amask;
  SDL_Surface * flipSurface(SDL_Surface * surface);

  picture_surface = IMG_Load(filename);
  if (picture_surface == NULL)
    return 0;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  rmask = 0xff000000;
  gmask = 0x00ff0000;
  bmask = 0x0000ff00;
  amask = 0x000000ff;
#else
  rmask = 0x000000ff;
  gmask = 0x0000ff00;
  bmask = 0x00ff0000;
  amask = 0xff000000;
#endif
  SDL_PixelFormat format = *(picture_surface->format);
  format.BitsPerPixel = 32;
  format.BytesPerPixel = 4;
  format.Rmask = rmask;
  format.Gmask = gmask;
  format.Bmask = bmask;
  format.Amask = amask;
  gl_surface = SDL_ConvertSurface(picture_surface,&format,SDL_SWSURFACE);
  gl_fliped_surface = flipSurface(gl_surface);
  glGenTextures(1, &glID);
  glBindTexture(GL_TEXTURE_2D, glID);
  if (useMipMap)
    {
      gluBuild2DMipmaps(GL_TEXTURE_2D, 4, gl_fliped_surface->w,
			gl_fliped_surface->h, GL_RGBA,GL_UNSIGNED_BYTE,
			gl_fliped_surface->pixels);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,
		      GL_LINEAR_MIPMAP_LINEAR);
    }
  else
    {
      glTexImage2D(GL_TEXTURE_2D, 0, 4, gl_fliped_surface->w,
		   gl_fliped_surface->h, 0, GL_RGBA,GL_UNSIGNED_BYTE,
		   gl_fliped_surface->pixels);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    }
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  SDL_FreeSurface(gl_fliped_surface);
  SDL_FreeSurface(gl_surface);
  SDL_FreeSurface(picture_surface);
  return glID;
}

void	draw_grass(double largeur, double hauteur, int day)
{
  GLuint texture;

  printf("Dessin avec day = %d\n", day);
  texture = loadTexture("grass.png", 0);
  glTranslated(0, HEIGHT - hauteur, 0);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture);
  glBegin(GL_QUADS);
  glTexCoord2d(1, 0);
  glColor3ub(day, day, day);
  glVertex2d(0, -hauteur);
  glTexCoord2d(1, 1);
  glColor3ub(0, 0, 200);
  glVertex2d(0, hauteur);
  glTexCoord2d(0, 1);
  glColor3ub(0, 0, 200);
  glVertex2d(largeur, hauteur);
  glTexCoord2d(0, 0);
  glColor3ub(day, day, day);
  glVertex2d(largeur, -hauteur);
  glEnd();
}

void Dessiner(int day)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  draw_bg(1024, 600);
  draw_grass(1024, 100, day);
  glFlush();
  SDL_GL_SwapBuffers();
}
