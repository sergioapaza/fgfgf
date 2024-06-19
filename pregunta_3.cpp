#include <iostream>

using namespace std;

class Fraction{
    
    public:
    int gcd(int a, int b){return b==0 ? a:gcd(b,a%b);}
    int n,d;
    Fraction(int n,int d=1):n(n/gcd(n,d)),d(d/gcd(n,d)){}
        int num() const {return n;}
        int den() const {return d;}
        Fraction operator+(const Fraction& rhs){
            int new_n=n*rhs.n/gcd(n*rhs.n,d*rhs.d);
            d=d*rhs.d/gcd(n*rhs.n,d*rhs.d);
            n=new_n;
            return *this;
        }

        Fraction operator==(const Fraction& rhs){
            return n*rhs.d == d*rhs.n;
        }

        Fraction operator!=(const Fraction& rhs){
            return n*rhs.d != d*rhs.n;
        }
    
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs){}
    friend ostream& operator<<(ostream& output, const Fraction& o);
    friend Fraction operator==(const Fraction& lhs, const Fraction& rhs){}
    friend Fraction operator!=(const Fraction& lhs, const Fraction& rhs){}
};

int main() {
    Fraction f1(3,8),f2(1,2),f3(10,2);
    cout<<(f1==f2)<< '\n';
    cout<<(f1!=f2)<< '\n';
    cout<<f1<<" * "<<f2<<" = "<<(f1*f2)<< '\n';
    cout<<f2<<" * "<<f3<<" = "<<(f2*f3)<< '\n';
    cout<<2<<" * "<<f1<<" = "<<(2*f1)<< '\n';
    return 0;
}
ostream& operator<<(ostream& output, const Fraction& o){
    output<<o.num()<<"/"<<o.num();
}