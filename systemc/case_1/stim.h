#include "systemc.h"
SC_MODULE(stim)
{
	sc_out <bool> A, B;	//输出端口！！
  	sc_in <bool> Clk;	//定义一个时钟输入信号。(事实上有typedef sc_in<bool> sc_in_clk;)时钟是sc_clock类的特殊对象

  	void StimGen()
  	{
    	A.write(false);
    	B.write(false);
    	wait();//线程进程使用wait()挂起，当敏感表中有事件发生，线程进程被重新激活运行到遇到新的wait()语句再重新挂起。
    	A.write(false);//在一次仿真中，线程进程一旦退出，将不能再次进入。
    	B.write(true);
    	wait();
    	A.write(true);
    	B.write(false);
    	wait();
    	A.write(true);
    	B.write(true);
    	wait();
    	sc_stop();	//仿真停止
  	}
  	SC_CTOR(stim)
  	{
    	SC_THREAD(StimGen); //内核注册StimGen()函数作 线程
    	sensitive << Clk.pos() ;	//为线程声明 敏感表。
		//时钟Clk的每一个上升沿，StimGen()函数被激活一次，当执行到wait()函数，则重新被挂起，直到下一个Clk的上升沿到来，StimGen()重新被激活，
	//并开始接着执行wait()后面接下来的代码，这里wait()的作用是将进程挂起，等待下一次被激活.
  	}
};
