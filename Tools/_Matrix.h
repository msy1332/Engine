#include "../Tools/_Vector.h"
#pragma once // 防止头文件重复包含而导致的重定义问题

namespace _Matrix // 定义了一个命名空间，用于组织代码，避免命名冲突
{
	class Matrix2D
	{
		protected:
		private:
			_Vector::Vector2D _Matrix2D[3]; // 2D矩阵
		public:
			Matrix2D(); // 默认构造函数，用于初始化2D矩阵
			Matrix2D(_Vector::Vector3D v1, _Vector::Vector3D v2, _Vector::Vector3D v3);// 有参构造函数，用于初始化2D矩阵

			_Vector::Vector2D& operator[](int index); // 重载了下标运算符，这样用户就可以通过下标来访问2D矩阵里面的值
			Matrix2D operator*(const Matrix2D& v) const; // 重载了乘法运算符，用来实现矩阵的乘法
			Matrix2D operator*(const _Vector::Vector2D& v) const; // 重载了乘法运算符，用来实现矩阵与向量的乘法
			Matrix2D operator+(const Matrix2D& v) const; // 重载了加法运算符，用来实现矩阵的加法
			Matrix2D operator-(const Matrix2D& v) const; // 重载了减法运算符，用来实现矩阵的减法
			Matrix2D operator=(const Matrix2D & v); // 重载了赋值运算符，用来实现矩阵的拷贝或者叫复值
			Matrix2D operator+=(const Matrix2D& v); // 重载了加法与赋值的赋和运算符，用来实现矩阵的加法和拷贝，也就是说先是进行矩阵的加法，然后再进行拷贝
			Matrix2D operator-=(const Matrix2D& v); // 重载了减法与赋值的赋和运算符，用来实现矩阵的减法和拷贝，也就是说先是进行矩阵的减法，然后再进行拷贝
	};
}