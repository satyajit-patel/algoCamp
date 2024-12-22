#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

/*
  Create a class "BankAccount" with attributes account number and balance. 
  Implement methods to deposit and withdraw funds, 
  and a display method to show the account details.
*/
class BankAccount {
  string accNum;
  double balance;
public:
  BankAccount(string accNum, double balance) {
    this->accNum = accNum;
    this->balance = balance;
  }

  void deposite(double balance) {
    this->balance += balance;
  }

  void withdraw(double balance) {
    if(this->balance >= balance) {
      this->balance -= balance;
    } else {
      cout << "Insufficient Balance!!\n\n";
    }
  }

  void print() {
    cout << "Acc Number: " << this->accNum << endl;
    cout << "Balance: " << fixed << this->balance << setprecision(2) << "\n\n";
  }
};

void solve() {
  BankAccount b1("123456789", 1000);
  b1.deposite(500);
  b1.withdraw(200);
  b1.print();

  BankAccount b2("123456798", 1000);
  b2.deposite(500);
  b2.withdraw(200.10);
  b2.print();
  b2.withdraw(5000);
}

signed main() {
  solve();
  return 0;
}
