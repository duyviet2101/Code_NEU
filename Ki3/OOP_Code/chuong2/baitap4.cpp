#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

class SinhVien {
    string hoten, ns;
    double diem[9];
    bool thilai[9] = {false};
public:
    friend istream& operator >> (istream& in, SinhVien &a) {
        cout << "Nhap ho ten SV: ";
        getline(in >> ws, a.hoten);
        cout << "Nhap nam sinh cua SV: ";
        in >> a.ns;
        cout << "Nhap lan luot diem thi 9 mon cua SV: ";
        for (int i = 0; i < 9; i++) {
            in >> a.diem[i];
            if (a.diem[i] < 5)
                a.thilai[i] = true;
        }
        return in;
    }
    double getDtb() {
        double res = 0;
        for (int i = 0; i < 9; i++)
        {
            res += diem[i];
        }
        return res / 9;
    }
    bool checkThilai() {
        for (int i = 0; i < 9; i++)
        {
            if (thilai[i] == true)
                return true;
        }
        return false;
    }
    int ketqua() {
        if (getDtb() >= 7 && checkThilai() == false)
            return 1;
        if (getDtb() < 7 && checkThilai() == false)
            return 2;
        return 3;
    }
    void getThilai() {
        cout << hoten << " - " << ns << " - Thi lai mon: ";
        for (int i = 0; i < 9; i++)
        {
            if (thilai[i] == true) {
                cout << i << ",";
            }
        }
    }
};

int main() {
    int n;
    cout << "Nhap so sinh vien quan ly: "; cin >> n;
    SinhVien a[n];

    int khoaLuan = 0, thiTotNghiep = 0, thiLai = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap sinh vien thu " << i + 1 << " :" << endl;
        cin >> a[i];
        if (a[i].ketqua() == 1) khoaLuan += 1;
        else if (a[i].ketqua() == 2) thiTotNghiep += 1;
        else thiLai += 1;
    }
    cout << "Khoa luan: " << khoaLuan << endl;
    cout << "Thi tot nghiep: " << thiTotNghiep << endl;

    cout << "Thi lai: " << thiLai << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i].checkThilai())
            a[i].getThilai();
    }
    
}