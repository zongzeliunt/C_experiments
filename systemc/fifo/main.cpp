#include "systemc.h"
#include "stim.h"
#include "mon.h"
#include "dut.h"
#include "reset_gen.h"
//包含模块的头文件
int sc_main (int argc, char * argv [])
{
  	sc_signal <int> input, output;		
	sc_signal <bool> full, empty;		
  	sc_signal <bool> write_signal, read_signal;		
  	sc_signal <bool> reset;		
  	sc_clock TestClk("TestClock", 10, SC_NS, 0.5);
  	  
  	
	stim Stim1("Stimulus");
  	Stim1.input_data(input);
  	Stim1.write_signal(write_signal);
	Stim1.read_signal(read_signal);
	
	Stim1.output_data(output);
	Stim1.full(full);
	Stim1.empty(empty);
  	
	Stim1.Clk(TestClk);
  	Stim1.Reset(reset);

	dut DUT("DUT");
	DUT.input_data(input);
	DUT.write_signal(write_signal);
	DUT.output_data(output);
	DUT.read_signal(read_signal);
	DUT.full(full);
	DUT.empty(empty);

	DUT.Clk(TestClk);
	DUT.Reset(reset);



  	mon Monitor1("Monitor");
  	Monitor1.input_data(input);
  	Monitor1.write_signal(write_signal);
	Monitor1.read_signal(read_signal);
	
	Monitor1.output_data(output);
	Monitor1.full(full);
	Monitor1.empty(empty);
	
	Monitor1.Clk(TestClk);
  	Monitor1.Reset(reset);




	reset_gen RESET("Reset");
	RESET.Clk(TestClk);
	RESET.Reset(reset); 


  	sc_start(); 	

	return 0;

}
