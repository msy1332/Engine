#include "../Tools/_Vector.h"
#pragma once // ��ֹͷ�ļ��ظ����������µ��ض�������

namespace _Matrix // ������һ�������ռ䣬������֯���룬����������ͻ
{
	class Matrix2D
	{
		protected:
		private:
			_Vector::Vector2D _Matrix2D[3]; // 2D����
		public:
			Matrix2D(); // Ĭ�Ϲ��캯�������ڳ�ʼ��2D����
			Matrix2D(_Vector::Vector3D v1, _Vector::Vector3D v2, _Vector::Vector3D v3);// �вι��캯�������ڳ�ʼ��2D����

			_Vector::Vector2D& operator[](int index); // �������±�������������û��Ϳ���ͨ���±�������2D���������ֵ
	};
}