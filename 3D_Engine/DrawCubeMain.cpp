#include "../Tools/_Matrix.h"
#include "../Tools/_Vector.h"
#include <iostream>		// ������׼���������ͷ�ļ�
#include <windows.h>	// ����ϵͳͷ�ļ�
#include <easyx.h>		// ����Easyxͼ�ο�
using namespace _Matrix::Matrix_2D;    // ����Matrix_2D�����ռ�,Ҳ���ǰ�������������ռ�
using namespace _Vector::Vector_2D;    // ����Vector_2D�����ռ�,Ҳ���ǰ��������������ռ�
using namespace std;    // ����std�����ռ�

double r = 0;
double sx = 1;
double sy = 1;
double tx = 0;
double ty = 0;
ExMessage msg; // ������Ϣ�ṹ��
bool Running = true; // ���������״̬

Matrix2D M; // �任��ĵľ���
Matrix2D_Scaling S; // ʵ����һ��2D���ž������
Matrix2D_Rotation R; // ʵ����һ��2D��ת�������
Matrix2D_Translation T; // ʵ����һ��2Dƽ�ƾ������
Vector2D Square[4]; // ʵ����һ��2D������������飬�����洢�����ε��ĸ��������

void Update(); // ��������
void Draw_Square(); // ����������
void Init_Square(); // ��ʼ������

int main() // ������������Ҳ���ǳ������ں���
{
	initgraph(1920, 1080, EX_SHOWCONSOLE); // ����ͼ�δ���
	setbkcolor(BLACK); // ���ñ�����ɫ
	cleardevice(); // �����ͼ�����������ñ�����ɫ�����������

	Init_Square(); // ��ʼ������
	BeginBatchDraw(); // ����˫�����ͼ
	while (Running)
	{
		while (peekmessage(&msg, EX_KEY))
		{
			switch (msg.message) // �ж���Ϣ����
			{
				case WM_KEYDOWN: // �ж��Ƿ��Ǽ��̰�����Ϣ
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
		cleardevice(); // ����
		Update();
		Draw_Square(); // ����������
		//Sleep(10000);
		FlushBatchDraw(); // ˢ�»�ͼ������
	}
	EndBatchDraw(); // // �ر�˫�����ͼ
	return 0; //����ķ���ֵ���������0������������˳������������Ƿ������˳�
}

void Init_Square()
{
	// ��ʼ��������
	Square[0] = { 100,100,1 };
	Square[1] = { 200,100,1 };
	Square[2] = { 100,200,1 };
	Square[3] = { 200,200,1 };

	// ��ʼ�����ž���
	S.SetS(1, 1);

	// ��ʼ��ƽ�ƾ���
	T.SetT(0, 0);

	// ��ʼ����ת����
	R.SetR(0);
}

void Draw_Square()
{
	// ����������ɫ
	setlinecolor(WHITE);

	// ����������ʽ
	setlinestyle(PS_SOLID, 5);

	// ���������ε��ϱ߿���±߿�
	line(Square[0][0], Square[0][1], Square[1][0], Square[1][1]);
	line(Square[2][0], Square[2][1], Square[3][0], Square[3][1]);

	// ���������ε���߿���ұ߿�
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

/*------------------------------ע��------------------------------*/
/*
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
	Matrix2D_Translation v6(2,2); // ������һ��2Dƽ�ƾ������
	Matrix2D_Scaling v7(2,2); // ������һ��2D���ž������
	Matrix2D v8 = v6 * v7;
	Matrix2D v5 = v2 * v3; // ����;�����ˣ����������µ�2D�������
	Vector2D v4 = v5 * v1; // ������������ˣ����������µ�2D��������
	for (int i = 0; i < 3; i++)
	{
		cout << v4[i] << endl;
	}
*/