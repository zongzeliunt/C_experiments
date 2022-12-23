
#include "SoDemoTest.h"

void ares_class::print_hello () {
	std::cout << "hello ares." << std::endl;

}

ares_class* gen_class_obj() {return new ares_class();}

void ares_class_call_print_hello (ares_class* class_obj) {
    class_obj -> print_hello();
}
