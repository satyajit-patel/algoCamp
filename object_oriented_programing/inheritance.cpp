#include<bits/stdc++.h>
using namespace std;
//----------------------------------------------------------------------------

/*          
                                // how we are inheriting
                                public      protected   private  
base class          public      public      protected   private   
access-modifier     protected   protected   protected   private
                    private     NA          NA          NA

i.g 
    if "base" class data members are "public" and we are inheriting as "protected"
    then the in "derived".. "base" class becomes "protected"

Note
    private data member of any class can not be inherited

what is protected access modifier ?
    => It is similar to private
    => just the difference is
        -> It is accessable inside own class
        -> child class can inherit

*/

// class Maruti {
// protected:
//     string companyName;
//     int mileage;

// public:
//     Maruti(string companyName, int mileage) {
//         this->companyName = companyName;
//         this->mileage = mileage;
//     }
    
//     void print() {
//         cout << "companyName = " << this->companyName << endl;
//         cout << "mileage = " << this->mileage << endl;
//         cout << endl;
//     }
// };

// class Dezire: public Maruti {
// private:
//     string carName;

// public:
//     Dezire(string carName, int mileage): Maruti("maruti_suzuki", mileage) {
//         this->carName = carName;
//     }
//     void print() {
//         /*
//             we need to keep access modifier as protected (not private) 
//             to access this->companyName of base clas in derived class
            
//             if base class data members would have been private then
//             we would have used getter function to access data of base class
//             as public getter function can can access private data members of same class
//         */
//         cout << "carName = "<< this->carName << endl;
//         cout << "companyName = " << this->companyName << endl;
//         cout << "mileage = " << this->mileage << endl;
//         cout << endl;
//     }
// };

// class Swift: public Maruti {
// private:
//     string carName;
// public:
//     Swift(string carName, string companyName, int mileage): Maruti(companyName, mileage) {
//         this->carName = carName;
//     }
    
//     void print() {
//         cout << "carName = "<< this->carName << endl;
//         Maruti::print();
//     }
// };

// void solve() {
//     Maruti m1("maruti_suzuki", 25);
//     m1.print();
    
//     Dezire d1("desire", 30);
//     d1.print();
    
//     Swift s1("swift", "maruti_suzuki", 35);
//     s1.print();
// }

class A {
protected:
    int x = 10;
};

class B: public A {
    // here x becomes protected
public:
    int getData() {
        return this->x;
    }
};

class C: private A {
    // here x becomes private
public:
    int getData() {
        return this->x;
    }
};

class D: protected B {
    // here x becomes protected
public:
    int getData() {
        return this->x;
    }
};

class E: public C {
    // NA (Not Accessible)
public:
    int getData() {
        return this->x; // ERROR
        // as private data member of any class can not be inherited
    }
};

void solve() {
    B b;
    cout << b.getData() << endl; // 10

    C c;
    cout << c.getData() << endl; // 10

    D d;
    cout << d.getData() << endl; // 10
}

//----------------------------------------------------------------------------
int main() {
    solve();
    return 0;
}