#include "../Tools/_Matrix.h"
#include "../Tools/_Vector.h"
#include "../Tools/_Model.h"
#include <iostream>		// 包含标准的输入输出头文件
#include <windows.h>	// 包含系统头文件
#include <easyx.h>		// 包含Easyx图形库
#include <vector>
using namespace _Matrix::Matrix_2D;    // 包含Matrix_2D命名空间,也就是包含矩阵的命名空间
using namespace _Vector::Vector_2D;    // 包含Vector_2D命名空间,也就是包含向量的命名空间
using namespace _Model::Model2D;	   // 包含Model命名空间，也就是包含这个2D模型的命名空间
using namespace std;    // 包含std命名空间

ExMessage msg; // 定义了一个消息结构体
bool Running = true; // 程序的运行状态

double r;  // 模型的绕世界坐标系旋转角度
double sx; // 这个模型的向x缩放多少倍
double sy; // 这个模型的向y缩放多少倍
double tx; // 这个模型的向x移动多少个距离
double ty; // 这个模型的向y移动多少个距离

double X; // 模型在世界坐标系中的x坐标，也就是这个模型下的模型坐标系中的原点在世界坐标系中的位置
double Y; // 模型在世界坐标系中的y坐标，也就是这个模型下的模型坐标系中的原点在世界坐标系中的位置
double R; // 模型的旋转角度
Model2D Triangle; // 定义了一个三角形模型

Matrix2D_Scaling Scaling; // 定义了一个缩放矩阵，用来给这个三角形模型做变换
Matrix2D_Rotation Rotation; // 定义了一个旋转矩阵，也是用来给这个三角形模型做变换的
Matrix2D_Translation Translation; // 定义了一个平移矩阵，也是用来给这个三角形模型做变换的

vector<Vector2D> Triangle_Vertex_World; // 定义了一个容器，用来存储这个三角形模型的顶点坐标转化到世界下的坐标，到时候就是用这个三角形模型下的顶点的世界坐标来绘制这个三角形模型的

void Draw(); // 绘制场景
void Init(); // 初始化场景
void Update(); // 更新场景

int main() // 主函数，就是程序的入口
{
	initgraph(800, 600, EX_SHOWCONSOLE); // 初始化这个图形窗口
	setbkcolor(BLACK); // 设置图形窗口的背景颜色
	cleardevice(); // 清楚绘图缓冲区，并用背景颜色填充整个窗口

	Init(); // 初始化场景
	BeginBatchDraw(); // 开启双缓冲绘图
	while (Running)
	{
		while (peekmessage(&msg, EX_KEY))
		{
			switch (msg.message) // 判断消息类型
			{
				case WM_KEYDOWN:
					switch (msg.vkcode) // 获取用户按下的什么键
					{
						case 'W':
							ty -= 5;
							break;
						case 'S':
							ty += 5;
							break;
						case 'A':
							tx -= 5;
							break;
						case 'D':
							tx += 5;
							break;
						case 'L':
							r += 0.1;
							break;
						case 'R':
							r -= 0.1;
							break;
						case VK_LEFT:
							R += 0.1;
							break;
						case VK_RIGHT:
							R -= 0.1;
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}
		}
		cleardevice(); // 清除绘图缓冲区
		Update(); // 更新场景
		Draw(); // 绘制场景
		FlushBatchDraw(); // 刷新绘图缓冲区
	}
	EndBatchDraw(); // 关闭双缓冲绘图
	return 0; // 程序的返回值，如果返回0，代表程序正常退出
}

void Init()
{
	/*-----------------初始化这个场景中三角形模型-----------------*/
	// 初始化这个三角形模型的顶点
	vector<Vector2D> Triangle_Vertex;
	Triangle_Vertex.push_back(Vector2D(0, 50, 1));
	Triangle_Vertex.push_back(Vector2D(0, 0, 1));
	Triangle_Vertex.push_back(Vector2D(50, 0, 1));
	Triangle.Set_Vertex(Triangle_Vertex);

	// 初始化这个三角形模型的顶点索引
	vector<Vector2D> Triangle_Vertex_Index;
	Triangle_Vertex_Index.push_back(Vector2D(0, 1, 1));
	Triangle_Vertex_Index.push_back(Vector2D(0, 2, 1));
	Triangle_Vertex_Index.push_back(Vector2D(1, 2, 1));
	Triangle.Set_Vertex_Index(Triangle_Vertex_Index);

	// 设置这个三角形模型在世界坐标系中的坐标和这个三角形模型的旋转角度
	X = 100;
	Y = 100;
	R = 0;
	Triangle.SetModelX(X);
	Triangle.SetModelY(Y);
	Triangle.SetModelR(R);

	// 初始化这个缩放矩阵
	sx = 1;
	sy = 1;
	Scaling.SetS(sx, sy);

	// 初始化这个平移矩阵
	tx = 0;
	ty = 0;
	Translation.SetT(tx, ty);

	// 初始化这个旋转矩阵
	r = 0;
	Rotation.SetR(r);
}

void Update()
{
	Rotation.SetR(r);
	Translation.SetT(tx, ty);

	X = Triangle.GetModelX();
	Y = Triangle.GetModelY();
	Vector2D v(X, Y, 1);
	v = (Translation * Rotation) * v;
	Triangle.SetModelX(v[0]);
	Triangle.SetModelY(v[1]);
	Triangle.SetModelR(R);
	Triangle_Vertex_World = Matrix2D::Model_To_World(Triangle);
	cout << "x: " << v[0] << "\t" << "y: " << v[1] << endl;

	tx = 0;
	ty = 0;
	r = 0;
}

void Draw()
{
	setlinecolor(WHITE); // 设置线条颜色

	/*-----------------绘制这个场景中三角形模型-----------------*/
	// 获取这个三角形模型的顶点和这个三角形模型的顶点索引
	// vector<Vector2D> Triangle_Vertex = Triangle.Get_Vertex();
	vector<Vector2D> Triangle_Vertex_Index = Triangle.Get_Vectex_Index();

	// 然后再根据这个三角形模型的顶点索引把这个三角形给回绘制出来，那怎么绘制呢？，其实很简单，首先，先获取当前索引的第0个，和第1个，因为每一个的索引就是一条线，也就是说，先获取这条线的起始坐标，和这条线的结束坐标，然后在通过这个索引去访问顶点坐标里的的x坐标和y坐标，然后就可以将这条线给绘制出来，循环整个的顶点索引，就可以把这个2D的模型给绘制出来
	for (int i = 0; i < Triangle_Vertex_Index.size(); i++)
	{
		int index = Triangle_Vertex_Index[i][0];
		int index1 = Triangle_Vertex_Index[i][1];
		line(Triangle_Vertex_World[index][0], Triangle_Vertex_World[index][1], Triangle_Vertex_World[index1][0], Triangle_Vertex_World[index1][1]);
	}
}