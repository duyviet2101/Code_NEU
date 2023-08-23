#include <bits/stdc++.h>
using namespace std;

struct SV
{
    string msv, ht, lop;
    float dtb;
    void nhap() {
        cin >> msv;
    }
};

bool cmp(SV a, SV b) {
    return a.dtb > b.dtb;
}

int main() {
    int n; 
    cout << "Nhap so sinh vien: "; cin >> n;

    SV *a = new SV[n];
    
    for (int i = 0; i < n; i++)
    {
        cout << "Sinh vien thu " << i + 1 << ":" << endl;
        cout << "MSV: "; cin >> (a+i)->msv;
        cin.ignore();
        cout << "Ho ten: "; getline(cin, a[i].ht);
        cout << "Lop: "; getline(cin, a[i].lop);
        cout << "Diem trung binh: "; cin >> a[i].dtb;
        cout << "________________________" << endl;
    }
    sort(a, a + n, cmp);
    cout << "DANH SACH SINH VIEN SAU KHI SAP XEP THEO DIEM TRUNG BINH GIAM DAN: \n" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "MSV: " << a[i].msv << endl;
        cout << "Ho ten: " << a[i].ht << endl;
        cout << "Lop: " << a[i].lop << endl;
        cout << "Diem trung binh: " << a[i].dtb << endl;
        cout << "_________________________" << endl;
    }
    
    cout << "\nDANH SACH SINH VIEN DIEM TRUNG BINH CAO NHAT: \n" << endl;
    float max = a[0].dtb;
    int i = 0;
    while (a[i].dtb == max)
    {
        cout << "MSV: " << a[i].msv << endl;
        cout << "Ho ten: " << a[i].ht << endl;
        cout << "Lop: " << a[i].lop << endl;
        cout << "Diem trung binh: " << a[i].dtb << endl;
        cout << "_________________________" << endl;
        i += 1;
    }
    
    delete a;
}