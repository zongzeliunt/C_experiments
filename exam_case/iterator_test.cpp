#include <iostream>
#include <algorithm>
#include <vector>
#include<iterator>
using namespace std;
class f
{            
public:
 int operator()() const
 {return __________;}
private:
 static int x;
};
int f::x=0;       
int main()
{
 int A[]={7,8,9,4,0};
 vector<int> B(A+1,A+3);   
 ostream_iterator< int > output( cout, " " ); 
    generate(B.begin(),B.end(),f());
 copy(B.begin(),B.end(),output);
 cout<<endl; 
    return 0;
}
