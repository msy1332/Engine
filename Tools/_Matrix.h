#include "../Tools/_Vector.h"
#include "../Tools/_Model.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <cmath>
using namespace _Vector::Vector_2D;
using namespace _Vector::Vector_3D;
using namespace _Model::Model2D;
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
				Matrix2D(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3);// �вι��캯�������ڳ�ʼ��2D����

				void Set_Matrix2D(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3); // ���þ���
				void Clear_Matrix(); // �������Ҳ������վ���

				Vector2D& operator[](int index); // �������±�������������û��Ϳ���ͨ���±�������2D���������ֵ
				const Vector2D& operator[](int index) const; // �������±�������������û��Ϳ���ͨ���±�������2D���������ֵ

				static std::vector<Vector2D> Model_To_World(const Model2D& model); // ������һ����̬��Ա�����ڽ�ģ������ת����������

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
					Matrix2D_Scaling(double Sx, double Sy); // �вεĹ��캯�������ڳ�ʼ��������ž���

					void SetS(double Sx,double Sy); // �������Ŵ�С
			};

			class Matrix2D_Translation : public Matrix2D
			{
				protected:
				private:
				public:
					Matrix2D_Translation(); // Ĭ�ϵĹ��캯�������ڳ�ʼ��������ž���
					Matrix2D_Translation(double Tx, double Ty); // �вεĹ��캯�������ڳ�ʼ��������ž���

					void SetT(double Tx, double Ty); // ����ƽ�ƾ���
			};
			class Matrix2D_Rotation : public Matrix2D
			{
				protected:
				private:
				public:
					Matrix2D_Rotation(); // Ĭ�ϵĹ��캯�������ڳ�ʼ��������ž���
					Matrix2D_Rotation(double R); // �вεĹ��캯�������ڳ�ʼ��������ž���

					void SetR(double R); // ������ת�Ƕ�
		};
	}
	namespace Matrix_3D // ������һ��3D���������ռ䣬������֯���룬����������ͻ
	{
		class Matrix3D
		{
			protected:
			private:
				Vector3D _Matrix3D[4]; // 3D����
			public:
				//Matrix3D(); // Ĭ�Ϲ��캯�������ڳ�ʼ�����3D����
				//Matrix3D(const Matrix3D& v); // �������캯��������ʹ�������ĵ�3D��������ʼ��
				//Matrix3D(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3); // �вι��캯����Ҳ�����ڳ�ʼ�����3D����

				//void Set_Matrix3D(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3); // ����3D����
				//void Clear_Matrix(); // ���3D����

				//Vector3D& operator[](int index); // �������±�������������Ϳ���������ͨ���±���ȡ���ʺ��޸�3D����
				//const Vector3D& operator[](int index) const; // �������±�������������Ϳ���������ͨ���±���ȡ���ʺ��޸�3D����

				//Matrix3D operator*(const Matrix3D& v) const; // �����˳˷������������ʵ�־���;���ĳ˷�
				//Vector3D operator*(const Vector3D& v) const; // �����˳˷������������ʵ�־���������ĳ˷�
				//Matrix3D operator+(const Matrix3D& v) const; // �����˼ӷ������������ʵ�־���ļӷ�
				//Matrix3D operator-(const Matrix3D& v) const; // �����˼��������������ʵ�־���ļ���
				//void operator=(const Matrix3D& v) const; // // �����˸�ֵ�����������ʵ�־���Ŀ���
		};
	}
}