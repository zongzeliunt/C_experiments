//Qe1Qt2

#include <stdio.h>
#include <iostream>
using namespace std;
main( )
{
   int i, n=0;
   char c, str[] = "test";
   for(i=0; str[i]; i++)
   {
      c = str[i];
		cout<<i<<" "<<c<<endl;
      switch(i)
      {
         case 1:
         case 3:
         case 4:
            cout<<"case 4: "<<c<<" i is: "<<i<<endl;
            //putchar(c);
            cout<<++n<<endl;
            //printf("%d", ++n);
            break;
         default:
            cout<<"default Q"<<endl;
            //putchar('Q');
      }
   }
}
