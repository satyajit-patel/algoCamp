#include <iostream>
using namespace std;

class complex {
private:
    int real;
    int img;
    
public:
    complex() {
        this->real = 0;
        this->img = 0;
    }
    complex(int real, int img) {
        this->real = real;
        this->img = img;
    }
    
    complex add(complex c1, complex c2) {
        complex ans;
        
        ans.real = c1.real + c2.real;
        ans.img = c1.img + c2.img;
        
        return ans;
    }
    
    complex operator+(complex c2) {
        complex ans;
        
        ans.real = this->real + c2.real;
        ans.img = this->img + c2.img;
        
        return ans;
    }
    
    int getReal() {
        return this->real;
    }
    int getImg() {
        return this->img;
    }
};

void solve() {
    complex c1(5, 2);
    complex c2(4, 7);
    
    complex ans = ans.add(c1, c2);
    cout<<ans.getReal()<<"+"<<ans.getImg()<<"i\n";
    
    // operator overloading
    complex res = c1 + c2;
    cout<<res.getReal()<<"+"<<res.getImg()<<"i\n";
}

int main() {
    solve();
    return 0;
}