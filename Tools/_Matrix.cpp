#include "../Tools/_Matrix.h"
#include <stdexcept>
#include <iostream>

_Matrix::Matrix2D::Matrix2D()
{

}

_Matrix::Matrix2D::Matrix2D(_Vector::Vector3D v1, _Vector::Vector3D v2, _Vector::Vector3D v3)
{
	_Matrix2D[0] = v1;
	_Matrix2D[1] = v2;
	_Matrix2D[2] = v3;
}

_Vector::Vector2D& _Matrix::Matrix2D::operator[](int index)
{
	if (index >= 0 && index <= 2)
	{
		return _Matrix2D[index];
	}
	else 
	{
		throw std::out_of_range("Index out of range");
	}
}