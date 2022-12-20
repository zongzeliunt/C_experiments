#TM laptop, SYSTEMC_HOME = /usr/local/systemc-2.3
LIB_DIR=-L$(SYSTEMC_HOME)/lib-linux64
INC_DIR=-I$(SYSTEMC_HOME)/include
LIB=-lsystemc

APP=main

all:
	g++ -o $(APP) $(APP).cpp $(LIB_DIR) $(INC_DIR) $(LIB)

clean:
	rm -rf $(APP)
