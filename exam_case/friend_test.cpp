#include<iostream>
using namespace std;
class P
{
public:
        P( int x, int y ) 
  { 
   X = x; 
   Y = y; 
  }
        void Print() 
  { 
   cout << "P(" << X << ", " << Y << ")" << endl;
  }
        friend P operator+( P & pt, int n );
private:
        int X, Y;
};
//P operator+( P & pt, int n )
P P::operator+( P & pt, int n )
{
   P T= pt;
   T.X += n;
   T.Y += n;
   return T;
}
int main()
{
   P pt( 10, 10 );
   pt = pt + 5;
   pt.Print();
   return 0;
}
