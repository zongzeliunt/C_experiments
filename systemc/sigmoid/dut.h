#include "systemc.h"
#include <math.h>
SC_MODULE(dut)
{
  	sc_in <float> input;
	sc_out <float> output;		
	sc_in <bool> input_valid; 
	sc_out <bool> output_valid;		
  	sc_out <bool> input_ready;
	sc_in <bool> output_ready;		
  	sc_in <bool> Reset;		
	sc_in <bool> Clk;

	sc_fifo<float> data_fifo;
	int opt_counter;
	float cal_data; 

 
	void rec_data()
	{
		if (Reset == 1) {
			input_ready.write(0);
			opt_counter = 0;
		} else {
			if (opt_counter % 3 == 0) {
				input_ready.write(0);
			} else {
				input_ready.write(1);
			}
			if (input_valid == 1) {
				data_fifo.nb_write(input);
			}
			opt_counter += 1;
		}
	}
	
	void calculate()
  	{
		if (Reset == 1) {
			output.write(0);
			output_valid.write(0);
		} else {
			if (data_fifo.nb_read(cal_data) ) {
				//用这种方式来判断fifo是不是空，如果能读出数据，就进行计算
				output.write(1/(exp(-1 * cal_data) + 1));
				//output.write(cal_data + float(14));
				output_valid.write(1);
			} else {
				output.write(0);
				output_valid.write(0);
			}
		}
  	}
	
	
  	SC_CTOR(dut)
  	{
    	SC_METHOD(rec_data); 
    	sensitive << Clk.pos();			
    	SC_METHOD(calculate); 
    	sensitive << Clk.pos();			
  	}
};
