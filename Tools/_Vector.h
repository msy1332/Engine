#pragma once // ��ֹͷ�ļ��ظ����������µ��ض�������

namespace _Vector // ������һ�������ռ䣬������֯���룬����������ͻ
{
	class Vector2D // ����һ����ά������
	{
		protected:
		private:
			double x; //x��������
			double y; //y��������
			double w; //w��������
		public:
			Vector2D();// Ĭ�Ϲ��캯�������ڳ�ʼ������
			Vector2D(const Vector2D& v); //�������캯��������������������������ʼ��
			Vector2D(double x, double y, double w); // �вι��캯�������ڳ�ʼ������

			double GetX(); // ��ȡx����
			double GetY(); // ��ȡy����
			double GetW(); // ��ȡw����

			void SetX(double x); // ����x����
			void SetY(double y); // ����y����
			void SetW(double w); // ����w����

			virtual const double& operator[](int index) const; // �������±��������ʹ�ö������ͨ��������һ�����±������������ķ���
			virtual double& operator[](int index); // �������±��������ʹ�ö������ͨ��������һ�����±������������ķ���
			Vector2D operator*(const Vector2D& v) const; // ���س˷�����������ڼ��������ĵ��
			Vector2D operator+(const Vector2D& v) const; // ���ؼӷ�����������ڼ��������ļӷ�
			Vector2D operator-(const Vector2D& v) const; // ���ؼ�������������ڼ��������ļ���
			void operator=(const Vector2D& v); // ���ظ�ֵ�������������������
	};
	class Vector3D : public Vector2D // ����һ����ά������
	{
		protected:
		private:
			double x; // x��������
			double y; // y��������
			double z; // z��������
			double w; // w��������
		public:
			Vector3D(); // Ĭ�ϵĹ��캯�������ڳ�ʼ������
			Vector3D(const Vector3D& v); // �������캯�����������������г�ʼ��
			Vector3D(double x, double y, double z, double w); // �вι��캯�������ڳ�ʼ������

			//double GetX() const; // ��ȡx����������
			//double GetY() const; // ��ȡy����������
			double GetZ() const; // ��ȡz����������
			//double GetW() const; // ��ȡw����������

			//void SetX(double x); // ����x����������
			//void SetY(double y); // ����y����������
			void SetZ(double z); // ����z����������
			//void SetW(double w);// ����w����������
			
			const double& operator[](int index) const override;// �������±��������ʹ�ö������ͨ��������һ�����±������������ķ���
			double& operator[](int index) override;// �������±��������ʹ�ö������ͨ��������һ�����±������������ķ���
			Vector3D operator*(const Vector3D& v) const; // ���س˷�����������ڼ����������
			Vector3D operator+(const Vector3D& v) const; // ���ؼӷ�����������ڼ��������ӷ�
			Vector3D operator-(const Vector3D& v) const; // ���ؼ�������������ڼ�����������
			void operator=(const Vector3D& v); // ���ظ�ֵ����������������Ŀ���
	};
}