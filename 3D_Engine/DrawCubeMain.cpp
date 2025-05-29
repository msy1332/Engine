#include "../Tools/_Matrix.h"
#include "../Tools/_Vector.h"
#include <iostream>		// ������׼���������ͷ�ļ�
#include <easyx.h>		// ����Easyxͼ�ο�
using namespace std;    // ����std�����ռ�
using namespace _Matrix;    // ����_Matrix�����ռ�,Ҳ���ǰ�������������ռ�
using namespace _Vector;    // ����_Vector�����ռ�,Ҳ���ǰ��������������ռ�

int main() // ������������Ҳ���ǳ������ں���
{
	Vector2D v1(2, 3, 1); // ������һ����ά����������
	Matrix2D v2(
		Vector2D(1, 0, 2),
		Vector2D(0, 1, 2),
		Vector2D(0, 0, 1)
	); // ������һ��2D�������
	Matrix2D v3(
		Vector2D(2, 0, 0),
		Vector2D(0, 2, 0),
		Vector2D(0, 0, 1)
	); // ������һ��2D�������
	Matrix2D v5 = v2 * v3; // ����;�����ˣ����������µ�2D�������
	Vector2D v4 = v5 * v1; // ������������ˣ����������µ�2D��������
	for (int i = 0; i < 3; i++)
	{
		cout << v4[i] << endl;
	}
	return 0; //����ķ���ֵ���������0������������˳������������Ƿ������˳�
}