#include "../Tools/_Matrix.h"
#include "../Tools/_Vector.h"
#include <iostream>		// 包含标准的输入输出头文件
#include <windows.h>	// 包含系统头文件
#include <easyx.h>		// 包含Easyx图形库
using namespace _Matrix::Matrix_2D;    // 包含Matrix_2D命名空间,也就是包含矩阵的命名空间
using namespace _Vector::Vector_2D;    // 包含Vector_2D命名空间,也就是包含向量的命名空间
using namespace std;    // 包含std命名空间

double r = 0;
double sx = 1;
double sy = 1;
double tx = 0;
double ty = 0;
ExMessage msg; // 定义消息结构体
bool Running = true; // 程序的运行状态

Matrix2D M; // 变换后的的矩阵
Matrix2D_Scaling S; // 实例化一个2D缩放矩阵对象
Matrix2D_Rotation R; // 实例化一个2D旋转矩阵对象
Matrix2D_Translation T; // 实例化一个2D平移矩阵对象
Vector2D Square[4]; // 实例化一个2D向量类对象数组，用来存储正方形的四个点的坐标

void Update(); // 更新坐标
void Draw_Square(); // 绘制正方形
void Init_Square(); // 初始化场景

int main() // 程序主函数，也就是程序的入口函数
{
	initgraph(1920, 1080, EX_SHOWCONSOLE); // 创建图形窗口
	setbkcolor(BLACK); // 设置背景颜色
	cleardevice(); // 清除绘图缓冲区，并用背景颜色填充整个窗口

	Init_Square(); // 初始化场景
	BeginBatchDraw(); // 开启双缓冲绘图
	while (Running)
	{
		while (peekmessage(&msg, EX_KEY))
		{
			switch (msg.message) // 判断消息类型
			{
				case WM_KEYDOWN: // 判断是否是键盘按下消息
					switch (msg.vkcode)
					{
						case 'W':
							sy += 0.1;
							cout << "W" << endl;
							break;
						case 'S':
							sy -= 0.1;
							cout << "S" << endl;
							break;
						case 'A':
							sx += 0.1;
							cout << "W" << endl;
							break;
						case 'D':
							sx -= 0.1;
							cout << "S" << endl;
							break;
						case 'L':
							r += 0.1;
							cout << "L" << endl;
							break;
						case 'R':
							r -= 0.1;
							cout << "R" << endl;
							break;
						case VK_UP:
							ty -= 5;
							cout << "UP" << endl;
							break;
						case VK_DOWN:
							ty += 5;
							cout << "DOWN" << endl;
							break;
						case VK_LEFT:
							tx -= 5;
							cout << "LEFT" << endl;
							break;
						case VK_RIGHT:
							tx += 5;
							cout << "RIGHT" << endl;
							break;
						case VK_ESCAPE:
							Running = false;
							break;
					}
					break;
				default:
					break;
			}
		}
		cleardevice(); // 清屏
		Update();
		Draw_Square(); // 绘制正方形
		//Sleep(10000);
		FlushBatchDraw(); // 刷新绘图缓冲区
	}
	EndBatchDraw(); // // 关闭双缓冲绘图
	return 0; //程序的返回值，如果返回0代表程序正常退出，否则程序就是非正常退出
}

void Init_Square()
{
	// 初始化正方形
	Square[0] = { 100,100,1 };
	Square[1] = { 200,100,1 };
	Square[2] = { 100,200,1 };
	Square[3] = { 200,200,1 };

	// 初始化缩放矩阵
	S.SetS(1, 1);

	// 初始化平移矩阵
	T.SetT(0, 0);

	// 初始化旋转矩阵
	R.SetR(0);
}

void Draw_Square()
{
	// 设置线条颜色
	setlinecolor(WHITE);

	// 设置线条样式
	setlinestyle(PS_SOLID, 5);

	// 绘制正方形的上边框和下边框
	line(Square[0][0], Square[0][1], Square[1][0], Square[1][1]);
	line(Square[2][0], Square[2][1], Square[3][0], Square[3][1]);

	// 绘制正方形的左边框和右边框
	line(Square[0][0], Square[0][1], Square[2][0], Square[2][1]);
	line(Square[1][0], Square[1][1], Square[3][0], Square[3][1]);
}

void Update()
{
	R.SetR(r);
	S.SetS(sx, sy);
	T.SetT(tx, ty);
	//M = T;
	cout << "M:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	cout << "S:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << S[i][j] << " ";
		}
		cout << endl;
	}
	cout << "T:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << T[i][j] << " ";
		}
		cout << endl;
	}
	M = S * T * R;
	cout << "M:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//Sleep(5000);
	for (int i = 0; i < 4; i++)
	{
		Square[i] = M * Square[i];
	}
	r = 0;
	sx = 1;
	sy = 1;
	tx = 0;
	ty = 0;
}

/*------------------------------注释------------------------------*/
/*
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
*/