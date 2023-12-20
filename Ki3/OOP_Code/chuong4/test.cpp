#include <bits/stdc++.h>
using namespace std;

class Father {
  
  public:
  // static int cnt;
  virtual void area() {
    cout << "This is father" << endl;
  }
};

class Son: public Father {
  public: 
  void area() {
    cout << "This is Son!" << endl;
  }
};

class Daughter: public Father {
  public:
  void area() {
    cout << "THis is daughter" << endl;
  }
};

// int Father::cnt = 0;

int main() {
  Father *fa;
  Son son;
  Daughter dau;
  // cout << Father::cnt << endl;
  fa = &son;
  fa->area();
  fa = &dau;
  fa->area();
  return 0;
}