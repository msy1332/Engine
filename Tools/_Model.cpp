#include "../Tools/_Model.h"
using namespace _Model::Model2D;

Model2D::Model2D()
{
	X = 0;
	Y = 0;
	R = 0;
}

Model2D::Model2D(const Model2D& model)
{
	X = model.X;
	Y = model.Y;
	R = model.R;
	Vertex = model.Vertex;
	Vectex_Index = model.Vectex_Index;
}

Model2D::Model2D(const std::vector<Vector2D>& Vectex, const std::vector<Vector2D>& Vectex_Index, double X, double Y, double R)
{
	this->Vertex = Vectex; // 初始化模型的顶点坐标
	this->Vectex_Index = Vectex_Index; // 初始化模型顶点索引
}

double Model2D::GetModelX() const
{
	return X;
}

double Model2D::GetModelY() const
{
	return Y;
}

double Model2D::GetModelR() const
{
	return R;
}

const std::vector<Vector2D>& Model2D::Get_Vertex()
{
	return Vertex;
}

const std::vector<Vector2D>& Model2D::Get_Vectex_Index()
{
	return Vectex_Index;
}


void Model2D::SetModelX(double X)
{
	this->X = X;
}

void Model2D::SetModelY(double Y)
{
	this->Y = Y;
}

void Model2D::SetModelR(double R)
{
	this->R = R;
}

void Model2D::Set_Vertex(const std::vector<Vector2D>& Vertex)
{
	this->Vertex.resize(Vertex.size());
	this->Vertex = Vertex;
}

void Model2D::Set_Vertex_Index(const std::vector<Vector2D>& Vertex_Index)
{
	this->Vectex_Index.resize(Vertex_Index.size());
	this->Vectex_Index = Vertex_Index;
}

void Model2D::Set_Model2D(const std::vector<Vector2D>& Vectex, const std::vector<Vector2D>& Vectex_Index)
{
	this->Vertex = Vectex; // 重新设置模型的顶点坐标
	this->Vectex_Index = Vectex_Index; // 重新设置模型顶点索引
}

void Model2D::operator=(const Model2D& model)
{
	Vertex = model.Vertex;
	Vectex_Index = model.Vectex_Index;
}