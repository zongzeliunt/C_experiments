#include "systemc.h"
#include "stim.h"
#include "mon.h"
#include "reset_gen.h"
//包含模块的头文件
int sc_main (int argc, char * argv [])
{
  	sc_signal <int> ASig, BSig;		
  	sc_signal <bool> reset;		
  	sc_clock TestClk("TestClock", 10, SC_NS, 0.5);
  	  
  	
	stim Stim1("Stimulus");
  	Stim1.A(ASig);
  	Stim1.B(BSig);
  	Stim1.Clk(TestClk);
  	Stim1.Reset(reset);


  	mon Monitor1("Monitor");
  	Monitor1.A(ASig);
  	Monitor1.B(BSig);
  	Monitor1.Clk(TestClk);
  	Monitor1.Reset(reset);

	reset_gen RESET("Reset");
	RESET.Clk(TestClk);
	RESET.Reset(reset); 


  	sc_start(); 	

	return 0;

}
