#ifndef			__CUBE_HPP__
# define		__CUBE_HPP__

#include        "stdafx.h"
#include		"Vector3d.hpp"
#include		<vector>

class			Cube
{
public:
  Cube(Vector3d dim = Vector3d(0.0f, 0.0f, 0.0f),
       Vector3d pos = Vector3d(0.0f, 0.0f, 0.0f),
	 Vector3d rot = Vector3d(0.0f, 0.0f, 0.0f)) :
    dim_(dim),
    pos_(pos),
    rot_(rot)
  {}

  ~Cube(){}
  void			draw()
  {
    glPushMatrix();

	glTranslatef(pos_.x, pos_.y, pos_.z);
	
	glTranslatef(dim_.x / 2.0f, dim_.y / 2.0f, dim_.z / 2.0f);

	glRotatef(rot_.x, 1.0f, 0.0f, 0.0f);
    glRotatef(rot_.y, 0.0f, 1.0f, 0.0f);
    glRotatef(rot_.z, 0.0f, 0.0f, 1.0f);

    glTranslatef(- dim_.x / 2.0f, - dim_.y / 2.0f, - dim_.z / 2.0f);

	

    glBegin(GL_QUADS);

    glColor3f(1.0f,1.0f,0.3f);

    //Quad 1
    glVertex3f(dim_.x, dim_.y, dim_.z);
    glVertex3f( dim_.x, 0.0f, dim_.z);
    glVertex3f( dim_.x,0.0f, 0.0f);
    glVertex3f( dim_.x, dim_.y, 0.0f);
    //Quad 2

    glColor3f(1.0f,0.8f,0.2f);
    glVertex3f( dim_.x, dim_.y, 0.0f);
    glVertex3f( dim_.x, 0.0f, 0.0f);
    glVertex3f( 0.0f, 0.0f, 0.0f);
    glVertex3f( 0.0f, dim_.y, 0.0f);

    glColor3f(0.5f,0.8f,0.7f);
    //Quad 3
    glVertex3f(0.0f, dim_.y, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, dim_.z);
    glVertex3f(0.0f, dim_.y, dim_.z);
    //Quad 4
    glColor3f(0.3f,0.3f,1.0f);
    glVertex3f(0.0f, dim_.y, dim_.z);
    glVertex3f( 0.0f, 0.0f, dim_.z);
    glVertex3f( dim_.x,0.0f, dim_.z);
    glVertex3f( dim_.x, dim_.y, dim_.z);
    //Quad 5
    glColor3f(0.765f,0.234f,0.234f);
    glVertex3f(0.0f, dim_.y, 0.0f);
    glVertex3f(0.0f, dim_.y, dim_.z);
    glVertex3f( dim_.x, dim_.y, dim_.z);
    glVertex3f( dim_.x, dim_.y, 0.0f);
    //Quad 6
    glColor3f(0.65f,0.34f,0.2f);
    glVertex3f(0.0f,0.0f, dim_.z);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(dim_.x,0.0f,0.0f);
    glVertex3f(dim_.x, 0.0f, dim_.z);
    glEnd();

    glPopMatrix();
	glPushMatrix();


	glTranslatef(dim_.x / 2.0f, dim_.y / 2.0f,  dim_.z / 2.0f);

    glRotatef(rot_.x, 1.0f, 0.0f, 0.0f);
    glRotatef(rot_.y, 0.0f, 1.0f, 0.0f);
    glRotatef(rot_.z, 0.0f, 0.0f, 1.0f);

	t_iter it;
	it = this->list_.begin();
	while (it != this->list_.end())
	{
		(*it)->draw();
		++it;
	}

	glTranslatef(- dim_.x / 2.0f, - dim_.y / 2.0f, - dim_.z / 2.0f);


	glPopMatrix();
  }

  void			push(Cube * c)
  {
	this->list_.push_back(c);
  }

  void			rotate(const Vector3d &v)
  {
		this->rot_ += v;
		if (this->rot_.x > 360.0f)
			this->rot_.x = 0.0f;
		if (this->rot_.y > 360.0f)
			this->rot_.y = 0.0f;
		if (this->rot_.z > 360.0f)
			this->rot_.z = 0.0f;
  }

  void			move(const Vector3d &v)
  {
	this->pos_ += v;
  }
private:
  Vector3d		dim_;
  Vector3d		pos_;
  Vector3d		rot_;
  std::vector<Cube*> list_;

  typedef std::vector<Cube*>::iterator t_iter;
};

#endif			// __CUBE_HPP__
