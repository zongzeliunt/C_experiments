#:%s/^[ ]\+/\t/g
#LIB_DIR=-L/usr/systemc/lib-linux64
#INC_DIR=-I/usr/systemc/include
LIB_DIR=-L/usr/local/systemc-2.3/lib-linux64
INC_DIR=-I/usr/local/systemc-2.3/include
LIB=-lsystemc

APP=hello

all:
	#g++ -o $(APP) $(APP).cpp $(LIB_DIR) $(INC_DIR) $(LIB)
	g++ -I. $(INC_DIR) -L. $(LIB_DIR) -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -o hello hello.cpp -lsystemc -lm

clean:
	rm -rf $(APP)
