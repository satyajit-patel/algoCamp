#include <iostream>

// Virtual class
class Vehicle {
public:
    // Virtual function for displaying vehicle type
    virtual void displayType() = 0;
};

// Derived class Car
class Car : public Vehicle {
public:
    // Implementation of virtual function
    void displayType() {
        std::cout << "This is a Car." << std::endl;
    }
};

// Derived class Truck
class Truck : public Vehicle {
public:
    // Implementation of virtual function
    void displayType() {
        std::cout << "This is a Truck." << std::endl;
    }
};

int main() {
    // Create objects of Car and Truck
    Car car;
    Truck truck;

    // Display types of vehicles
    car.displayType();
    truck.displayType();

    return 0;
}
