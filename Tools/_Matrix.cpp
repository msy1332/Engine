#include "../Tools/_Matrix.h"
using namespace _Matrix::Matrix_2D;

_Matrix::Matrix_2D::Matrix2D::Matrix2D()
{
	_Matrix2D[0] = { 1,0,0 };
	_Matrix2D[1] = { 0,1,0 };
	_Matrix2D[2] = { 0,0,1 };
}

_Matrix::Matrix_2D::Matrix2D::Matrix2D(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3)
{
	_Matrix2D[0] = v1;
	_Matrix2D[1] = v2;
	_Matrix2D[2] = v3;
}

Vector2D& Matrix2D::operator[](int index)
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

void Matrix2D::Set_Matrix2D(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3)
{
	_Matrix2D[0] = v1;
	_Matrix2D[1] = v2;
	_Matrix2D[2] = v3;
}

void Matrix2D::Clear_Matrix()
{
	_Matrix2D[0] = { 1,0,0 };
	_Matrix2D[1] = { 0,1,0 };
	_Matrix2D[2] = { 0,0,1 };
}

const Vector2D& Matrix2D::operator[](int index) const
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

std::vector<Vector2D> Matrix2D::Model_To_World(const Model2D& model)
{
	double X = model.GetModelX();
	double Y = model.GetModelY();
	double R = model.GetModelR();
	std::vector<Vector2D> Vertex_World;
	std::vector<Vector2D> Mocdel_Vertex = Model2D(model).Get_Vertex();
	for (int i = 0;i < Mocdel_Vertex.size();i++)
	{
		Vector2D v(Mocdel_Vertex[i][0], Mocdel_Vertex[i][1], 1);
		v = Matrix2D_Rotation(R) * v;
		v[0] = v[0] + X;
		v[1] = v[1] + Y;
		Vertex_World.push_back(v);
	}
	return Vertex_World;
}

Matrix2D Matrix2D::operator*(const Matrix2D& v) const
{
	Matrix2D v1;
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0;j < 3;j++)
		{
			v1[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				v1[i][j] += _Matrix2D[i][k] * v._Matrix2D[k][j];
			}
		}
	}
	return v1;
}

Vector2D Matrix2D::operator*(const Vector2D& v) const
{
	Vector2D v1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			v1[i] += _Matrix2D[i][j] * v[j];
		}
	}
	return v1;
}

Matrix2D Matrix2D::operator+(const Matrix2D& v) const
{
	Matrix2D v1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			v1[i][j] = _Matrix2D[i][j] + v[i][j];
		}
	}
	return v1;
}

Matrix2D Matrix2D::operator-(const Matrix2D& v) const
{
	Matrix2D v1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			v1[i][j] = _Matrix2D[i][j] - v[i][j];
		}
	}
	return v1;
}

void Matrix2D::operator=(const Matrix2D& v)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_Matrix2D[i][j] = v[i][j];
		}
	}
}

_Matrix::Matrix_2D::Matrix2D_Scaling::Matrix2D_Scaling()
	: Matrix2D()
{

}

_Matrix::Matrix_2D::Matrix2D_Scaling::Matrix2D_Scaling(double Sx, double Sy)
	: Matrix2D(
		Vector2D(Sx, 0, 0),
		Vector2D(0, Sy, 0),
		Vector2D(0, 0, 1)
	)
{

}

void Matrix2D_Scaling::SetS(double Sx, double Sy)
{
	Set_Matrix2D(
		Vector2D(Sx, 0, 0),
		Vector2D(0, Sy, 0),
		Vector2D(0, 0, 1)
	);
}

_Matrix::Matrix_2D::Matrix2D_Translation::Matrix2D_Translation()
	: Matrix2D()
{

}

_Matrix::Matrix_2D::Matrix2D_Translation::Matrix2D_Translation(double Tx, double Ty)
	: Matrix2D(
		Vector2D(1, 0, Tx),
		Vector2D(0, 1, Ty),
		Vector2D(0, 0, 1)
	)
{

}

void Matrix2D_Translation::SetT(double Tx, double Ty)
{
	Set_Matrix2D(
		Vector2D(1, 0, Tx),
		Vector2D(0, 1, Ty),
		Vector2D(0, 0, 1)
	);
}

_Matrix::Matrix_2D::Matrix2D_Rotation::Matrix2D_Rotation()
	: Matrix2D()
{

}

_Matrix::Matrix_2D::Matrix2D_Rotation::Matrix2D_Rotation(double  R)
	: Matrix2D(
		Vector2D(cos(R), -1 * sin(R), 0),
		Vector2D(sin(R), cos(R), 0),
		Vector2D(0, 0, 1)
	)
{

}

void Matrix2D_Rotation::SetR(double R)
{
	Set_Matrix2D(
		Vector2D(cos(R), -1 * sin(R), 0),
		Vector2D(sin(R), cos(R), 0),
		Vector2D(0, 0, 1)
	);
}