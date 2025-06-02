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

bool Running = true; // �������Ϸ״̬
ExMessage msg; // ������һ����Ϣ�ṹ�壬������ȡ��Ϣ

// ��������������ģ������������ϵ�е�λ�ú����ģ�͵���ת�Ƕ�
double X;
double Y;
double R;

// ����һЩ�������������������ģ�ͽ��о���ı任�ģ�Ҳ����˵��Щ���������������������ģ�ͽ�����ת��ƽ�ƣ����ű任��
Matrix2D_Scaling Scaling;		// ������һ�����ž���
Matrix2D_Rotation Rotation;	// ������һ����ת����
Matrix2D_Translation Translation; // ������һ��ƽ�ƾ���

// ������һЩ����,Ȼ��ͻ�ͨ����Щ������������ת��ƽ�ƣ����ž���ģ��������������ģ�ͽ��о���任��
double r;	// ���������ģ��������������ϵ��ת�ĽǶ�
double sx;	// ���������ģ����x�������Ŷ��ٱ�
double sy;	// ���������ģ����y�������Ŷ��ٱ�
double tx;	// ���������ģ����x����ƽ�ƶ��پ���
double ty;	// ���������ģ����y����ƽ�ƶ��پ���

vector<Vector2D> Triangle_Vertex_World; // ��������������ģ���µĶ������������
Model2D Triangle; // ������һ��2D��ģ����

void Init();	// ��ʼ������������˵��ʼ������������е�������ģ��
void Draw();	// ���Ƴ���������˵����������л���һ��������ģ�ͣ�����λ����أ�������ͨ�����ģ�͵Ķ��������������ģ�͸����Ƴ�����
void Update();	// ���³��������ڸ�����Щ�ڳ����е�ģ�͵�λ��

int main() // ��������Ҳ���ǳ�������
{
	/*---------------------��ʼ������---------------------*/
	initgraph(800, 600, EX_SHOWCONSOLE); // ��������
	setbkcolor(BLACK); // ���ô��ڵı�����ɫ
	cleardevice(); // ������ڻ�ͼ�����������ñ�����ɫ�������������

	Init(); // ��ʼ������
	BeginBatchDraw(); // ����˫�����ͼ

	while (Running)
	{
		while (peekmessage(&msg, EX_KEY)) // ��ȡ��Ϣ�����ѻ�ȡ������Ϣ�洢����Ϣ�ṹ����
		{
			switch (msg.message) // �жϻ�ȡ������Ϣ������
			{
				case WM_KEYDOWN: // ���̰�����Ϣ
					switch (msg.vkcode) // ͨ��vkcode��Ա����ȡ�û�������ʲô��
					{
						// ͨ�������ϵ�WSAD���������ģ�͵��ƶ�
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

						// Ȼ����ͨ�������ϵ�RL���������ģ��������������ϵ�µ���ת
						case 'L':
							r += 0.1;
							break;
						case 'R':
							r -= 0.1;
							break;

						// Ȼ����ͨ����������ϵ����Ҽ������������ģ�͵���ת
						case VK_LEFT:
							R += 0.1;
							break;
						case VK_RIGHT:
							R -= 0.1;
							break;

						// Ȼ����ͨ�������ϵ��ϼ����¼����������ģ�͵�����
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
		cleardevice(); // ������ڻ�ͼ�����������ñ�����ɫ�������������
		Update(); // ���³���
		Draw(); // ���Ƴ���
		FlushBatchDraw(); // ˢ�»�ͼ������
	}

	EndBatchDraw(); // �ر�˫�����ͼ
	return 0; // ����ķ���ֵ���������0��������������˳���������ǳ����쳣�˳�
}

void Init() // ��ʼ������
{
	/*-------------------��ʼ��������ģ��-------------------*/
	// ��ʼ�����������ģ�͵Ķ�������
	vector<Vector2D> Triangle_Vertex;
	Triangle_Vertex.push_back(Vector2D(0, 50, 1));
	Triangle_Vertex.push_back(Vector2D(0, 0, 1));
	Triangle_Vertex.push_back(Vector2D(50, 0, 1));
	Triangle.Set_Vertex(Triangle_Vertex);

	// ��ʼ�����������ģ�͵Ķ����������Ƕ���������ʲô���أ��������ǿ���ͨ�����ģ�͵Ķ����������������ģ�͵���״����ξ������ǿ���ͨ�����ģ�͵Ķ��������������ģ�͸����Ƴ���
	vector<Vector2D> Triangle_Vertex_Index;
	Triangle_Vertex_Index.push_back(Vector2D(0, 1, 1));
	Triangle_Vertex_Index.push_back(Vector2D(0, 2, 1));
	Triangle_Vertex_Index.push_back(Vector2D(1, 2, 1));
	Triangle.Set_Vertex_Index(Triangle_Vertex_Index);

	// ��ʼ�����������ģ������������ϵ�е�λ��,Ҳ�������ģ���µ�ģ������ϵ�е�ԭ������������ϵ�е���������ģ�͵���ת�Ƕ�
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

void Update() // ���³��������������ģ������任�ͽ����ģ�͵��µ�����ϵ�Ķ�������ת������������,Ȼ��������ģ�͵�ʱ����ͨ�����ģ���µĶ�������������������ģ�͸����Ƴ�����
{
	/*---------------------������Щ�任����---------------------*/
	Scaling.SetS(sx, sy);
	Translation.SetT(tx, ty);
	Rotation.SetR(r);

	/*---------------------ͨ����Щ�����������������ģ�����任---------------------*/
	// ͨ����ȡ�����ģ������������ϵ��x�����y���꣬���û�ȡ��������������һ����ʱ������
	Vector2D v(Triangle.GetModelX(), Triangle.GetModelY(), 1);

	// �����ͨ��ģ�����������������Ľ��о���ı任����ʵ�����������ģ������������ϵ�е���ת�����������ģ�͵�ƽ�ƺ�������ģ�͵�����
	v = (Translation * Rotation) * v;

	// Ȼ����ͨ��������ž�����ʵ�����ģ�͵�����
	// �����Ȼ�ȡ���ģ�͵Ķ�������
	vector<Vector2D> Model_Vertex = Triangle.Get_Vertex();

	//Ȼ���ͨ����ȡ����ģ�͵Ķ����������������ŵı任
	for (int i = 0; i < Model_Vertex.size(); i++)
	{
		Model_Vertex[i] = Scaling * Model_Vertex[i];
	}
	Triangle.Set_Vertex(Model_Vertex);

	// �������ģ�͵�x�����y��������ģ�͵���ת�Ƕ�
	Triangle.SetModelX(v[0]);
	Triangle.SetModelY(v[1]);
	Triangle.SetModelR(R);

	Triangle_Vertex_World = Matrix2D::Model_To_World(Triangle); // ���ڽ����������ģ���µĶ�������ת������������

	// ��ʼ����Щ��������Ϊ��ͨ����Щ�����������ľ����������ʼ���ͻᵼ�µ�����һ�α任
	r = 0;
	sx = 1;
	sy = 1;
	tx = 0;
	ty = 0;
}

void Draw() // ���Ƴ���
{
	setlinecolor(WHITE); // ����������ɫ

	/*------------------------------------------�������������ģ��------------------------------------------*/
	vector<Vector2D> v = Triangle.Get_Vectex_Index(); // ��ȡ������������ģ�Ͷ���������ͨ�����������ģ�͵Ķ��������������ģ�͸����Ƴ���
	for (int i = 0; i < v.size(); i++)
	{
		// �������ͨ����Щ������ģ�͵Ķ��������������ģ�͸����Ƴ����ģ���Ϊÿһ����������ģ�͵Ķ������������һ���ߣ�����ͨ����ǰ�����ĵ�һ���������������ߵ���ʼ������Ȼ��ڶ����������������ߵĽ���������Ȼ�����ͨ���������ȥ�������ģ�͵Ķ�������������������ģ�͸����Ƴ���
		int index1 = v[i][0]; // ��ȡ��ǰ�����ĵ�һ��Ԫ��Ҳ���������ߵ���ʼ����
		int index2 = v[i][1]; // ��ȡ��ǰ�����ĵڶ���Ԫ��Ҳ���������ߵĽ�������
		line(Triangle_Vertex_World[index1][0], Triangle_Vertex_World[index1][1], Triangle_Vertex_World[index2][0], Triangle_Vertex_World[index2][1]); // ͨ�������ߵ���ʼ�����ͽ�����������ȥ�������������ģ�Ͷ�����������꣬�������ģ�͸����Ƴ���
	}
}