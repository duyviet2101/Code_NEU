#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

class HoaDon {
    string sohoadon, tenhang;
    int tienban;
public:
    friend istream& operator >> (istream& in, HoaDon &a) {
        cout << "Nhap so hoa don: ";
        getline(in >> ws, a.sohoadon);
        cout << "Nhap ten hang: ";
        getline(in >> ws, a.tenhang);
        cout << "Nhap tien ban: ";
        in >> a.tienban;
        return in;
    }

    friend ostream& operator << (ostream& out, HoaDon a) {
        out << "So hoa don: " << a.sohoadon << endl;
        out << "Ten hang: " << a.tenhang << endl;
        out << "Tien ban: " << a.tienban << endl;
        return out;
    }

    friend bool operator > (HoaDon a, HoaDon b) {
        return a.tienban > b.tienban;
    }

    int getTienban() {
        return tienban;
    }
};

int main() {
    int n;
    cout << "Nhap so hoa don: "; cin >> n;
    HoaDon *a = new HoaDon[n];
    for (int i = 0; i < n; i++)
    {
        cout << endl << "Hoa don thu " << i + 1 << " :" << endl;
        cin >> a[i];
    }
    sort(a, a + n, greater<HoaDon>());
    cout << endl << "--------------------------------------------------" << endl;
    cout << "Danh sach hoa don sap xep theo tien ban giam dan: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    
    cout << endl << "--------------------------------------------------" << endl;
    cout << "Tong so hoa don: " << n << endl;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i].getTienban();
    }
    cout << "Tong so tien ban: " << sum << endl;
    
}