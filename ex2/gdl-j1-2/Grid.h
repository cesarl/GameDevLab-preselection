#pragma once

#include		<SDL.h>
#include		<gl/GL.h>
#include		<gl/GLU.h>
#include "Vector3d.hpp"

class Grid
{
public:
	Grid(unsigned int column,
		unsigned int row,
		const Vector3d &dimension = Vector3d(10.0f, 10.0f, 10.0f),
		const Vector3d &position = Vector3d(0.0f, 0.0f, 0.0f),
		const Vector3d &rotation = Vector3d(0.0f, 0.0f, 0.0f));
	~Grid(void);
	void draw();
private:
	int column_;
	int row_;
	Vector3d dim_;
	Vector3d pos_;
	Vector3d rot_;
};

