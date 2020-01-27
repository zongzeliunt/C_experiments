#include <iostream>
#include <algorithm>
#include <list>
#define size 10
using namespace std;
typedef list <int> iList;
int main ()
{
    int x[size],i;
    iList::iterator iL; 
    iList list1; 
    for (i=1; i<size; i++) {    
  		list1.push_front(2*i+1);    
  		//list1.push_front(3);
	}	
    cout<<count(list1.begin(),list1.end(),3)<<endl;

	for (iL = list1.begin(); iL != list1.end(); iL++) {
		cout<<*iL<<endl;
	}
   return 0;
}
