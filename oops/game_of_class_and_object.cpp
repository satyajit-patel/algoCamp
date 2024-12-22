/*
Class and Object
Object-oriented programming (OOP) is a computer programming model 
that organizes software design with classes and objects, 
rather than functions and logic.
Class :
-> A class is the building block that leads to Object-Oriented programming. 
It is a user-defined data type, 
which holds its own data members and member functions, 
which can be accessed and used by creating an instance of that class.

Object :
-> An Object is an instance of a Class. 
When a class is defined, no memory is allocated but when it is instantiated 
(i.e. an object is created) memory is allocated.
*/
// #include <bits/stdc++.h>
// using namespace std;
// class Person {
// // Access specifier
// public:

//         // Data Members
//         string name;

//         // Member Functions()
//         void printname(){
//                 cout << "Person name is: " << name;
//         }
// };
// int main() {
// 	// Declare an object of class Person
// 	Person obj1;

// 	// accessing data member
// 	obj1.name = "Thanos";

// 	// accessing member function
// 	obj1.printname();
// 	return 0;
// }

/*
Constructor & Destructor

Constructor :
-> Constructors are special class members which are called by the compiler 
every time an object of that class is instantiated. 
-> Constructors have the same name as the class and 
may be defined inside or outside the class definition.

There are 3 types of constructors:
1. Default constructors
2. Parameterized constructors
3. Copy constructors

1. Default Constructor: 
        Default constructor is the constructor which doesn’t take any argument.

2. Parameterized Constructor: 
        A constructor is called Parameterized Constructor 
        when it accepts a specific number of parameters.
 
3.Copy Constructor: 
        A copy constructor is a member function 
        which initializes an object using another object of the same class.

Characteristics of the constructor:
        1. Constructor has same name as the class itself.
        2. Constructors don’t have return type.
        3. A constructor is automatically called when an object is created.
        4. It must be placed in public section of class.
        5. If we do not specify a constructor, 
        C++ compiler generates a default constructor for object.
        6. Constructors can be overloaded.
        7. Constructor can not be declared virtual.
*/
// #include <bits/stdc++.h>
// using namespace std;
// class student {
//         string name;
// public:
//         int age;
//         bool gender;

//         student() {                        // Default Constructor
//                 cout << "Default Constructor \n" << endl;
//         }

//         student(string s, int a, int b) {  // parameterised constructor
//                 name = s;
//                 age = a;
//                 gender = b;
//                 cout << "parameterised constructor \n" << endl;
//         }

//         student(student& p) {               // copy constructer
//                 name = p.name;
//                 age = p.age;
//                 gender = p.gender;
//                 cout << "copy constructer \n" << endl;
//         }

//         void printinfo() {
//                 cout << "Name = ";
//                 cout << name << endl;
//                 cout << "Age = ";
//                 cout << age << endl;
//                 cout << "Gender = ";
//                 cout << gender << endl;
//         }
// };
// int main() {
//     student p("Sumit", 20, 1);
//     student d;
//     student c = p;
//     c.printinfo();
//     return 0;
// }
/*
Destructor :
-> A destructor is also a special member function as a constructor. 
-> Destructor destroys the class objects created by the constructor. 
-> Destructor has the same name as their class name
   preceded by a tiled (~) symbol.

Characteristics of a destructor:-
1. Destructor is invoked automatically by the compiler when 
   its corresponding constructor goes out of scope 
   and releases the memory space that is no longer required by the program.
2. Destructor neither requires any argument nor returns any value 
   therefore it cannot be overloaded.
3. Destructor  cannot be declared as static and const.
4. Destructor should be declared in the public section of the program.
*/
// #include <iostream>
// using namespace std;
// int count;
// class num {
// public:
//     num() {             // Constructor
//         count++;
//         cout << "Constructor called with object num: " << count << endl;
//     }

//     ~num() {            // Destructor
//         cout << "Destructor called with object num: " << count << endl;
//         count--;
//     }
// };
// int main() {
//         count = 0;
//         num n;
//         return 0;
// }

/*
Inheritance
-> Inheritance is one of the most important features of OOP.
   The capability of a class to derive properties and characteristics
   from another class is called Inheritance.

-> derived class(child) - the class that inherits from another class
-> base class(parent) - the class being inherited from

Example:
For instance, we are humans. We inherit certain properties from the class 
'Human' such as the ability to speak, breathe, eat, drink, etc

There are 5 Types of Inheritance in C++ :
        1. Single Inheritance.
        2. Multiple Inheritance.(derived from multiple base class)
        3. Multilevel Inheritance.
        4. Hierarchical Inheritance.(derived from one base class)
        5. Hybrid Inheritance.
*/
// 1. Single Inheritance
// When a subclass(child) is inherited from a base class is called single inheritance.
// #include<bits/stdc++.h>
// using namespace std;

// class A {
// public:
//         void funcA() {
//                 cout<<"class A"<<endl;
//         }
// };

// class B: public A {
// public:
//         void funcB(){
//                 cout<<"class B"<<endl;
//         }
// };

// int main() {
//     B obj;
//     obj.funcA();
//     return 0;
// }
// 2. Multipile Inheritance
// when one subclass is inherited from more than one base class 
// is called multiple inheritance.
// #include<bits/stdc++.h>
// using namespace std;

// class A {
// public:
//         void func() {
//                 cout<<"class A"<<endl;
//         }
// };

// class B {
// public:
//         void func() {
//                 cout<<"class B"<<endl;
//         }
// };

// class C: public A, public B {
// public:
//         void func() {
//                 cout<<"class C"<<endl;
//         }
// };

// int main() {
//         C obj;
//         obj.func();

//         // resolving ambiguity
//         obj.A :: func();  
//         obj.B :: func();
        
//         return 0;
// }
// 3. Multilevel Inheritance
// In this type, a derived class is created from another derived class.
// #include<bits/stdc++.h>
// using namespace std;

// class A {
// public:
//   void funcA() {
//     cout<<"class A"<<endl;
//   }
// };

// class B: public A {
// public: 
//     void funcB() {
//         cout<<"class B"<<endl;
//     }
// };

// class C: public B {
// public:
//     void func() {
//         cout<<"class C"<<endl;
//     }
// };

// int main() {
//     C obj;
//     obj.funcB();
//     obj.funcA();
//     return 0;
// }
// 4. Hierarchical Inheritance
// In this type, more than one subclass is inherited from a single base class.
// #include<bits/stdc++.h>
// using namespace std;

// class A {
// public:
//     void funcA() {
//         cout<<"class A"<<endl;
//     }
// };

// class B: public A {
//     public:
//     void funcB(){
//         cout<<"class B"<<endl;
//     }
// };

// class C: public A {
// public:
//     void funcC() {
//         cout<<"class C"<<endl;
//     }
// };

// int main() {
//     C obj1;
//     obj1.funcA();

//     B obj2;
//     obj2.funcB();
//     obj2.funcA();
//     return 0;
// }
// 5. Hybrid Inheritance
// Hybrid inheritance is a combination of 
// multiple inheritance and multilevel inheritance.

/*
There are 2 Ways to Avoid Ambiguity :
    1. Avoiding ambiguity using the scope resolution operator: 
        Using the scope resolution operator we can manually specify the path 
        from which data member will be accessed.
    2. Avoiding ambiguity using the virtual base class: 
        Virtual classes are primarily used during multiple inheritance. 
        To avoid, multiple instances of the same class 
        being taken to the same class which later causes ambiguity.
*/
// Using scope resolution operator :
// #include <iostream>
// using namespace std;

// class A {
// public:
//     void func() {
//         cout << " I am in class A" << endl;
//     }
// };

// class B {
// public:
//     void func() {
//         cout << " I am in class B" << endl;
//     }
// };

// // Derived class C
// class C: public A, public B {
// };

// int main(){
//     // Created an object of class C
//     C obj;

//     // Calling function func() in class A
//     obj.A::func();

//     // Calling function func() in class B
//     obj.B::func();

//     return 0;
// }
// Using Virtual class :
//________________________________________________________
//| NOTE: virtual class is different from virtual function |
//|________________________________________________________|
/*
   A virtual function is a function that you can override in derived classes 
   to provide different behavior 
   while still keeping the same interface (function signature) from the base class. 
   However virtual inheritance is different from virtual functions 
   but still involves the keyword virtual.
*/
// #include <iostream>
// using namespace std;

// class A {
// public:
//     int a;
//     A() {
//         a = 10;
//     }
// };

// // class B: public A {
// // };

// // class C: public A {
// // };

// /*
//    In the above case, 
//    class D inherits two copies of class A.
//    one from class B and one from class C. 
//    So when you access object.a, 
//    the compiler doesn't know which a you mean, leading to ambiguity

//    NOW
//    With Virtual Inheritance:
//    You can resolve this ambiguity by using virtual inheritance, 
//    which ensures that only one copy of class A is inherited, 
//    no matter how many classes derive from it:
// */

// class B: public virtual A {
// };

// class C: public virtual A {
// };

// class D : public B, public C {
// };

// int main() {
//     // creating class D object
//     D object;
//     cout << "a = " << object.a << endl;

//     return 0;
// }


/*
Polymorphism

-> The word polymorphism means having many forms. 
   Polymorphism occurs when there is a hierarchical mode inheritance.

Polymorphism is divided into two types :
   1. Compile time Polymorphism(overloading)
   2. Runtime Polymorphism - virtual function(overriding)

Example:
Another excellent real time example of polymorphism is your smartphone. 
The smartphone can act as phone, camera, music player and what not.

Compile-time polymorphism :
   -> Compile-time polymorphism is a polymorphism that is, 
      the function call is resolved during the compilation process
   -> compile-time polymorphism is divide into two type:
      -> Function overloading
      -> Operator overloading

1. Function overloading :
   -> when there are multiple functions with the same name 
      but take different parameters as an arguments 
      then these function are said to be overloaded.
   -> Functions can be overloaded by changing the number of arguments
      or changing the type of arguments.
*/
// #include<bits/stdc++.h>
// using namespace std;

// class Simple {
// public:
//   void fun() {
//       cout<<"function with no argument"<<endl;
//   }

//   void fun(int x) {
//       cout <<"function with int argument"<<endl;
//   }
//   void fun(double x) {
//       cout<<"function with double argument"<<endl;
//   }
// };

// int main() {
//     Simple obj;
//     obj.fun();
//     obj.fun(4);
//     obj.fun(4.5);

//     return 0;
// }
/*
2. Operator Overloading :
   -> C++ also provides the option to overload operators So a single operator ‘+’, 
   when placed between integer operands, 
   adds them and when placed between string operands, concatenates them.
   
Runtime Polymorphism :
-> Runtime polymorphism is also known as
   _______________________________________
   |dynamic polymorphism or late binding.|
   |_____________________________________|
   In runtime polymorphism, the function call is resolved at run time.
-> This type of polymorphism is achieved by 
   Function Overriding or Virtual function.
   __________________________________________________________
-> |A virtual function is a member function in the base class| 
   |that we expect to redefine in derived classes.|
   ________________________________________________
   When you use a base class pointer or reference 
   to point to a derived class object, 
   calling a virtual function will invoke the derived class version,
   not the base class version. 
   This allows for polymorphism — treating different objects uniformly 
   while executing their specific behavior.

Advantages of virtual function 
   -> It helps the programmer to reuse the code.
   -> It also save lot of time.
   -> Easy to debug the code.
*/
// #include <iostream>
// using namespace std;

// class Base {
// public:
//    virtual void print() {
//       cout << "Base Function" << endl;
//    }

//    // without virtual keyword
//    void ping() {
//       cout << "Pong from Base class" << endl;
//    }
// };

// class Derived: public Base {
// public:
//    void print() {
//       cout << "Derived Function" << endl;
//    }
//    void ping() { // Override base class function
//       cout << "Pong from Derived class" << endl;
//    }
// };

// int main() {
//    /*
//    Without virtual functions, 
//    C++ will always call the base class version of a function, 
//    even if the object is of a derived class.
//    This can lead to incorrect behavior if you're trying to work with 
//    objects of different derived classes 
//    using a base class pointer or reference.
//    */
//    Base* b1 = new Derived();
//    b1->ping();


//    Derived derived1;
//    // pointer of Base type that points to derived1
//    Base* base1 = &derived1;
//    // calls member function of Derived class
//    base1->print();

//    return 0;
// }
// #include <iostream>
// using namespace std;
// class Animal {
// public:
//     virtual void sound() {
//         cout << "Animal sound" << endl;
//     }
// };

// class Dog : public Animal {
// public:
//     void sound() override {
//         cout << "Dog barks" << endl;
//     }
// };

// class Cat : public Animal {
// public:
//     void sound() override {
//         cout << "Cat meows" << endl;
//     }
// };

// int main() {
//     Animal* a1 = new Dog();
//     Animal* a2 = new Cat();
    
//     a1->sound();  // Prints "Dog barks"
//     a2->sound();  // Prints "Cat meows"
    
//     return 0;
// }


/*
Encapsulation

-> In normal term encapsulation is defined as
   wrapping up of data and information under a single unit.

Example:
School bag is one of the most real examples of Encapsulation. 
School bag can keep our books, pens, etc. 

Advantages
1. Increased security of data
2. Makes the application easier to understand.

Abstraction

-> Data Abstraction is one of the most essential and important feature of OOP.
-> Abstraction means displays only the relevant attributes of objects 
   and hides the unnecessary details like the background details and implementation.

Abstraction using class :
   we can implement abstraction in c++ using classes. 
   class helps us to group data members and member functions 
   using available access specifiers.

Example:
when we are driving a car, we are only concerned about driving the car 
like start/stop the car, accelerate/ break, etc.

Advantages of Abstraction
1. Helps user to avoid writing the low level code.
2. Avoids code duplication and increases reusability.
3. Helps to increase security of an application or program 
   as only required details are provided to the user.

Friend class and Friend function :
   -> A friend class can access private and protected members of other class 
   in which it is declared as friend.
   -> It is sometimes useful to allow a particular class 
      to access private members of other class.
   -> A friend function or friend class is declared inside a class 
      but is not considered a member of that class(just gets a special access).
*/
// #include<iostream>
// using namespace std;

// class A {
// 	int x;
// public:			
// 	A() {
// 		x = 10;
// 	}
// 	friend class B; //friend class
// };

// class B {
// public:
//    void display(A& t) {
//       cout<<"The value of x = " << t.x;
//    }
// };

// int main() {
// 	A a;

// 	B b;
// 	b.display(a);

// 	return 0;
// }
/*
   Important points about friend functions and classes: 
   1) Friends should be used only for limited purpose.
      It violate the OOP norms. 
   2) Friendship is not mutual. 
      If class B is a friend of A, then A doesn’t become a friend of B automatically.
   3) Friendship is not inherited.
   4) The concept of friends is not there in Java.
*/



/*
In C++, you need the scope resolution operator (::) to access a nested class from outside the outer class 
unless you are inside a member function of the outer class itself. If you're inside the outer class, 
you can directly refer to the nested class without using the scope resolution operator.

Here’s an example demonstrating both approaches and using the new keyword to create an object:

cpp
Copy code
#include <iostream>
using namespace std;

class Outer {
public:
    class Inner { // Nested class
    public:
        void display() {
            cout << "Hello from the Inner class!" << endl;
        }
    };

    // Function inside Outer to access Inner class
    void createInnerObject() {
        Inner* innerObj = new Inner();
        innerObj->display();
        delete innerObj; // Clean up
    }
};

int main() {
    // Accessing using the scope resolution operator
    Outer::Inner* innerObj1 = new Outer::Inner();
    innerObj1->display();
    delete innerObj1; // Clean up

    // Accessing from within a member function of Outer
    Outer outerObj;
    outerObj.createInnerObject();

    return 0;
}
Key Points:
Scope Resolution Operator (::):
When creating the object of the Inner class outside the Outer class, you must use the Outer::Inner syntax.
Direct Access Within the Outer Class:
Inside a member function of the Outer class, you can directly create an Inner object without using the Outer:: prefix.
Output:

javascript
Copy code
Hello from the Inner class!
Hello from the Inner class!
Usage of new:
Objects of the nested class are dynamically allocated using new in both cases. 
Ensure proper cleanup using delete to avoid memory leaks.
*/
