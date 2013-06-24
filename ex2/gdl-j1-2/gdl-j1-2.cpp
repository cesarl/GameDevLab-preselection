// gdl-j1-2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <Windows.h>
#include <SDL.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include  <iostream>
#include "Context.hpp"
#include "Cube.hpp"
#include "Grid.h"


Cube finger1(Vector3d(0.5f, 0.2f, 0.2f),
			Vector3d(2.0f, 0.0f, -5.0f),
			Vector3d(0.0f, 0.0f, 0.0f));

Cube finger2(Vector3d(0.5f, 0.2f, 0.2f),
			Vector3d(2.0f, 0.0f, -4.8f),
			Vector3d(0.0f, 0.0f, 0.0f));

Cube finger3(Vector3d(0.5f, 0.2f, 0.2f),
			Vector3d(2.0f, 0.0f, -4.6f),
			Vector3d(0.0f, 0.0f, 0.0f));

Cube poignet(Vector3d(0.6f, 0.2f, 0.4f),
			Vector3d(1.5f, 0.0f, -4.9f),
			Vector3d(0.0f, 0.0f, 0.0f));

Cube avantPoignet(Vector3d(0.8f, 0.3f, 0.3f),
			Vector3d(0.85f, -0.05f, -4.9f),
			Vector3d(0.0f, 0.0f, 0.0f));

Cube bras(Vector3d(1.2f, 0.5f, 0.5f),
			Vector3d(-0.3f, -0.4f, -5.6f),
			Vector3d(0.0f, 0.0f, 0.0f));

void myFinger(SDL_Event &ev)
{
	//finger1.draw();
	//finger2.draw();
	//finger3.draw();
	//poignet.draw();
	//avantPoignet.draw();
	bras.draw(true);

	if (ev.type == SDL_KEYDOWN)
		{
			switch(ev.key.keysym.sym)
			{
			case SDLK_KP7:
				bras.rotate(Vector3d(0.0f, 0.0f, 1.0f));
				break;
			case SDLK_KP4:
				bras.rotate(Vector3d(0.0f, 0.0f, -1.0f));
				break;
			case SDLK_KP8:
				if (!avantPoignet.rotate(Vector3d(0.0f, 0.0f, 1.0f)))
					bras.rotate(Vector3d(0.0f, 0.0f, 1.0f));
				break;
			case SDLK_KP5:
				if (!avantPoignet.rotate(Vector3d(0.0f, 0.0f, -1.0f)))
					bras.rotate(Vector3d(0.0f, 0.0f, -1.0f));
				break;
			case SDLK_KP9:
				if(!poignet.rotate(Vector3d(0.0f, 0.0f, 1.0f)))
					if (!avantPoignet.rotate(Vector3d(0.0f, 0.0f, 1.0f)))
						bras.rotate(Vector3d(0.0f, 0.0f, 1.0f));
				break;
			case SDLK_KP6:
				if(!poignet.rotate(Vector3d(0.0f, 0.0f, -1.0f)))
					if (!avantPoignet.rotate(Vector3d(0.0f, 0.0f, -1.0f)))
						bras.rotate(Vector3d(0.0f, 0.0f, -1.0f));
				break;
			case SDLK_q:
				finger1.rotate(Vector3d(0.0f, 0.0f, -1.0f));
				break;
			case SDLK_a:
				finger1.rotate(Vector3d(0.0f, 0.0f, 1.0f));
				break;
			case SDLK_w:
				finger2.rotate(Vector3d(0.0f, 0.0f, -1.0f));
				break;
			case SDLK_s:
				finger2.rotate(Vector3d(0.0f, 0.0f, 1.0f));
				break;
			case SDLK_e:
				finger3.rotate(Vector3d(0.0f, 0.0f, -1.0f));
				break;
			case SDLK_d:
				finger3.rotate(Vector3d(0.0f, 0.0f, 1.0f));
				break;
			default:
				break;
			}

	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Context &c = Context::getInstance();


	SDL_Event ev;

	Grid grid(40, 40, Vector3d(30.0f, 0.0f, 30.0f), Vector3d(-15.0f, 0.0f, -30.0f));
	int current = 0;


	finger1.setMin(Vector3d(0,0,-90));
	finger1.setMax(Vector3d(0,0,90));
	finger2.setMin(Vector3d(0,0,-90));
	finger2.setMax(Vector3d(0,0,90));
	finger3.setMin(Vector3d(0,0,-90));
	finger3.setMax(Vector3d(0,0,90));

	poignet.setMin(Vector3d(0,0,-90));
	poignet.setMax(Vector3d(0,0,90));

	avantPoignet.setMin(Vector3d(0,0,-40));
	avantPoignet.setMax(Vector3d(0,0,40));

	poignet.push(&finger1);
	poignet.push(&finger2);
	poignet.push(&finger3);
	avantPoignet.push(&poignet);
	bras.push(&avantPoignet);

	if (!c.init())
		return -1;

	while (c.run(ev))
	{
		SDL_PollEvent(&ev);
			
		
		myFinger(ev);

		if (ev.type == SDL_QUIT || ev.key.keysym.sym == SDLK_ESCAPE)
		{
			c.stop();
		}
	
		c.endOfLoop();
	}
	c.uninit();
	return 0;
}

