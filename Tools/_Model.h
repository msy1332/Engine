#include "../Tools/_Vector.h"
#include <iostream>
#include <vector>
using namespace _Vector::Vector_2D;
#pragma once // 防止头文件重复包含而导致的重定义问题

namespace _Model // 定义了一个模型的命名空间，用于组织代码，避免命名冲突
{
	namespace Model2D // 定义了一个2D模型的命名空间，用于组织代码，避免命名命名冲突
	{
		class Model2D // 定义了一个2D模型类
		{
			protected:
			private:
				double X; // 2D模型在世界坐标系中的x坐标
				double Y; // 2D模型在世界坐标系中的y坐标
				double R; // 2D模型的在世界坐标系中的旋转的角度，因为这个模型他也是可以旋转的，所以我们还要指定模型的旋转的角度

				std::vector<Vector2D> Vertex; // 2D模型的顶点坐标
				std::vector<Vector2D> Vectex_Index; // 2D模型的顶点索引
			public:
				Model2D(); // 默认构造函数，用于初始化这个2D模型
				Model2D(const Model2D& model); // 定义了一个拷贝构造函数，可以用其他的对象或者说用其他的2D模型来进行这个2D模型的初始化
				Model2D(const std::vector<Vector2D>& Vectex, const std::vector<Vector2D>& Vectex_Index, double X = 0, double Y =  0, double R = 0); // 有参构造函数，用于初始化这个2D模型

				double GetModelX() const; // 获取这个模型在世界坐标系下的x坐标
				double GetModelY() const; // 获取这个模型在世界坐标系下的y坐标
				double GetModelR() const; // 获取这个模型旋转角度
				const std::vector<Vector2D>& Get_Vertex(); // 获取这个2D模型的顶点坐标
				const std::vector<Vector2D>& Get_Vectex_Index(); // 获取2D模型的顶点索引

				void SetModelX(double X); // 设置这个模型在世界坐标系中的x坐标
				void SetModelY(double Y); // 设置这个模型在世界坐标系下的y坐标
				void SetModelR(double R); // 设置这个模型的旋转角度
				void Set_Vertex(const std::vector<Vector2D>& Vectex); // 重新设置这个2D模型的顶点坐标
				void Set_Vertex_Index(const std::vector<Vector2D>& Vectex_Index); // 重新设置这个2D模型的顶点索引
				void Set_Model2D(const std::vector<Vector2D>& Vectex, const std::vector<Vector2D>& Vectex_Index); // 重新设置这个2D模型
				void operator=(const Model2D& model); // 重载了赋值运算符，用于2D模型的拷贝
		};
	}
}