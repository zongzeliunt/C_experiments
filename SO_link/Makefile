#:%s/^[ ]\+/\t/g

# step1:
#g++ one.cpp two.cpp three.cpp -fPIC -shared -o libtest.so
# step2:
#g++ main.cpp -L. -ltest -o main
# step3:
#ldd main

#just a reference
#   g++ -w -g -ldl -Wl,--no-as-needed -lpython3.8 -fPIC -shared -DDebug one.cpp -o libtest.so 

so_only:
	g++ -w -g -fPIC -shared -DDebug one.cpp two.cpp three.cpp four.cpp -o libtest.so

all:
	make so_only
	g++ main.cpp -L. -ltest -o main

pure_c:
	g++ -DPUREC main.cpp one.cpp two.cpp three.cpp four.cpp -o main_pure_c

clean:
	rm main
	rm libtest.so


