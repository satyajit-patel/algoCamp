#include <iostream>
using namespace std;

class maruti {
private:
  int mileage;
  string companyName;
  string carName;
public:
  maruti(int mileage, string carName, string companyName) {
    cout<<"Memory Created\n";
    this->mileage = mileage;
    this->carName = carName;
    this->companyName = companyName;
  }
  ~maruti() {
    cout<<"Memory Destroyed\n";
    // this gets called by te end of the scope
    // but this is a bdefault call in Stack
    // but in Heap we have to call manually using "delete" 
    // like delete object_name
  }

  void showDetails() {
    cout<<"companyName = "<<companyName<<endl;
    cout<<"carName = "<<carName<<endl;
    cout<<"mileage = "<<mileage<<endl;
  }
  
  int sum(int a, int b) {
      return a + b;
  }
  int sum(int a, string b) {
      int nb = stoi(b);
      return a + nb;
  }
  
  int getMileage() {
      return this->mileage;
  }
  
  void operator+(maruti& a2) {
      int n1 = this->mileage;
    //   int n2 = a2.mileage; // this is also correct
    int n2 = a2.getMileage();
      cout<<n1 - n2<<endl;
  }
};

int main() {
  maruti a1(25, "Dezire", "Maruri_Suzuki");
  a1.showDetails();
  
  maruti* a2 = new maruti(25, "Swift", "Maruri_Suzuki");
  a2->showDetails();
  delete a2;
  
  // in function overloading
  // only change in fun name and parametre, not return type
  cout<<a1.sum(5, 2)<<endl;
  cout<<a1.sum(5, "20")<<endl;
  
  // operator overloading (operation between 2 objects)
  maruti a3(5, "Swift2", "Maruri_Suzuki");
  a1 + a3;
  
  return 0;
}