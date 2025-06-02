#include "../Tools/_Vector.h"
#include <iostream>
#include <vector>
using namespace _Vector::Vector_2D;
#pragma once // ��ֹͷ�ļ��ظ����������µ��ض�������

namespace _Model // ������һ��ģ�͵������ռ䣬������֯���룬����������ͻ
{
	namespace Model2D // ������һ��2Dģ�͵������ռ䣬������֯���룬��������������ͻ
	{
		class Model2D // ������һ��2Dģ����
		{
			protected:
			private:
				double X; // 2Dģ������������ϵ�е�x����
				double Y; // 2Dģ������������ϵ�е�y����
				double R; // 2Dģ�͵�����������ϵ�е���ת�ĽǶȣ���Ϊ���ģ����Ҳ�ǿ�����ת�ģ��������ǻ�Ҫָ��ģ�͵���ת�ĽǶ�

				std::vector<Vector2D> Vertex; // 2Dģ�͵Ķ�������
				std::vector<Vector2D> Vectex_Index; // 2Dģ�͵Ķ�������
			public:
				Model2D(); // Ĭ�Ϲ��캯�������ڳ�ʼ�����2Dģ��
				Model2D(const Model2D& model); // ������һ���������캯���������������Ķ������˵��������2Dģ�����������2Dģ�͵ĳ�ʼ��
				Model2D(const std::vector<Vector2D>& Vectex, const std::vector<Vector2D>& Vectex_Index, double X = 0, double Y =  0, double R = 0); // �вι��캯�������ڳ�ʼ�����2Dģ��

				double GetModelX() const; // ��ȡ���ģ������������ϵ�µ�x����
				double GetModelY() const; // ��ȡ���ģ������������ϵ�µ�y����
				double GetModelR() const; // ��ȡ���ģ����ת�Ƕ�
				const std::vector<Vector2D>& Get_Vertex(); // ��ȡ���2Dģ�͵Ķ�������
				const std::vector<Vector2D>& Get_Vectex_Index(); // ��ȡ2Dģ�͵Ķ�������

				void SetModelX(double X); // �������ģ������������ϵ�е�x����
				void SetModelY(double Y); // �������ģ������������ϵ�µ�y����
				void SetModelR(double R); // �������ģ�͵���ת�Ƕ�
				void Set_Vertex(const std::vector<Vector2D>& Vectex); // �����������2Dģ�͵Ķ�������
				void Set_Vertex_Index(const std::vector<Vector2D>& Vectex_Index); // �����������2Dģ�͵Ķ�������
				void Set_Model2D(const std::vector<Vector2D>& Vectex, const std::vector<Vector2D>& Vectex_Index); // �����������2Dģ��
				void operator=(const Model2D& model); // �����˸�ֵ�����������2Dģ�͵Ŀ���
		};
	}
}