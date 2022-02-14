#:%s/^[ ]\+/\t/g
#API_PATH = "/home/ares/c_path_exp/API"
API_PATH = $(CURDIR)/../API

INCLUDES += -I$(API_PATH)

CC = gcc
OBJ = hello.o

C_FLAGS = -w
C_FLAGS += -g

all:
	$(CC) -w main.c $(INCLUDES) $(API_PATH)/api.c -o $(OBJ)

run:
	./$(OBJ)

clean:
	if [ -e $(OBJ) ]; then rm -r $(OBJ); fi




