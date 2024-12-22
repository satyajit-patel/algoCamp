#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

/*
  function overloading: 
    only change in parametre not in return type
  operator overloading: 
    this refers left object, parametre refers right object
*/
int sum(int x, int y) {
  cout << "int + int \n";
  return x + y;
}

int sum(int x, string y) {
  cout << "int + string \n";
  return x + stoi(y);
}

int sum(int x, int y, int z) {
  cout << "int + int + int \n"; 
  return x + y + z;
}

class Car {
  int mileage;
  string carName;
  string companyName;
public:
  Car(int mileage, string carName, string companyName) {
    this->mileage = mileage;
    this->carName = carName;
    this->companyName = companyName; 
  }

  void print() {
    cout << endl;
    cout << "Company Name: " << this->companyName << endl;
    cout << "Car Name: " << this->carName << endl;
    cout << "Mileage: " << this->mileage << endl;
    cout << endl;
  }

  Car operator +(const Car& c) {
    Car hybrid(this->mileage + c.mileage, c.carName + this->carName, "Maruti");
    return hybrid;
  }
};

void solve() {
  cout << sum(4, 6) << endl;
  cout << sum(4, "6") << endl;
  cout << sum(4, 4, 2) << endl;

  Car c1(25, "Dezire", "Maruti");
  c1.print();

  Car c2(25, "Swift", "Maruti");
  c2.print();

  Car hybrid = c1 + c2;
  hybrid.print();
}

signed main() {
  solve();
  return 0;
}
