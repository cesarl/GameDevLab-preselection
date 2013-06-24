#pragma once

#include		"stdafx.h"
#include		<Windows.h>
#include		<SDL.h>
#include		<gl/GL.h>
#include		<gl/GLU.h>
#include		"Singleton.hpp"

class			Context : public Singleton<Context>
{
public:
  bool			init()
  {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) == -1)
      return false;
    this->display_ = SDL_SetVideoMode(1000, 1000, 32, SDL_SWSURFACE | SDL_OPENGL);
    if (!this->display_)
      return false;

    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0f);
    glViewport(0, 0, 1000, 1000);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)(1000 / 1000), 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_TEXTURE_2D);
    glLoadIdentity();
    glClearColor((128.0f / 255.0f), 1.0f, 1.0f, 1.0f);
	this->run_ = true;
	return true;
  }

  bool			run(SDL_Event &ev)
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	

	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -2.0f, 0.0f);

    return this->run_;
  }

  void			endOfLoop()
  {
    SDL_GL_SwapBuffers();
    SDL_Delay(30);
  }

  void			uninit()
  {
    SDL_FreeSurface(this->display_);
    SDL_Quit();
  }

  void			stop()
	{
		this->run_ = false;
	}
private:
  SDL_Surface		*display_;
  bool				run_;
private:
  Context() :
    display_(NULL),
	run_(false)
  {}

  ~Context()
  {}
  friend class Singleton<Context>;
};

