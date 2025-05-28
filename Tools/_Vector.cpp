#include "../Tools/_Vector.h"
#include <stdexcept>
#include <iostream>

_Vector::Vector2D::Vector2D()
	: x(0), y(0), w(0)
{

}

_Vector::Vector2D::Vector2D(const Vector2D& v)
	:x(v.x),y(v.y),w(v.w)
{

}

_Vector::Vector2D::Vector2D(double x,double y,double w) 
	: x(x), y(y), w(w) 
{

}


double _Vector::Vector2D::GetX() const
{
	return x;
}

double _Vector::Vector2D::GetY() const
{
	return y;
}

double _Vector::Vector2D::GetW() const
{
	return w;
}


void _Vector::Vector2D::SetX(double x)
{
	this->x = x;
}

void _Vector::Vector2D::SetY(double y)
{
	this->y = y;
}

void _Vector::Vector2D::SetW(double w)
{
	this->w = w;
}

double _Vector::Vector2D::operator[](int index)
{
	if (index >= 0 && index <= 2)
	{
		switch (index)
		{
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return w;
		}
	}
	else
	{
		throw std::out_of_range("Index out of range");
		return -1;
	}
}

_Vector::Vector2D _Vector::Vector2D::operator*(const _Vector::Vector2D& v) const
{
	return Vector2D(x * v.x, y * v.y, w * v.w);
}

_Vector::Vector2D _Vector::Vector2D::operator+(const _Vector::Vector2D& v) const
{
	return Vector2D(x + v.x, y + v.y, w + v.w);
}

_Vector::Vector2D _Vector::Vector2D::operator-(const _Vector::Vector2D& v) const
{
	return Vector2D(x - v.x, y - v.y, w - v.w);
}

void _Vector::Vector2D::operator=(const _Vector::Vector2D& v)
{
	this->x = v.x;
	this->y = v.y;
	this->w = v.w;
}

_Vector::Vector3D::Vector3D()
	:Vector2D(),z(0)
{

}

_Vector::Vector3D::Vector3D(const Vector3D& v)
	:x(v.x), y(v.y), z(v.z), w(v.w)
{

}

_Vector::Vector3D::Vector3D(double x, double y, double z, double w)
	:Vector2D(x,y,w),z(z)
{

}

//double _Vector::Vector3D::GetX() const
//{
//	return x;
//}
//
//double _Vector::Vector3D::GetY() const
//{
//	return y;
//}
//
double _Vector::Vector3D::GetZ() const
{
	return z;
}

//double _Vector::Vector3D::GetW() const
//{
//	return w;
//}



//void _Vector::Vector3D::SetX(double x)
//{
//	this->x = x;
//}
//
//void _Vector::Vector3D::SetY(double y)
//{
//	this->y = y;
//}
//
void _Vector::Vector3D::SetZ(double z)
{
	this->z = z;
}

//void _Vector::Vector3D::SetW(double w)
//{
//	this->w = w;
//}

double _Vector::Vector3D::operator[](int index)
{
	if (index >= 0 && index <= 3)
	{
		switch (index)
		{
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			case 3:
				return w;
		}
	}
	else
	{
		throw std::out_of_range("Index out of range");
		return -1;
	}
}

_Vector::Vector3D _Vector::Vector3D::operator*(const _Vector::Vector3D& v) const
{
	return Vector3D(x * v.x, y * v.y, z * v.z, w * v.w);
}

_Vector::Vector3D _Vector::Vector3D::operator+(const _Vector::Vector3D& v) const
{
	return Vector3D(x + v.x, y + v.y, z + v.z, w + v.w);
}

_Vector::Vector3D _Vector::Vector3D::operator-(const _Vector::Vector3D& v) const
{
	return Vector3D(x - v.x, y - v.y, z - v.z, w - v.w);
}

void _Vector::Vector3D::operator=(const _Vector::Vector3D& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;
}