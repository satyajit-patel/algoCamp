#include<bits/stdc++.h>
using namespace std;

class Maruti {
protected:
    string companyName;
    int mileage;

public:
    Maruti(string companyName, int mileage) {
        this->companyName = companyName;
        this->mileage = mileage;
    }
    
    void print() {
        cout << "companyName = " << this->companyName << endl;
        cout << "mileage = " << this->mileage << endl;
        cout << endl;
    }
};

class Dezire: public Maruti {
private:
    string carName;

public:
    Dezire(string carName, string companyName, int mileage): Maruti(companyName, mileage) {
        this->carName = carName;
    }
    
    void print() {
        /*
            we need to keep access modifier as protected (not private) to
            access this->companyName of base clas in derived class
            
            if base class data members would have been private then
            we would have used getter function to access data of base class
            as public getter function can can access private data members of same class
        */
        cout << "carName = "<< this->carName << endl;
        cout << "companyName = " << this->companyName << endl;
        cout << "mileage = " << this->mileage << endl;
        cout << endl;
    }
};

class Swift: public Maruti {
private:
    string carName;

public:
    Swift(string carName, string companyName, int mileage): Maruti(companyName, mileage) {
        this->carName = carName;
    }
    
    void print() {
        cout << "carName = "<< this->carName << endl;
        Maruti::print();
    }
};

void solve() {
    Maruti m1("maruti_suzuki", 25);
    m1.print();
    
    Dezire d1("desire", "maruti_suzuki", 30);
    d1.print();
    
    Swift s1("swift", "maruti_suzuki", 35);
    s1.print();
}

int main() {
    solve();
    return 0;
}