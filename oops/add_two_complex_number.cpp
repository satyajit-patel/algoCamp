#include <bits/stdc++.h>
#include <ostream>
using namespace std;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

class Complex {
  int real;
  int img;
public:
  Complex() {

  }
  Complex(int real, int img) {
    this->real = real;
    this->img = img;
  }

  void print() {
    cout << this->real << " + " << this->img << "i\n";
  }

  Complex* add(Complex* c1, Complex* c2) {
    Complex* ans = new Complex();
    ans->real = c1->real + c2->real;
    ans->img = c1->img + c2->img;
    return ans;
  }

  Complex* operator+(Complex* c) {
    /*
      The operator+ function should only take a single argument 
      because "this" implicitly refers to the left operand.
    */
    Complex* ans = new Complex();
    ans->real = this->real + c->real;
    ans->img = this->img + c->img;
    return ans;
  }
};

void solve() {
  Complex* c1 = new Complex(4, 4);
  c1->print();
  Complex* c2 = new Complex(6, 6);
  c2->print();

  Complex* ans = c1->add(c1, c2);
  ans->print();

  // Bad Practice
  // Complex* ans = new Complex();
  // ans = ans->add(c1, c2);
  // ans->print();
  // why
  /*
  Explanation:
  Step 1: Complex* ans = new Complex();

  You allocate memory for a new Complex object on the heap and 
  store its pointer in ans.
  So, ans initially points to a newly created (empty) Complex object.
  Step 2: ans = ans->add(c1, c2);

  Now, you call ans->add(c1, c2). 
  The add function creates another Complex object, 
  also on the heap, and returns a pointer to this new object.
  After the call, ans is reassigned to point to the result of add(c1, c2).
  Memory Leak: The original Complex object created in Step 1 
  is no longer accessible, which results in a memory leak because 
  that memory was allocated but never freed.
  Step 3: ans->print();

  The result of the addition is printed correctly, 
  but the first Complex object created in Step 1 is lost.
  
  The Problem:
  In the line ans = ans->add(c1, c2);,
  you're effectively discarding the original memory allocated in Step 1. 
  This leads to a memory leak because that memory is no longer accessible 
  but hasn't been deallocated with delete.
  */

  // using operator overloading
  // allows you to add 2 complex dta using + operator directly
  Complex* res = *c1 + c2;
  /*
    The expression *c1 + c2 .
    c1 uses pointer dereferencing to access the object c1 is pointing to, 
    but c2 is passed directly as a pointer.

    Dereferencing a Pointer (*c1): 
    When you have a pointer (c1), it holds the memory address of an object. 
    To access the actual object that the pointer is pointing to, 
    you need to dereference the pointer using *.
  */
  res->print();
}

signed main() {
  solve();
  return 0;
}



/* 
One should use references rather than pointers when overloading operators, 
as it simplifies memory management and memory allocated in stack area is
fast and auto flushed 
*/
// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define int long long
// #define vi vector<int>
// #define vvi vector<vector<int>>

// class Complex {
//   int real;
//   int img;
// public:
//   Complex() {}

//   Complex(int real, int img) {
//     this->real = real;
//     this->img = img;
//   }

//   void print() {
//     cout << this->real << " + " << this->img << "i\n";
//   }

//   // Addition using method
//   Complex add(const Complex& c) {
//     Complex ans;
//     ans.real = this->real + c.real;
//     ans.img = this->img + c.img;
//     return ans;
//   }

//   // Operator overloading for +
//   Complex operator+(const Complex& c) {
//     Complex ans;
//     ans.real = this->real + c.real;
//     ans.img = this->img + c.img;
//     return ans;
//   }
// };

// void solve() {
//   Complex c1(4, 4);
//   c1.print();

//   Complex c2(6, 6);
//   c2.print();

//   // Using add method
//   Complex ans = c1.add(c2);
//   ans.print();

//   // Using operator overloading
//   Complex res = c1 + c2;
//   res.print();
// }

// signed main() {
//   solve();
//   return 0;
// }


// BUT
/*
  if you want manual control then go ahead with pointer(heap area)
  pros:
    => larger memory size than stack
    => allocate deallocate memory as needed
  cons:
    => every new should have a corresponding delete. 
      Failing to free memory leads to memory leaks.
    => slower compared to stack memory for small objects
*/
// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define int long long
// #define vi vector<int>
// #define vvi vector<vector<int>>

// class Complex {
//   int real;
//   int img;
// public:
//   Complex() {}

//   Complex(int real, int img) {
//     this->real = real;
//     this->img = img;
//   }

//   void print() {
//     cout << this->real << " + " << this->img << "i\n";
//   }

//   Complex* add(Complex* c) {
//     Complex* ans = new Complex();
//     ans->real = this->real + c->real;
//     ans->img = this->img + c->img;
//     return ans;
//   }

//   Complex* operator+(Complex* c) {
//     Complex* ans = new Complex();
//     ans->real = this->real + c->real;
//     ans->img = this->img + c->img;
//     return ans;
//   }

//   ~Complex() {
//     /*
//       => Handles object-specific cleanup (e.g., closing files).
//       => The destructor is called automatically 
//       when an object goes out of scope (for stack-allocated objects) 
//       or 
//       when delete is called (for heap-allocated objects).
//     */
//     cout << "Destructor called, cleaning up!" << endl;
//   }
// };

// void solve() {
//   Complex* c1 = new Complex(4, 4);
//   c1->print();
  
//   Complex* c2 = new Complex(6, 6);
//   c2->print();

//   Complex* ans = c1->add(c2);
//   ans->print();

//   Complex* res = *c1 + c2;
//   res->print();

//   // Free allocated memory
//   delete c1;
//   delete c2;
//   delete ans;
//   delete res;
// }

// signed main() {
//   solve();
//   return 0;
// }



// #include <iostream>
// using namespace std;

// class Complex {
// public:
//     Complex() {
//         cout << "Constructor called!" << endl;
//     }

//     ~Complex() { // Destructor
//         cout << "Destructor called, cleaning up!" << endl;
//     }
// };

// int main() {
//     Complex* c = new Complex();  // Allocates memory on heap
//     delete c;  // Calls destructor, then frees memory

//     // For stack-allocated objects, destructor is called automatically.
//     Complex c2;  
//     // Destructor will be called automatically when `c2` goes out of scope
//     return 0;
// }



