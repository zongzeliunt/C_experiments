//每一个switch-case必须加上break，否则能match一个就顺序把下面所有的case全执行一遍，如果把default放最上面又不写break，则下面的条件全执行！

#include <stdio.h>
#include <iostream>
using namespace std;
main( )
{
   int i, n=0;
   for(i=0; i<5; i++)
   {
		cout<<"i value: "<<i<<endl;
      switch(i)
      {
         default:
            cout<<"default"<<endl;
         case 1:
            cout<<"case 1 i value: "<<i<<endl;
         case 3:
            cout<<"case 3 i value: "<<i<<endl;
         case 4:
            cout<<"case 4 i value: "<<i<<endl;
      }
   }
}
