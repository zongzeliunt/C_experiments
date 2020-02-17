#include "systemc.h"
#include <iomanip>
#include <iostream>
SC_MODULE(mon)
{
    sc_in<int> input_data, output_data;
    sc_in<bool> write_signal, read_signal;
    sc_in<bool> full, empty;
    sc_in<bool> Clk;
    sc_in<bool> Reset;

  void monitor()
  {
    cout << std::setw(10) << "Time";
    cout << std::setw(10) << "Reset";
    cout << std::setw(15) << "write_signal" ;
    cout << std::setw(10) << "input" ;
    cout << std::setw(15) << "read_signal" ;
    cout << std::setw(10) << "output" ;
	cout << std::setw(10) << "full";
	cout << std::setw(10) << "empty";
	cout << endl;
    while (true)
    {
      cout << std::setw(10) << sc_time_stamp();
      cout << std::setw(10) << Reset;
      cout << std::setw(15) << write_signal;
      cout << std::setw(10) << input_data;
      cout << std::setw(15) << read_signal;
      cout << std::setw(10) << output_data;
      cout << std::setw(10) << full;
      cout << std::setw(10) << empty;
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
