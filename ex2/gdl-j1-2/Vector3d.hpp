#pragma once

class		Vector3d
{
public:
  float	x;
  float	y;
  float	z;
public:
  Vector3d();
  Vector3d(const Vector3d& other);
  Vector3d(float x, float y, float z);
  ~Vector3d();
  float	getX() const { return this->x; }
  void		setX(float v) { this->x = v; }
  float	getY() const { return this->y; }
  void		setY(float v) { this->y = v; }
  float	getZ() const { return this->z; }
  void		setZ(float v) { this->z = v; }
  Vector3d	&operator=(float value);
  Vector3d	&operator+=(float value);
  Vector3d	&operator-=(float value);
  Vector3d	&operator*=(float value);
  Vector3d	&operator/=(float value);
  Vector3d	&operator+=(const Vector3d& other);
  Vector3d	&operator-=(const Vector3d& other);
  Vector3d	&operator*=(const Vector3d& other);
  Vector3d	&operator/=(const Vector3d& other);
  bool		operator==(const Vector3d& other) const;
  bool		operator!=(const Vector3d& other) const;
  Vector3d	&operator=(const Vector3d& other);
  float	distance(const Vector3d& other);
  float	length();
  float	dotProduct(const Vector3d& other);
  Vector3d	crossProduct(const Vector3d& other);
  Vector3d	normal();
  float	angle(const Vector3d& other);
};

Vector3d	operator+(const Vector3d& left, const Vector3d& right);
Vector3d	operator-(const Vector3d& left, const Vector3d& right);
Vector3d	operator*(const Vector3d& left, const Vector3d& right);
Vector3d	operator/(const Vector3d& left, const Vector3d& right);

