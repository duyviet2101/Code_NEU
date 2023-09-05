#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

class PHANSO {
    int tu, mau;
public:
    PHANSO () {

    }
    void nhap() {
        do
        {
            cout << "Nhap tu so: "; cin >> tu;
            cout << "Nhap mau so: "; cin >> mau;
            if (mau == 0) cout << "Mau so khong hop le, nhap lai phan so: " << endl;
        } while (mau == 0);
        //! toi gian ngay sau khi nhap phan so
        toigian();
    }
    void in() {
        cout << tu << "/" << mau;
    }
    void toigian() {
        int ucln = gcd(tu, mau);
        tu /= ucln;
        mau /= ucln;
        if (mau * tu < 0 && mau < 0) {
            mau *= -1;
            tu *= -1;
        }
    }
    //!nap chong toan tu cong
    friend PHANSO operator + (PHANSO a, PHANSO b) {
        PHANSO res;
        res.mau = a.mau * b.mau;
        res.tu = a.tu * b.mau + b.tu * a.mau;
        res.toigian();
        return res;
    } 
    //!nap chong toan tu tru
    friend PHANSO operator - (PHANSO a, PHANSO b) {
        PHANSO res;
        res.mau = a.mau * b.mau;
        res.tu = a.tu * b.mau - b.tu * a.mau;
        res.toigian();
        return res;
    }
    //! nap chong toan tu nhan
    friend PHANSO operator * (PHANSO a, PHANSO b) {
        PHANSO res;
        res.mau = a.mau * b.mau;
        res.tu = a.tu * b.tu;
        res.toigian();
        return res;
    } 
    //!nap chong toan tu chia
    friend PHANSO operator / (PHANSO a, PHANSO b) {
        PHANSO res;
        res.mau = a.mau * b.tu;
        res.tu = a.tu * b.mau;
        res.toigian();
        return res;
    } 

    //! nap chong toan tu so sanh nho hon
    friend bool operator < (PHANSO a, PHANSO b) {
        //!quy dong 2 phan so
        PHANSO tmp = a;
        a.mau *= b.mau;
        a.tu *= b.mau;

        b.mau *= tmp.mau;
        b.tu *= tmp.mau;

        //! so sanh tu so de tra ve ket qua so sanh 2 phan so
        return a.tu < b.tu;

    }
};

int main() {
    int n;
    cout << "Nhap so luong phan so: "; cin >> n;
    PHANSO a[n];

    //!nhap day phan so
    cout << "Nhap gia tri cac phan so: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << endl << "Phan so thu " << i + 1 << ": " << endl;
        a[i].nhap();
    }
    cout << "_________________________________________" << endl;

    //!In day phan so
    cout << endl << "Day phan so da nhap, sau khi rut gon la: " << endl;
    for (int i = 0; i < n; i++)
    {
        a[i].in();
        cout << ", ";
    }
    cout << endl << "_________________________________________" << endl;

    //!tinh tong day phan so
    cout << "Tong day phan so da nhap la: ";
    PHANSO sum = a[0];
    for (int i = 1; i < n; i++)
    {
        sum = sum + a[i];
    }
    sum.in();
    cout << endl << "_________________________________________" << endl;

    //! tinh tich day phan so
    cout << "Tich day phan so da nhap la: ";
    PHANSO pro = a[0];
    for (int i = 1; i < n; i++)
    {
        pro = pro * a[i];
    }
    pro.in();
    cout << endl << "_________________________________________" << endl;

    //!phan so co gia tri lon nhat
    cout << "Phan so co gia tri lon nhat la: ";
    PHANSO max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (max < a[i])
            max = a[i];
    }
    max.in();
    
}