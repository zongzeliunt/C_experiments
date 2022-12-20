#:%s/^[ ]\+/\t/g

# step1:
#g++ one.cpp two.cpp three.cpp -fPIC -shared -o libtest.so
# step2:
#g++ main.cpp -L. -ltest -o main
# step3:
#ldd main

all:
	g++ one.cpp two.cpp three.cpp -fPIC -shared -o libtest.so
	g++ main.cpp -L. -ltest -o main

clean:
	rm main
	rm libtest.so


