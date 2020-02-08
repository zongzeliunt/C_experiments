#include "systemc.h"
#include "stim.h"
#include "mon.h"
#include "dut.h"
#include "reset_gen.h"
//包含模块的头文件
int sc_main (int argc, char * argv [])
{
  	sc_signal <float> input, output;		
	sc_signal <bool> input_valid, output_valid;		
  	sc_signal <bool> input_ready, output_ready;		
  	sc_signal <bool> reset;		
  	sc_clock TestClk("TestClock", 10, SC_NS, 0.5);
  	  
  	
	stim Stim1("Stimulus");
  	Stim1.gen_data(input);
  	Stim1.gen_data_valid(input_valid);
	Stim1.gen_data_ready(input_ready);
	
	Stim1.rec_data(output);
	Stim1.rec_data_valid(output_valid);
	Stim1.rec_data_ready(output_ready);
  	
	Stim1.Clk(TestClk);
  	Stim1.Reset(reset);

	dut DUT("DUT");
	DUT.input(input);
	DUT.input_valid(input_valid);
	DUT.output(output);
	DUT.output_valid(output_valid);
	DUT.input_ready(input_ready);
	DUT.output_ready(output_ready);

	DUT.Clk(TestClk);
	DUT.Reset(reset);



  	mon Monitor1("Monitor");
  	Monitor1.input(input);
  	Monitor1.input_valid(input_valid);
  	Monitor1.output(output);
  	Monitor1.output_valid(output_valid);
  	Monitor1.Clk(TestClk);
  	Monitor1.Reset(reset);

	reset_gen RESET("Reset");
	RESET.Clk(TestClk);
	RESET.Reset(reset); 


  	sc_start(); 	

	return 0;

}
