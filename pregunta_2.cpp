#include <iostream>
using namespace std;

class   Polygon{
    protected:
        int witdh,height;
    public:
        Polygon(int a, int b): witdh(a), height(b){}
        int area(void){return 0;}
        void printarea(){
            cout<<this->area()<<'\n';
        }
};

//PERDON, ME BLOQUIE :(