#include "systemc.h"
SC_MODULE(stim)
{
	sc_out <int> input_data;
  	sc_out <bool> write_signal;
	sc_out <bool> read_signal;
	
	sc_in <int> output_data;
  	sc_in <bool> full;
	sc_in <bool> empty;
  	
	sc_in <bool> Clk;
	sc_in <bool> Reset;
	//int counter = 0;	
	sc_signal<int> clk_counter;	
	sc_signal<int> write_count; 
  	void write_opt()
  	{
		if (Reset == 1) {
			input_data.write(0);
			write_signal.write(0);
			write_count.write(0);
		} else {
			if (full == 0 && write_count <= 5) {
				input_data.write (write_count + 2);
				write_signal.write(1);
				write_count.write( write_count + 1);
			} else {
				input_data.write (0);
				write_signal.write(0);
			}	
		}
  	}
  	
	void read_opt()
  	{
		if (Reset == 1) {
			read_signal.write(0);
		} else {
			if (empty == 0) {
				read_signal.write(1);
			} else {
				read_signal.write(0);
			}
		}
  	}
	
	void stop_sensor()
	{
		if (write_count >= 10 ) 
		{
			cout<<"sensor stop"<<endl;
			sc_stop();
		}
	}
	
	void stop_guard()
	{
		if (Reset == 1) {
			clk_counter.write(0);
		} else {
			clk_counter.write(clk_counter + 1);
		}
		if (clk_counter >= 10 ) 
		{
			cout<<"guard stop"<<endl;
			sc_stop();
		}
	}
	
	
  	SC_CTOR(stim)
  	{
    	SC_METHOD(write_opt); 
    	sensitive << Clk.pos();			
    	SC_METHOD(read_opt); 
    	sensitive << Clk.pos();			
    	SC_METHOD(stop_sensor); 
    	sensitive << Clk.pos();			
    	SC_METHOD(stop_guard); 
    	sensitive << Clk.pos();			
  	}
};
