#include                "StdAfx.h"
#include				<cmath>
#include				"Vector3d.hpp"

Vector3d::Vector3d()
  : x(0)
  , y(0)
  , z(0)
{
}

Vector3d::Vector3d(const Vector3d& other)
  : x(other.x)
  , y(other.y)
  , z(other.z)
{
}

Vector3d::Vector3d(float x, float y, float z)
  : x(x)
  , y(y)
  , z(z)
{
}

Vector3d::~Vector3d()
{
}

Vector3d				&Vector3d::operator+=(const Vector3d& other)
{
  this->x += other.x;
  this->y += other.y;
  this->z += other.z;
  return (*this);
}

Vector3d				&Vector3d::operator-=(const Vector3d& other)
{
  this->x -= other.x;
  this->y -= other.y;
  this->z -= other.z;
  return (*this);
}

Vector3d				&Vector3d::operator*=(const Vector3d& other)
{
  this->x *= other.x;
  this->y *= other.y;
  this->z *= other.z;
  return (*this);
}

Vector3d				&Vector3d::operator/=(const Vector3d& other)

{
  this->x /= other.x;
  this->y /= other.y;
  this->z /= other.z;
  return (*this);
}

Vector3d				&Vector3d::operator=(float value)
{
  this->x = value;
  this->y = value;
  this->z = value;
  return (*this);
}

Vector3d				&Vector3d::operator+=(float value)
{
  this->x += value;
  this->y += value;
  this->z += value;
  return (*this);
}

Vector3d				&Vector3d::operator-=(float value)
{
  this->x -= value;
  this->y -= value;
  this->z -= value;
  return (*this);
}

Vector3d				&Vector3d::operator*=(float value)
{
  this->x *= value;
  this->y *= value;
  this->z *= value;
  return (*this);
}

Vector3d				&Vector3d::operator/=(float value)
{
  this->x /= value;
  this->y /= value;
  this->z /= value;
  return (*this);
}

Vector3d				operator+(const Vector3d& left, const Vector3d& right)
{
  Vector3d				tmp(left);

  tmp += right;
  return (tmp);
}

Vector3d				operator-(const Vector3d& left, const Vector3d& right)
{
  Vector3d				tmp(left);

  tmp -= right;
  return (tmp);
}

Vector3d				operator*(const Vector3d& left, const Vector3d& right)
{
  Vector3d				tmp(left);

  tmp *= right;
  return (tmp);
}

Vector3d				operator/(const Vector3d& left, const Vector3d& right)
{
  Vector3d				tmp(left);

  tmp /= right;
  return (tmp);
}

bool					Vector3d::operator==(const Vector3d& other) const
{
  return (
	  (((other.x - 0.0001f) < this->x) && (this->x < (other.x + 0.0001f))) &&
	  (((other.y - 0.0001f) < this->y) && (this->y < (other.y + 0.0001f))) &&
	  (((other.z - 0.0001f) < this->z) && (this->z < (other.z + 0.0001f))) );
}

bool					Vector3d::operator!=(const Vector3d& other) const
{
  return (!(*this == other));
}

Vector3d				&Vector3d::operator=(const Vector3d& other)
{
  this->x = other.x;
  this->y = other.y;
  this->z = other.z;
  return *this;
}

float					Vector3d::distance(const Vector3d& other)
{
  return sqrt((other.x - this->x) * (other.x - this->x)
	      + (other.y - this->y) * (other.y - this->y));
}
float					Vector3d::length()
{
  return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

float					Vector3d::dotProduct(const Vector3d& other)
{
  return (this->x * other.x + this->y * other.y + this->z * other.z);

}

Vector3d				Vector3d::crossProduct(const Vector3d& other)
{
  float nx = (this->y * other.z) - (this->z * other.y);
  float ny = (this->z * other.x) - (this->x * other.z);
  float nz = (this->x * other.y) - (this->y * other.x);

  return Vector3d(nx, ny, nz);
}

Vector3d				Vector3d::normal()
{
  float length;
  if (this->length() == 0)
    length = 0.0f;
  else
    length = 1.0f / this->length();
  this->x *= length;
  this->y *= length;
  this->z *= length;
  return *this;
}

float					Vector3d::angle(const Vector3d& other)
{
  float dx = this->x - other.x;
  float dy = this->y - other.y;

  return (atan2(dy, dx) / 3.1415926535897f * 180.0f);
}
