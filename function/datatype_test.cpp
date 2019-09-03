#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
	string a = "abcde";
	cout<<"string a "<<a<<" "<<typeid(a).name()<<" "<<sizeof(a)<<endl;	

	int b = 10;
	cout<<"int b "<<b<<" "<<typeid(b).name()<<" "<<sizeof(b)<<endl;	
	
	float c = 50;
	cout<<"float c "<<c<<" "<<typeid(c).name()<<" "<<sizeof(c)<<endl;	
	
	char d = 'd';
	cout<<"char d "<<d<<" "<<typeid(d).name()<<" "<<sizeof(d)<<endl;

	string e = a + "gh";
	cout<<"string e "<<e<<" "<<typeid(e).name()<<" "<<sizeof(e)<<endl;

	cout<<e[6]<<endl;
	
}
