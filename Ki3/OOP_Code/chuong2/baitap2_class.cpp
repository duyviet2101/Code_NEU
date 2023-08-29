#include <bits/stdc++.h>
using namespace std;

class SV
{
private:
    string msv, ht, lop;
    float dtb;

public:
    void nhap();
    void in()
    {
        cout << "MSV: " << msv << endl;
        cout << "Ho ten: " << ht << endl;
        cout << "Lop: " << lop << endl;
        cout << "Diem trung binh: " << dtb << endl;
    }
    float getDtb() {
        return dtb;
    }
};

void SV::nhap()
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


bool cmp(SV a, SV b)
{
    return a.getDtb() > b.getDtb();
}

int main()
{
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    //! New
    SV *a = new SV[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Sinh vien thu " << i + 1 << ":" << endl;
        a[i].nhap();
        cout << "________________________" << endl;
    }
    

    sort(a, a + n, cmp);
    cout << "DANH SACH SINH VIEN SAU KHI SAP XEP THEO DIEM TRUNG BINH GIAM DAN: \n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        a[i].in();
        cout << "________________________" << endl;
    }

    cout << "\nDANH SACH SINH VIEN DIEM TRUNG BINH CAO NHAT: \n"
         << endl;
    float max = a[0].getDtb();
    int i = 0;
    while (a[i].getDtb() == max)
    {
        a[i].in();
        cout << "_________________________" << endl;
        i += 1;
    }
    //! delete
    delete a;
}