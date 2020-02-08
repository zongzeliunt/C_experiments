#include <iostream>
using namespace std;

class test_base {
	private:
		//因为heri要继承base并且要访问base中定义的int 和float型数据，所以要用protected类型声明
		//但是其实也是没必要的，访问base定义的数据可以通过函数，用不着直接访问，但是直接访问更方便点。
		int int_data = 0;
   		float float_data = 0;
	public:
		//构造函数和重载
		test_base(int data);
		test_base(float data);
		
		//两种类型的修改和输出函数
		void change_int_data(int data);
		int get_int_data();
		void change_float_data(float data);
		float get_float_data();

		//函数重载
		//这个函数重载只是个例子，以后不能用，因为继承类也不能直接调用基类的数据。
		int add_data(int data);
		float add_data(float data);
		
		//虚函数
		virtual void class_classify ()
		{
			cout<<"this is base class"<<endl;
		}
};


class test_heri:public test_base {
	private:
		double double_data = 0;

	public:
		//构造函数重载
		test_heri(int data);
		test_heri(float data);
		test_heri(double data);
		//数据修改和输出函数
		void change_double_data(double data);
		double get_double_data();
		//运算符重载
		test_heri operator+(test_heri data);
		int operator+(int data);
		//函数模板成员

		//重新定义虚函数
		void class_classify ()
		{
			cout<<"this is heri class"<<endl;
		}

};

