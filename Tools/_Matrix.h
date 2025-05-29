#include "../Tools/_Vector.h"
#include <stdexcept>
#include <iostream>
#include <cmath>
using namespace _Vector::Vector_2D;
#pragma once // 防止头文件重复包含而导致的重定义问题

namespace _Matrix // 定义了一个命名空间，用于组织代码，避免命名冲突
{
	namespace Matrix_2D // 定义了一个2D矩阵命名空间，用于组织代码，避免命名冲突
	{
		class Matrix2D
		{
			protected:
			private:
				Vector2D _Matrix2D[3]; // 2D矩阵
			public:
				Matrix2D(); // 默认构造函数，用于初始化2D矩阵
				Matrix2D(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3);// 有参构造函数，用于初始化2D矩阵

				void Set_Matrix2D(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3); // 设置矩阵
				void Clear_Matrix(); // 清除矩阵，也就是清空矩阵

				Vector2D& operator[](int index); // 重载了下标运算符，这样用户就可以通过下标来访问2D矩阵里面的值
				const Vector2D& operator[](int index) const; // 重载了下标运算符，这样用户就可以通过下标来访问2D矩阵里面的值
				Matrix2D operator*(const Matrix2D& v) const; // 重载了乘法运算符，用来实现矩阵的乘法
				Vector2D operator*(const Vector2D& v) const; // 重载了乘法运算符，用来实现矩阵与向量的乘法
				Matrix2D operator+(const Matrix2D& v) const; // 重载了加法运算符，用来实现矩阵的加法
				Matrix2D operator-(const Matrix2D& v) const; // 重载了减法运算符，用来实现矩阵的减法
				void operator=(const Matrix2D& v); // 重载了赋值运算符，用来实现矩阵的拷贝或者叫复值
			};
			class Matrix2D_Scaling : public Matrix2D
			{
				protected:
				private:
				public:
					Matrix2D_Scaling(); // 默认的构造函数，用于初始化这个缩放矩阵
					Matrix2D_Scaling(double Sx, double Sy); // 有参的构造函数，用于初始化这个缩放矩阵

					void SetS(double Sx,double Sy); // 设置缩放大小
			};

			class Matrix2D_Translation : public Matrix2D
			{
				protected:
				private:
				public:
					Matrix2D_Translation(); // 默认的构造函数，用于初始化这个缩放矩阵
					Matrix2D_Translation(double Tx, double Ty); // 有参的构造函数，用于初始化这个缩放矩阵

					void SetT(double Tx, double Ty); // 设置平移距离
			};
			class Matrix2D_Rotation : public Matrix2D
			{
				protected:
				private:
				public:
					Matrix2D_Rotation(); // 默认的构造函数，用于初始化这个缩放矩阵
					Matrix2D_Rotation(double R); // 有参的构造函数，用于初始化这个缩放矩阵

					void SetR(double R); // 设置旋转角度
		};
	}
	namespace Matrix_3D // 定义了一个3D矩阵命名空间，用于组织代码，避免命名冲突
	{

	}
}