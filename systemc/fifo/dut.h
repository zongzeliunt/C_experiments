#include "systemc.h"
#include <math.h>
SC_MODULE(dut)
{
  	sc_in <int> input_data;
	sc_out <int> output_data;		
	sc_in <bool> write_signal; 
	sc_in <bool> read_signal;		
  	sc_out <bool> full;
	sc_out <bool> empty;		
  	
	sc_in <bool> Reset;		
	sc_in <bool> Clk;
	
	const static int DEPTH = 4;
	int data_array[DEPTH];
	sc_signal<bool> flap;
	sc_signal<int> write_addr;
	sc_signal<int> read_addr;	
	
	
 	void data_array_opt () {
		if (Reset == 1) {
			for (int i = 0; i < DEPTH; i ++ ) {
				data_array[i] = 0;
			}
		} else {
			if (write_signal == 1 && full != 1) {
				data_array[write_addr] = input_data;
			}
		}
	}
	
 	void write_addr_opt () {
		if (Reset == 1) {
			write_addr.write(0);
		} else {
			if (write_signal == 1 && full != 1) {
				if (write_addr == DEPTH - 1) {
					write_addr.write(0);					
				} else {
					write_addr.write(write_addr + 1);
				}
			}
		}
	}
 	
	void read_addr_opt () {
		if (Reset == 1) {
			read_addr.write(0);
		} else {
			if (read_signal == 1 && empty != 1) {
				if (read_addr == DEPTH - 1) {
					read_addr.write(0);					
				} else {
					read_addr.write( read_addr + 1);
				}
			}
		}
	}
	
	void flap_opt () {
		if (Reset == 1) {
			flap = 0;
		} else {
			if (read_signal == 1 && empty != 1) {
				if (read_addr == DEPTH - 1) {
					if (flap == 0) {
						flap.write(1);
					} else {
						flap.write(0);
					}
				}
			}
			if (write_signal == 1 && full != 1) {
				if (write_addr == DEPTH - 1) {
					if (flap == 0) {
						flap.write(1);
					} else {
						flap.write(0);
					}
				}
			}
		}
	}

	void output_data_opt () {
		while (true) { 
			output_data = data_array[read_addr];
			wait(10, SC_NS);
		}
	}

	void empty_opt () {
		while (true) {
			empty = (write_addr == read_addr && flap == 0) ? 1 : 0;
			wait(10, SC_NS);
		}
	}
	
	void full_opt () {
		while (true) {
			//full = (write_addr == read_addr && flap == 1) ? 1 : 0;
			full.write((write_addr == read_addr && flap == 1) ? 1 : 0);
			wait(10, SC_NS);
		}
	}
  	SC_CTOR(dut)
  	{
    	SC_METHOD(data_array_opt); 
    	sensitive << Clk.pos();			
    	SC_METHOD(write_addr_opt); 
    	sensitive << Clk.pos();			
    	SC_METHOD(read_addr_opt); 
    	sensitive << Clk.pos();			
    	SC_METHOD(flap_opt); 
    	sensitive << Clk.pos();	



		//这种方式相当于verilog里的assign	
    	SC_THREAD(output_data_opt); 
    	sensitive << Clk.pos();	
    	SC_THREAD(empty_opt); 
    	sensitive << Clk.pos();	
    	SC_THREAD(full_opt); 
    	sensitive << Clk.pos();	
  	}
};
