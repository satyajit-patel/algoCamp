#include <iostream>
using namespace std;

// Virtual class
class Vehicle {
public:
    // Virtual function for displaying vehicle type
    // virtual void displayType() {

    // }
                // or
    virtual void displayType() = 0;
    //                                      _________________________________
    // above intialise with zero is called |Pure Virtual Fuction Declaration|
    //                                      _________________________________
};

// Derived class Car
class Car: public Vehicle {
public:
    // Implementation of virtual function
    void displayType() {
        std::cout << "This is a Car." << endl;
    }
};

// Derived class Truck
class Truck: public Vehicle {
public:
    // Implementation of virtual function
    void displayType() {
        cout << "This is a Truck." << endl;
    }
};

int main() {
    Vehicle* c = new Car();
    Vehicle* t = new Truck();

    c->displayType();  // Prints "Derived class"
    t->displayType();

    return 0;
}

/*
                        NOTE
                       Summary:
-> Virtual function with a definition: 
    Provides a default implementation that derived classes can override.
-> Pure virtual function: 
    Enforces that derived classes must provide an implementation, 
    making the base class abstract.
    
   This makes the class an abstract class, 
   meaning you cannot define it directly. 
   Derived classes must provide their own implementation
*/
