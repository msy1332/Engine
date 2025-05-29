#include "../Tools/_Vector.h"
#include <stdexcept>
#include <iostream>
#include <cmath>
using namespace _Vector::Vector_2D;
#pragma once // ��ֹͷ�ļ��ظ����������µ��ض�������

namespace _Matrix // ������һ�������ռ䣬������֯���룬����������ͻ
{
	namespace Matrix_2D // ������һ��2D���������ռ䣬������֯���룬����������ͻ
	{
		class Matrix2D
		{
			protected:
			private:
				Vector2D _Matrix2D[3]; // 2D����
			public:
				Matrix2D(); // Ĭ�Ϲ��캯�������ڳ�ʼ��2D����
				Matrix2D(Vector2D v1, Vector2D v2, Vector2D v3);// �вι��캯�������ڳ�ʼ��2D����

				Vector2D& operator[](int index); // �������±�������������û��Ϳ���ͨ���±�������2D���������ֵ
				const Vector2D& operator[](int index) const; // �������±�������������û��Ϳ���ͨ���±�������2D���������ֵ
				Matrix2D operator*(const Matrix2D& v) const; // �����˳˷������������ʵ�־���ĳ˷�
				Vector2D operator*(const Vector2D& v) const; // �����˳˷������������ʵ�־����������ĳ˷�
				Matrix2D operator+(const Matrix2D& v) const; // �����˼ӷ������������ʵ�־���ļӷ�
				Matrix2D operator-(const Matrix2D& v) const; // �����˼��������������ʵ�־���ļ���
				void operator=(const Matrix2D& v); // �����˸�ֵ�����������ʵ�־���Ŀ������߽и�ֵ
			};
			class Matrix2D_Scaling : public Matrix2D
			{
				protected:
				private:
				public:
					Matrix2D_Scaling(); // Ĭ�ϵĹ��캯�������ڳ�ʼ��������ž���
					Matrix2D_Scaling(int Sx, int Sy); // �вεĹ��캯�������ڳ�ʼ��������ž���
			};

			class Matrix2D_Translation : public Matrix2D
			{
				protected:
				private:
				public:
					Matrix2D_Translation(); // Ĭ�ϵĹ��캯�������ڳ�ʼ��������ž���
					Matrix2D_Translation(int Tx, int Ty); // �вεĹ��캯�������ڳ�ʼ��������ž���
			};
			class Matrix2D_Rotation : public Matrix2D
			{
				protected:
				private:
				public:
					Matrix2D_Rotation(); // Ĭ�ϵĹ��캯�������ڳ�ʼ��������ž���
					Matrix2D_Rotation(int R); // �вεĹ��캯�������ڳ�ʼ��������ž���
		};
	}
	namespace Matrix_3D // ������һ��3D���������ռ䣬������֯���룬����������ͻ
	{

	}
}