#include "systemc.h"
SC_MODULE(reset_gen)
{
	sc_out <bool> Reset;	
  	sc_in <bool> Clk;
	void ResetGen()
	{

		Reset.write(0); 
		wait(10, SC_NS);
		Reset.write(1); 
		wait(10, SC_NS);
		Reset.write(0); 

	}
  	SC_CTOR(reset_gen)
  	{
    	SC_THREAD(ResetGen);
		sensitive << Clk.pos(); 
  	}

};

