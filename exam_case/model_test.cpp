#include <iostream>
using namespace std;
class Model
{
    private:
        int val;
    public:
        Model(int n = 0):val(n){}
        Model(const Model &obj)
        { val =  2*obj.val; }
        Model &operator=(const Model &obj)
        { val =  4*obj.val; return *this; }
        void print()
        {
            cout << val << endl;
        }
};
 
int main( )
{
    Model obj1(10), obj2 = obj1, obj3;
    obj3 = obj1;
    obj1.print();
    obj2.print();
    obj3.print();
    return 0;
}
