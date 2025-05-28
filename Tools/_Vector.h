#pragma once // 防止头文件重复包含而导致的重定义问题

namespace _Vector // 定义了一个命名空间，用于组织代码，避免命名冲突
{
	class Vector2D // 定义一个二维向量类
	{
		protected:
		private:
			double x; //x向量分量
			double y; //y向量分量
			double w; //w向量分量
		public:
			Vector2D();// 默认构造函数，用于初始化向量
			Vector2D(const Vector2D& v); //拷贝构造函数，用其他对象来进行向量初始化
			Vector2D(double x, double y, double w); // 有参构造函数，用于初始化向量

			double GetX(); // 获取x分量
			double GetY(); // 获取y分量
			double GetW(); // 获取w分量

			void SetX(double x); // 设置x分量
			void SetY(double y); // 设置y分量
			void SetW(double w); // 设置w分量

			virtual const double& operator[](int index) const; // 重载了下标运算符，使得对象可以通过像数组一样用下标来访问向量的分量
			virtual double& operator[](int index); // 重载了下标运算符，使得对象可以通过像数组一样用下标来访问向量的分量
			Vector2D operator*(const Vector2D& v) const; // 重载乘法运算符，用于计算向量的点乘
			Vector2D operator+(const Vector2D& v) const; // 重载加法运算符，用于计算向量的加法
			Vector2D operator-(const Vector2D& v) const; // 重载减法运算符，用于计算向量的减法
			void operator=(const Vector2D& v); // 重载复值运算符，用于向量拷贝
	};
	class Vector3D : public Vector2D // 定义一个三维向量类
	{
		protected:
		private:
			double x; // x向量分量
			double y; // y向量分量
			double z; // z向量分量
			double w; // w向量分量
		public:
			Vector3D(); // 默认的构造函数，用于初始化向量
			Vector3D(const Vector3D& v); // 拷贝构造函数，用其他向量进行初始化
			Vector3D(double x, double y, double z, double w); // 有参构造函数，用于初始化向量

			//double GetX() const; // 获取x的向量分量
			//double GetY() const; // 获取y的向量分量
			double GetZ() const; // 获取z的向量分量
			//double GetW() const; // 获取w的向量分量

			//void SetX(double x); // 设置x的向量分量
			//void SetY(double y); // 设置y的向量分量
			void SetZ(double z); // 设置z的向量分量
			//void SetW(double w);// 设置w的向量分量
			
			const double& operator[](int index) const override;// 重载了下标运算符，使得对象可以通过像数组一样用下标来访问向量的分量
			double& operator[](int index) override;// 重载了下标运算符，使得对象可以通过像数组一样用下标来访问向量的分量
			Vector3D operator*(const Vector3D& v) const; // 重载乘法运算符，用于计算向量点乘
			Vector3D operator+(const Vector3D& v) const; // 重载加法运算符，用于计算向量加法
			Vector3D operator-(const Vector3D& v) const; // 重载减法运算符，用于计算向量减法
			void operator=(const Vector3D& v); // 重载复值运算符，用于向量的拷贝
	};
}