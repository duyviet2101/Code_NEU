#include <bits/stdc++.h>
using namespace std;

struct SV
{
    string msv, ht, lop;
    float dtb;
    void nhap()
    {
        cout << "MSV: ";
        cin >> msv;
        cin.ignore();
        cout << "Ho ten: ";
        getline(cin, ht);
        cout << "Lop: ";
        getline(cin, lop);
        cout << "Diem trung binh: ";
        cin >> dtb;
    }
};

void in(SV *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "MSV: " << a[i].msv << endl;
        cout << "Ho ten: " << a[i].ht << endl;
        cout << "Lop: " << a[i].lop << endl;
        cout << "Diem trung binh: " << a[i].dtb << endl;
        cout << "_________________________" << endl;
    }
}

void nhap(SV *a, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << "Sinh vien thu " << i + 1 << ":" << endl;
        a[i].nhap();
        cout << "________________________" << endl;
    }
}

bool cmp(SV a, SV b)
{
    return a.dtb > b.dtb;
}

int main()
{
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    //! New
    SV *a = new SV[n];
    nhap(a, n);

    sort(a, a + n, cmp);
    cout << "DANH SACH SINH VIEN SAU KHI SAP XEP THEO DIEM TRUNG BINH GIAM DAN: \n"
         << endl;
    in(a, n);

    cout << "\nDANH SACH SINH VIEN DIEM TRUNG BINH CAO NHAT: \n"
         << endl;
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
    //! delete
    delete a;
}