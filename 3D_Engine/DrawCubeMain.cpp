#include "../Tools/_Matrix.h"
#include "../Tools/_Vector.h"
#include "../Tools/_Model.h"
#include <iostream>		// ������׼���������ͷ�ļ�
#include <windows.h>	// ����ϵͳͷ�ļ�
#include <easyx.h>		// ����Easyxͼ�ο�
#include <vector>
using namespace _Matrix::Matrix_2D;    // ����Matrix_2D�����ռ�,Ҳ���ǰ�������������ռ�
using namespace _Vector::Vector_2D;    // ����Vector_2D�����ռ�,Ҳ���ǰ��������������ռ�
using namespace _Model::Model2D;	   // ����Model�����ռ䣬Ҳ���ǰ������2Dģ�͵������ռ�
using namespace std;    // ����std�����ռ�

ExMessage msg; // ������һ����Ϣ�ṹ��
bool Running = true; // ���������״̬

double r;  // ģ�͵�����������ϵ��ת�Ƕ�
double sx; // ���ģ�͵���x���Ŷ��ٱ�
double sy; // ���ģ�͵���y���Ŷ��ٱ�
double tx; // ���ģ�͵���x�ƶ����ٸ�����
double ty; // ���ģ�͵���y�ƶ����ٸ�����

double X; // ģ������������ϵ�е�x���꣬Ҳ�������ģ���µ�ģ������ϵ�е�ԭ������������ϵ�е�λ��
double Y; // ģ������������ϵ�е�y���꣬Ҳ�������ģ���µ�ģ������ϵ�е�ԭ������������ϵ�е�λ��
double R; // ģ�͵���ת�Ƕ�
Model2D Triangle; // ������һ��������ģ��

Matrix2D_Scaling Scaling; // ������һ�����ž������������������ģ�����任
Matrix2D_Rotation Rotation; // ������һ����ת����Ҳ�����������������ģ�����任��
Matrix2D_Translation Translation; // ������һ��ƽ�ƾ���Ҳ�����������������ģ�����任��

vector<Vector2D> Triangle_Vertex_World; // ������һ�������������洢���������ģ�͵Ķ�������ת���������µ����꣬��ʱ����������������ģ���µĶ���������������������������ģ�͵�

void Draw(); // ���Ƴ���
void Init(); // ��ʼ������
void Update(); // ���³���

int main() // �����������ǳ�������
{
	initgraph(800, 600, EX_SHOWCONSOLE); // ��ʼ�����ͼ�δ���
	setbkcolor(BLACK); // ����ͼ�δ��ڵı�����ɫ
	cleardevice(); // �����ͼ�����������ñ�����ɫ�����������

	Init(); // ��ʼ������
	BeginBatchDraw(); // ����˫�����ͼ
	while (Running)
	{
		while (peekmessage(&msg, EX_KEY))
		{
			switch (msg.message) // �ж���Ϣ����
			{
				case WM_KEYDOWN:
					switch (msg.vkcode) // ��ȡ�û����µ�ʲô��
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
		cleardevice(); // �����ͼ������
		Update(); // ���³���
		Draw(); // ���Ƴ���
		FlushBatchDraw(); // ˢ�»�ͼ������
	}
	EndBatchDraw(); // �ر�˫�����ͼ
	return 0; // ����ķ���ֵ���������0��������������˳�
}

void Init()
{
	/*-----------------��ʼ�����������������ģ��-----------------*/
	// ��ʼ�����������ģ�͵Ķ���
	vector<Vector2D> Triangle_Vertex;
	Triangle_Vertex.push_back(Vector2D(0, 50, 1));
	Triangle_Vertex.push_back(Vector2D(0, 0, 1));
	Triangle_Vertex.push_back(Vector2D(50, 0, 1));
	Triangle.Set_Vertex(Triangle_Vertex);

	// ��ʼ�����������ģ�͵Ķ�������
	vector<Vector2D> Triangle_Vertex_Index;
	Triangle_Vertex_Index.push_back(Vector2D(0, 1, 1));
	Triangle_Vertex_Index.push_back(Vector2D(0, 2, 1));
	Triangle_Vertex_Index.push_back(Vector2D(1, 2, 1));
	Triangle.Set_Vertex_Index(Triangle_Vertex_Index);

	// �������������ģ������������ϵ�е���������������ģ�͵���ת�Ƕ�
	X = 100;
	Y = 100;
	R = 0;
	Triangle.SetModelX(X);
	Triangle.SetModelY(Y);
	Triangle.SetModelR(R);

	// ��ʼ��������ž���
	sx = 1;
	sy = 1;
	Scaling.SetS(sx, sy);

	// ��ʼ�����ƽ�ƾ���
	tx = 0;
	ty = 0;
	Translation.SetT(tx, ty);

	// ��ʼ�������ת����
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
	setlinecolor(WHITE); // ����������ɫ

	/*-----------------�������������������ģ��-----------------*/
	// ��ȡ���������ģ�͵Ķ�������������ģ�͵Ķ�������
	// vector<Vector2D> Triangle_Vertex = Triangle.Get_Vertex();
	vector<Vector2D> Triangle_Vertex_Index = Triangle.Get_Vectex_Index();

	// Ȼ���ٸ������������ģ�͵Ķ�����������������θ��ػ��Ƴ���������ô�����أ�����ʵ�ܼ򵥣����ȣ��Ȼ�ȡ��ǰ�����ĵ�0�����͵�1������Ϊÿһ������������һ���ߣ�Ҳ����˵���Ȼ�ȡ�����ߵ���ʼ���꣬�������ߵĽ������꣬Ȼ����ͨ���������ȥ���ʶ���������ĵ�x�����y���꣬Ȼ��Ϳ��Խ������߸����Ƴ�����ѭ�������Ķ����������Ϳ��԰����2D��ģ�͸����Ƴ���
	for (int i = 0; i < Triangle_Vertex_Index.size(); i++)
	{
		int index = Triangle_Vertex_Index[i][0];
		int index1 = Triangle_Vertex_Index[i][1];
		line(Triangle_Vertex_World[index][0], Triangle_Vertex_World[index][1], Triangle_Vertex_World[index1][0], Triangle_Vertex_World[index1][1]);
	}
}