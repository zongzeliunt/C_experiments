#include <iostream> 

using namespace std;

class base {

	public:
		
		
		/*
		virtual void class_classify ()
		{
			cout<<"this is base class"<<endl;
		}
		*/
		//纯虚函数，如果这样声明，此base类就是个抽象类（接口）(abstract)，就不能实例化对象了
		virtual void class_classify () =0;
		
};

class heir1:public base {
	private:
		int int_data;
		char char_data; 
	public:
		heir1(int init_data);
		heir1(char init_data);
		void change_int_data(int data);
		void change_char_data(char data);
		int get_int_data();
		char get_char_data();
		
		//继承类必须定义抽象类里的所有的纯虚函数，不管要不要call它	
		void class_classify ()
		{
			cout<<"this is heir1 class"<<endl;
		}
};



class heir2:public heir1 {
	private:
		float float_data;
	public:
		//构造函数重载
		heir2(float init_data);
		heir2(int init_data);
		heir2(char init_data);

		void change_float_data(float data);
		float get_float_data();
		void class_classify ()
		{
			cout<<"this is hair2 class"<<endl;
		}
}; 
