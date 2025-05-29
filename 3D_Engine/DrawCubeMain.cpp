#include "../Tools/_Matrix.h"
#include "../Tools/_Vector.h"
#include <iostream>		// 包含标准的输入输出头文件
#include <easyx.h>		// 包含Easyx图形库
using namespace _Matrix::Matrix_2D;    // 包含Matrix_2D命名空间,也就是包含矩阵的命名空间
using namespace _Vector::Vector_2D;    // 包含Vector_2D命名空间,也就是包含向量的命名空间
using namespace std;    // 包含std命名空间

int main() // 程序主函数，也就是程序的入口函数
{
	Vector2D v1(2, 3, 1); // 定义了一个二维的向量对象
	Matrix2D v2(
		Vector2D(1, 0, 2),
		Vector2D(0, 1, 2),
		Vector2D(0, 0, 1)
	); // 定义了一个2D矩阵对象
	Matrix2D v3(
		Vector2D(2, 0, 0),
		Vector2D(0, 2, 0),
		Vector2D(0, 0, 1)
	); // 定义了一个2D矩阵对象
	Matrix2D_Translation v6(2,2); // 定义了一个2D平移矩阵对象
	Matrix2D_Scaling v7(2,2); // 定义了一个2D缩放矩阵对象
	Matrix2D v8 = v6 * v7;
	Matrix2D v5 = v2 * v3; // 矩阵和矩阵相乘，并拷贝给新的2D矩阵对象
	Vector2D v4 = v5 * v1; // 矩阵与向量相乘，并拷贝给新的2D向量对象
	for (int i = 0; i < 3; i++)
	{
		cout << v4[i] << endl;
	}
	return 0; //程序的返回值，如果返回0代表程序正常退出，否则程序就是非正常退出
}