#include "StdAfx.h"
#include "Grid.h"


Grid::Grid(unsigned int column,
		unsigned int row,
		const Vector3d &dimension,
		const Vector3d &position,
		const Vector3d &rotation) :
	column_(column),
	row_(row),
	dim_(dimension),
	pos_(position),
	rot_(rotation)
{
}

void Grid::draw()
{
    glPushMatrix();

    glTranslatef(pos_.x, pos_.y, pos_.z);

    glTranslatef(dim_.x / 2.0f, dim_.y / 2.0f, dim_.z / 2.0f);

    glRotatef(rot_.x, 1.0f, 0.0f, 0.0f);
    glRotatef(rot_.y, 0.0f, 1.0f, 0.0f);
    glRotatef(rot_.z, 0.0f, 0.0f, 1.0f);

    glTranslatef(- dim_.x / 2.0f, - dim_.y / 2.0f, - dim_.z / 2.0f);

	glColor3f(0.2f,0.6f,0.3f);

    glBegin(GL_LINES);

	float w = this->dim_.x / this->row_;
	float h = this->dim_.z / this->column_;

	for (int i = 0; i < this->row_; i++)
	{
		glVertex3f(w * (float)i, 0, 0);
		glVertex3f(w *(float)i, 0, this->dim_.z);
	}

	for (int i = 0; i < this->column_; i++)
	{
		glVertex3f(0, 0, h * (float)i);
		glVertex3f(this->dim_.z, 0, h * (float)i);
	}
    glEnd();

    glPopMatrix();	
}

Grid::~Grid(void)
{
}
