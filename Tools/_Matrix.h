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
	};
}