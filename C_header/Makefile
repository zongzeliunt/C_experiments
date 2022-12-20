#:%s/^[ ]\+/\t/g
GCC += gcc-10
INCLUDES =  
INCLUDES += func.c
#INCLUDES += ../API/FT4222_API.c
LOCAL = 
#LOCAL += flow.c
#LIB += -lft4222 -Wl,-rpath,/usr/local/lib 

all:
	$(GCC) -w -g $(INCLUDES) $(LOCAL) main.c -o main.o
