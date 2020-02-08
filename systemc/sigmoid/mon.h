#include "systemc.h"
#include <iomanip>
#include <iostream>
SC_MODULE(mon)
{
    sc_in<float> input, output;
    sc_in<bool> input_valid, output_valid;
    sc_in<bool> Clk;
    sc_in<bool> Reset;

  void monitor()
  {
    cout << std::setw(10) << "Time";
    cout << std::setw(15) << "input_valid" ;
    cout << std::setw(10) << "input" ;
    cout << std::setw(15) << "output_valid" ;
    cout << std::setw(10) << "output" ;
	cout << std::setw(10) << "reset";
	cout << endl;
    while (true)
    {
      cout << std::setw(10) << sc_time_stamp();
      //cout << std::setw(10) << A.read();
      cout << std::setw(15) << input_valid;
      cout << std::setw(10) << input ;
      cout << std::setw(15) << output_valid;
      cout << std::setw(10) << output;
      cout << std::setw(10) << Reset.read();
      cout << endl;
      wait();    // wait for 1 clock cycle
    }
  }

  SC_CTOR(mon)
  {
    SC_THREAD(monitor);
    sensitive << Clk.pos(); 
  }
};
