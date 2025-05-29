#include "../Tools/_Vector.h"
using namespace _Vector::Vector_2D;
using namespace _Vector::Vector_3D;

Vector2D::Vector2D()
	: x(0), y(0), w(0)
{

}

Vector2D::Vector2D(const Vector2D& v)
	:x(v.x),y(v.y),w(v.w)
{

}

Vector2D::Vector2D(double x,double y,double w) 
	: x(x), y(y), w(w) 
{

}


double Vector2D::GetX() 
{
	return x;
}

double Vector2D::GetY()
{
	return y;
}

double Vector2D::GetW()
{
	return w;
}


void Vector2D::SetX(double x)
{
	this->x = x;
}

void Vector2D::SetY(double y)
{
	this->y = y;
}

void Vector2D::SetW(double w)
{
	this->w = w;
}

const double& Vector2D::operator[](int index) const
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
	}
}

double& Vector2D::operator[](int index)
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
	}
}

Vector2D Vector2D::operator*(const Vector2D& v) const
{
	return Vector2D(x * v.x, y * v.y, w * v.w);
}

Vector2D Vector2D::operator+(const Vector2D& v) const
{
	return Vector2D(x + v.x, y + v.y, w + v.w);
}

Vector2D Vector2D::operator-(const Vector2D& v) const
{
	return Vector2D(x - v.x, y - v.y, w - v.w);
}

void Vector2D::operator=(const Vector2D& v)
{
	this->x = v.x;
	this->y = v.y;
	this->w = v.w;
}

Vector3D::Vector3D()
	:Vector2D(),z(0)
{

}

Vector3D::Vector3D(const Vector3D& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;
}

Vector3D::Vector3D(double x, double y, double z, double w)
	:Vector2D(x,y,w),z(z)
{

}

//double Vector3D::GetX() const
//{
//	return x;
//}
//
//double Vector3D::GetY() const
//{
//	return y;
//}
//
double Vector3D::GetZ() const
{
	return z;
}

//double Vector3D::GetW() const
//{
//	return w;
//}



//void Vector3D::SetX(double x)
//{
//	this->x = x;
//}
//
//void Vector3D::SetY(double y)
//{
//	this->y = y;
//}
//
void Vector3D::SetZ(double z)
{
	this->z = z;
}

//void Vector3D::SetW(double w)
//{
//	this->w = w;
//}

const double& Vector3D::operator[](int index) const
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
	}
}

double& Vector3D::operator[](int index)
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
	}
}

Vector3D Vector3D::operator*(const Vector3D& v) const
{
	return Vector3D(x * v.x, y * v.y, z * v.z,w * v.w);
}

Vector3D Vector3D::operator+(const Vector3D& v) const
{
	return Vector3D(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vector3D Vector3D::operator-(const Vector3D& v) const
{
	return Vector3D(x - v.x, y - v.y, z - v.z, w - v.w);
}

void Vector3D::operator=(const Vector3D& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;
}