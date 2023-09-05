#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

#define SIZE 50

class Stack {
    int arrayStack[SIZE];
    int tos;
public:
    Stack() {
        tos = 0;
    }
    ~Stack() {

    }
    bool isEmpty() {
        if (tos == 0)
            return true;
        return false;
    }
    bool isFull() {
        if (tos == SIZE)
            return true;
        return false;
    }
    void push(int x) {
        if (!isFull()) {
            arrayStack[tos++] = x;
        }
        else
            cout << "Stack overflow" << endl;
    }
    int pop() {
        if (tos == 0) 
        {
            cout << "Stack underflow" << endl;
            return NULL;
        }
        else
            return arrayStack[--tos];
    }
    void in() {
        for (int i = 0; i < tos; i++)
        {
            cout << arrayStack[i] << ", ";
        }
    }
};

int main() {
    Stack a;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a.push(x);
    }
    a.pop(); 
    cout << a.isEmpty() << endl;
    cout << a.isFull() << endl;
    a.in();
}