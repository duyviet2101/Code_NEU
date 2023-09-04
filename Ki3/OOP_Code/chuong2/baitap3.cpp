#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

class String {
    string s;
    int length;
public:
    String() {

    }

    void nhap() {
        cout << endl << "Nhap chuoi: ";
        getline(cin, s);
        length = s.length();
    }

    void print() {
        cout << "Chuoi co gia tri: " << s << endl;
    }

    char character(int i) {
        if (i >= 0 && i < length)
            return s[i];
        return NULL;
    }

};

int main() {
    String s;
    s.nhap();
    s.print();

    cout << "Nhap i: ";
    int i; cin >> i;
    cout << endl << "Ki tu thu i (0<= i < length): " << s.character(i) << endl;
}