#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int nst = 20;

class Stack {
  int s[nst];
  int t;
public:
  Stack() {
    t = -1;
  };
  
  ~Stack() {};
  
  bool isEmpty() {
    if (t < 0) 
      return true;
    return false;
  }

  bool isFull() {
    if (t == nst) 
      return true;
    return false;
  }

  void push(int x) {
    if (isFull()) 
    {
      cout << "Stack overflow" << endl;
      return;
    }

    t++;
    s[t] = x;
    return;
  }

  int pop() {
    if (isEmpty())
    {
      cout << "Stack is empty" << endl;
      return NULL;
    }

    t--;
    return s[t + 1];
  }

  void in() {
    cout << endl << "noi dung stack: " << endl;
    while (!isEmpty()) {
      cout << setw(2) << pop();
    }
  }
};

class i2b : public Stack {
  int i;
  public:
  void nhap() {
    cout << "Nhap i: "; cin >> i;
  };
  void i2b_i() {
    int bf = i;
    while (bf != 0) {
      push(bf % 2);
      bf /= 2;
    }
  }
};

int main() {
  i2b a;
  a.nhap();
  a.i2b_i();
  a.in();
}