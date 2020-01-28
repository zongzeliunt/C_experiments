#include "systemc.h"
#include "nand2.h"
SC_MODULE(exor2)
{	//模块exor2被创建

  	sc_in <bool> A, B;//端口被声明
  	sc_out <bool> F;	//允许重复使用名称A，B 和F，因为这是层次结构的不同层

  	nand2 n1, n2, n3, n4;	//声明nand2的四个实例

  	sc_signal <bool> S1, S2, S3;	//sc_signal是一个原始通道，一个带有模板参数的类，该参数指定了信号可以容纳的数据类型

  	SC_CTOR(exor2):n1("N1"),n2("N2"),n3("N3"),n4("N4")//初始化列表
  	{
    	n1.A(A);//构造函数内 端口连接
    	n1.B(B);
    	n1.F(S1);

    	n2.A(A);
    	n2.B(S1);
    	n2.F(S2);

    	n3.A(S1);
    	n3.B(B);
    	n3.F(S3);

    	n4.A(S2);
    	n4.B(S3);
    	n4.F(F);
  	}
};
