#:%s/^[ ]\+/\t/g
API_PATH = "/home/ares/TM_work/NPU_pro_work/NPU_pro_c_driver/C_API"

INCLUDES += -I$(API_PATH)

CC = gcc
OBJ = functions.so

C_FLAGS = -w
C_FLAGS += -g
C_FLAGS += -fPIC -shared

all:
	#$(CC) -w main.c $(INCLUDES) $(API_PATH)/FILE/FILE_API.c  -o $(OBJ)
	$(CC) $(C_FLAGS) functions.c local_lib.c $(INCLUDES) -o $(OBJ)

run:
	./$(OBJ)

clean:
	if [ -e $(OBJ) ]; then rm -r $(OBJ); fi
