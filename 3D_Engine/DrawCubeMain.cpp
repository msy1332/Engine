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

bool Running = true; // 程序的游戏状态
ExMessage msg; // 定义了一个消息结构体，用来获取消息

// 这个是这个三角形模型在世界坐标系中的位置和这个模型的旋转角度
double X;
double Y;
double R;

// 定义一些矩阵用来给这个三角形模型进行矩阵的变换的，也就是说这些矩阵是用来给这个三角形模型进行旋转，平移，缩放变换的
Matrix2D_Scaling Scaling;		// 定义了一个缩放矩阵
Matrix2D_Rotation Rotation;	// 定义了一个旋转矩阵
Matrix2D_Translation Translation; // 定义了一个平移矩阵

// 定义了一些变量,然后就会通过这些变量来创建旋转，平移，缩放矩阵的，来给这个三角形模型进行矩阵变换的
double r;	// 这个三角形模型绕着世界坐标系旋转的角度
double sx;	// 这个三角形模型向x方向缩放多少倍
double sy;	// 这个三角形模型向y方向缩放多少倍
double tx;	// 这个三角形模型向x方向平移多少距离
double ty;	// 这个三角形模型向y方向平移多少距离

vector<Vector2D> Triangle_Vertex_World; // 这个是这个三角形模型下的顶点的世界坐标
Model2D Triangle; // 定义了一个2D的模型类

void Init();	// 初始化场景，比如说初始化在这个场景中的三角形模型
void Draw();	// 绘制场景，比如说在这个场景中绘制一个三角形模型，那如何绘制呢？，这是通过这个模型的顶点索引来将这个模型给绘制出来的
void Update();	// 更新场景，用于更新这些在场景中的模型的位置

int main() // 主函数，也就是程序的入口
{
	/*---------------------初始化窗口---------------------*/
	initgraph(800, 600, EX_SHOWCONSOLE); // 创建窗口
	setbkcolor(BLACK); // 设置窗口的背景颜色
	cleardevice(); // 清除窗口绘图缓冲区，并用背景颜色来填充整个窗口

	Init(); // 初始化场景
	BeginBatchDraw(); // 开启双缓冲绘图

	while (Running)
	{
		while (peekmessage(&msg, EX_KEY)) // 获取消息，并把获取到的消息存储到消息结构体中
		{
			switch (msg.message) // 判断获取到的消息的类型
			{
				case WM_KEYDOWN: // 键盘按下消息
					switch (msg.vkcode) // 通过vkcode成员来获取用户按下了什么键
					{
						// 通过键盘上的WSAD来控制这个模型的移动
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

						// 然后再通过键盘上的RL来控制这个模型绕着世界坐标系下的旋转
						case 'L':
							r += 0.1;
							break;
						case 'R':
							r -= 0.1;
							break;

						// 然后再通过这个键盘上的左右键，来控制这个模型的旋转
						case VK_LEFT:
							R += 0.1;
							break;
						case VK_RIGHT:
							R -= 0.1;
							break;

						// 然后再通过键盘上的上键和下键来控制这个模型的缩放
						case VK_UP:
							sx += 1;
							sy += 1;
							break;
						case VK_DOWN:
							sx -= 1;
							sy -= 1;
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}
		}
		cleardevice(); // 清除窗口绘图缓冲区，并用背景颜色来填充整个窗口
		Update(); // 更新场景
		Draw(); // 绘制场景
		FlushBatchDraw(); // 刷新绘图缓冲区
	}

	EndBatchDraw(); // 关闭双缓冲绘图
	return 0; // 程序的返回值，如果返回0，代表程序正常退出，否则就是程序异常退出
}

void Init() // 初始化场景
{
	/*-------------------初始化三角形模型-------------------*/
	// 初始化这个三角形模型的顶点坐标
	vector<Vector2D> Triangle_Vertex;
	Triangle_Vertex.push_back(Vector2D(0, 50, 1));
	Triangle_Vertex.push_back(Vector2D(0, 0, 1));
	Triangle_Vertex.push_back(Vector2D(50, 0, 1));
	Triangle.Set_Vertex(Triangle_Vertex);

	// 初始化这个三角形模型的顶点索引，那顶点索引有什么用呢，首先我们可以通过这个模型的顶点索引来描述这个模型的形状，其次就是我们可以通过这个模型的顶点索引来将这个模型给绘制出来
	vector<Vector2D> Triangle_Vertex_Index;
	Triangle_Vertex_Index.push_back(Vector2D(0, 1, 1));
	Triangle_Vertex_Index.push_back(Vector2D(0, 2, 1));
	Triangle_Vertex_Index.push_back(Vector2D(1, 2, 1));
	Triangle.Set_Vertex_Index(Triangle_Vertex_Index);

	// 初始化这个三角形模型在世界坐标系中的位置,也就是这个模型下的模型坐标系中的原点在世界坐标系中的坐标和这个模型的旋转角度
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

void Update() // 更新场景，用于这个的模型坐标变换和将这个模型的下的坐标系的顶点坐标转化到世界坐标,然后绘制这个模型的时候是通过这个模型下的顶点的世界坐标来将这个模型给绘制出来的
{
	/*---------------------更新这些变换矩阵---------------------*/
	Scaling.SetS(sx, sy);
	Translation.SetT(tx, ty);
	Rotation.SetR(r);

	/*---------------------通过这些矩阵来给这个三角形模型做变换---------------------*/
	// 通过获取到这个模型在世界坐标系中x坐标和y坐标，并用获取到的坐标来创建一个临时的向量
	Vector2D v(Triangle.GetModelX(), Triangle.GetModelY(), 1);

	// 给这个通过模型坐标来创建向量的进行矩阵的变换，来实现这个三角形模型绕世界坐标系中的旋转和这个三角形模型的平移和三角形模型的缩放
	v = (Translation * Rotation) * v;

	// 然后再通过这个缩放矩阵来实现这个模型的缩放
	// 首先先获取这个模型的顶点坐标
	vector<Vector2D> Model_Vertex = Triangle.Get_Vertex();

	//然后就通过获取到的模型的顶点坐标来进行缩放的变换
	for (int i = 0; i < Model_Vertex.size(); i++)
	{
		Model_Vertex[i] = Scaling * Model_Vertex[i];
	}
	Triangle.Set_Vertex(Model_Vertex);

	// 更新这个模型的x坐标和y坐标和这个模型的旋转角度
	Triangle.SetModelX(v[0]);
	Triangle.SetModelY(v[1]);
	Triangle.SetModelR(R);

	Triangle_Vertex_World = Matrix2D::Model_To_World(Triangle); // 用于将这个三角形模型下的顶点坐标转化到世界坐标

	// 初始化这些变量，因为是通过这些变量来创建的矩阵，如果不初始化就会导致叠加上一次变换
	r = 0;
	sx = 1;
	sy = 1;
	tx = 0;
	ty = 0;
}

void Draw() // 绘制场景
{
	setlinecolor(WHITE); // 设置线条颜色

	/*------------------------------------------绘制这个三角形模型------------------------------------------*/
	vector<Vector2D> v = Triangle.Get_Vectex_Index(); // 获取这个这个三角形模型顶点索引，通过这个三角形模型的顶点索引来将这个模型给绘制出来
	for (int i = 0; i < v.size(); i++)
	{
		// 那是如何通过这些三角形模型的顶点索引来将这个模型给绘制出来的？因为每一个的三角形模型的顶点的索引就是一条线，并且通过当前索引的第一个索引就是这条线的起始索引，然后第二个索引就是这条线的结束索引，然后就是通过这个索引去访问这个模型的顶点的世界坐标来将这个模型给绘制出来
		int index1 = v[i][0]; // 获取当前索引的第一个元素也就是这条线的起始索引
		int index2 = v[i][1]; // 获取当前索引的第二个元素也就是这条线的结束索引
		line(Triangle_Vertex_World[index1][0], Triangle_Vertex_World[index1][1], Triangle_Vertex_World[index2][0], Triangle_Vertex_World[index2][1]); // 通过这条线的起始索引和结束索引，来去访问这个三角形模型顶点的世界坐标，来将这个模型给绘制出来
	}
}