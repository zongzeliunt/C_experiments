#include <iostream>
using namespace std;

class test_base {
	private:
		//��ΪheriҪ�̳�base����Ҫ����base�ж����int ��float�����ݣ�����Ҫ��protected��������
		//������ʵҲ��û��Ҫ�ģ�����base��������ݿ���ͨ���������ò���ֱ�ӷ��ʣ�����ֱ�ӷ��ʸ�����㡣
		int int_data = 0;
   		float float_data = 0;
	public:
		//���캯��������
		test_base(int data);
		test_base(float data);
		
		//�������͵��޸ĺ��������
		void change_int_data(int data);
		int get_int_data();
		void change_float_data(float data);
		float get_float_data();

		//��������
		//�����������ֻ�Ǹ����ӣ��Ժ����ã���Ϊ�̳���Ҳ����ֱ�ӵ��û�������ݡ�
		int add_data(int data);
		float add_data(float data);
		
		//�麯��
		virtual void class_classify ()
		{
			cout<<"this is base class"<<endl;
		}
};


class test_heri:public test_base {
	private:
		double double_data = 0;

	public:
		//���캯������
		test_heri(int data);
		test_heri(float data);
		test_heri(double data);
		//�����޸ĺ��������
		void change_double_data(double data);
		double get_double_data();
		//���������
		test_heri operator+(test_heri data);
		int operator+(int data);
		//����ģ���Ա

		//���¶����麯��
		void class_classify ()
		{
			cout<<"this is heri class"<<endl;
		}

};

