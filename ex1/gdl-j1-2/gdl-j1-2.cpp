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
	bras.draw();

	if (ev.type == SDL_KEYDOWN)
		{
			switch(ev.key.keysym.sym)
			{
			case SDLK_LEFT:
				bras.rotate(Vector3d(0.0f, 0.0f, 1.0f));
				break;
			case SDLK_RIGHT:
				bras.rotate(Vector3d(0.0f, 0.0f, -1.0f));
				break;
			case SDLK_UP:
				avantPoignet.rotate(Vector3d(0.0f, 0.0f, 1.0f));
				break;
			case SDLK_DOWN:
				avantPoignet.rotate(Vector3d(0.0f, 0.0f, -1.0f));
				break;
			default:
				break;
			}

	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Context &c = Context::getInstance();
	Cube cube1(Vector3d(1.0f, 1.0f, 1.0f),
				Vector3d(0.0f, 0.0f, -10.0f),
				Vector3d(0.0f, 0.0f, 0.0f));

	Cube cube2(Vector3d(0.3f, 0.3f, 0.3f),
				Vector3d(0.4f, 1.0f, -9.7f),
				Vector3d(0.0f, 0.0f, 0.0f));

	SDL_Event ev;
	Vector3d move;
	Grid grid(40, 40, Vector3d(30.0f, 0.0f, 30.0f), Vector3d(-15.0f, 0.0f, -30.0f));
	int current = 0;

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
		/*while(SDL_PollEvent(&ev))
		{*/
		move = Vector3d(0.0f, 0.0f, 0.0f);
		
		if (ev.type == SDL_KEYDOWN)
		{
			switch(ev.key.keysym.sym)
			{
			case SDLK_LEFT:
				move.x -= 0.5f;
				break;
			case SDLK_RIGHT:
				move.x +=0.5f;
				break;
			default:
				break;
			}
			switch(ev.key.keysym.sym)
			{
			case SDLK_UP:
				move.z -= 0.5f;
				break;
			case SDLK_DOWN:
				move.z += 0.5f;
				break;
			default:
				break;
			}
		}

		else if (ev.type == SDL_KEYUP)
		{
				switch(ev.key.keysym.sym)
				{
				case SDLK_LEFT:
					move.x = 0.0f;
					break;
				case SDLK_RIGHT:
					move.x = 0.0f;
					break;
				default:
					break;
				}
				switch(ev.key.keysym.sym)
				{
				case SDLK_UP:
					move.z = 0.0f;
					break;
				case SDLK_DOWN:
					move.z = 0;
					break;
				default:
					break;
				}
		}

		cube1.move(move);
		cube2.move(move);

		if (ev.type == SDL_QUIT || ev.key.keysym.sym == SDLK_ESCAPE)
		{
			c.stop();
		}
	
	
		/*}*/
		cube2.draw();
		cube1.draw();
		grid.draw();
		cube1.rotate(Vector3d(0.0f, 2.0f, 0.0f));
		cube2.rotate(Vector3d(3.0f, 2.0f, 1.0f));
		c.endOfLoop();
	}
	c.uninit();
	return 0;
}

