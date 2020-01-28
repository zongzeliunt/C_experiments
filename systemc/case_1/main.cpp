#include "systemc.h"
#include "stim.h"
#include "exor2.h"
#include "mon.h"
//包含模块的头文件
int sc_main (int argc, char * argv [])
{
  	sc_signal <bool> ASig, BSig, FSig;		//声明 连线的顶层信号以及          使用sc_clock创建的时钟(sc_clock声明语句时钟初始逻辑值持续时间为0时将在时间0触发一个上升沿)
  	sc_clock TestClk("TestClock", 10, SC_NS, 0.5);//sc_clock有5个重载的构造函数.(时钟名，时钟周期，时间单位，占空比，时钟初始逻辑值持续，时间，首个逻辑值)
  	  //每个模块被实例化和连接
  	stim Stim1("Stimulus");//刺激发生器(相当于信号电源？) 模块实例化
  	Stim1.A(ASig);
  	Stim1.B(BSig);
  	Stim1.Clk(TestClk);

  	exor2 DUT("exor2");//异或门 模块实例化
  	DUT.A(ASig);
  	DUT.B(BSig);
  	DUT.F(FSig);

  	mon Monitor1("Monitor");//监视器 模块实例化
  	Monitor1.A(ASig);
  	Monitor1.B(BSig);
  	Monitor1.F(FSig);
  	Monitor1.Clk(TestClk);

  	sc_start(); 	//调用sc_start()开始仿真 并永久运行(或者直到它遇到在刺激模块中对sc_stop()的调用)
  return 0;

}
