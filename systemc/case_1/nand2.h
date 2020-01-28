#include "systemc.h"
SC_MODULE(nand2)//声明nand2 sc_module
{
	sc_in <bool> A, B; //输入信号端口
	sc_out <bool> F; //输出信号端口

  	void do_nand2()//一个C ++函数
  	{
    	F.write(!(A.read()&& B.read()));
  	}

  	SC_CTOR(nand2)// nand2的构造函数
  	{
    	SC_METHOD(do_nand2); //用内核注册do_nand2函数作 进程
    	sensitive << A << B ;		//敏感表
  	} 
};
