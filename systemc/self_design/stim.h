#include "systemc.h"
SC_MODULE(stim)
{
	sc_out <int> A, B;	
  	sc_in <bool> Clk;
	sc_in <bool> Reset;
	//int counter = 0;	
	sc_signal<int> counter;	
  	void StimGen()
  	{
		if (Reset == 1) {
			A.write(0);
			B.write(0);
			counter.write(0);
		} else {
			cout<<"counter "<<counter<<endl;
			A.write(counter);
			B.write(counter + 10);
			counter.write(counter.read() + 1);
		}
  	}
	void stop_sensor_1()
	{
		while (true) {
			if (counter >= 9 ) 
			{
				cout<<"sensor 1 stop"<<endl;
				sc_stop();
			}
			wait();
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
	
  	SC_CTOR(stim)
  	{
    	SC_METHOD(StimGen); 
    	sensitive << Clk.pos();			
    	SC_METHOD(stop_sensor); 
    	sensitive << Clk.pos();			
    	SC_THREAD(stop_sensor_1); 
    	sensitive << Clk.pos();			
  	}
};
