#include "systemc.h"
SC_MODULE(stim)
{
	sc_out <float> gen_data;
  	sc_out <bool> gen_data_valid;
	sc_in <bool> gen_data_ready;
	
	sc_in <float> rec_data;
  	sc_in <bool> rec_data_valid;
	sc_out <bool> rec_data_ready;
  	
	sc_in <bool> Clk;
	sc_in <bool> Reset;
	float initial_data = 0.5;
	//int counter = 0;	
	sc_signal<int> counter;	
	int total_counter = 0;
  	void StimGen()
  	{
		if (Reset == 1) {
			gen_data.write(0);
			gen_data_valid.write(0);
			counter.write(0);
		} else {
			if (gen_data_ready == 1) {
				gen_data.write( initial_data + counter * 0.05);
				gen_data_valid.write(1);
				counter.write(counter.read() + 1);
			} else {
				gen_data.write(0);
				gen_data_valid.write(0);
			}
		}
  	}
	
	void stop_sensor()
	{
		if (counter >= 10 ) 
		{
			cout<<"sensor 2 stop"<<endl;
			sc_stop();
		}
	}
	
	void stop_sensor_1()
	{
		total_counter += 1;
		if (total_counter >= 100 ) 
		{
			sc_stop();
		}
	}
	
  	SC_CTOR(stim)
  	{
    	SC_METHOD(StimGen); 
    	sensitive << Clk.pos();			
    	SC_METHOD(stop_sensor); 
    	sensitive << Clk.pos();			
    	SC_METHOD(stop_sensor_1); 
    	sensitive << Clk.pos();			
  	}
};
