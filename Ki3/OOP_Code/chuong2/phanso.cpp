#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second


class PHANSO{
private:
    int tu, mau;
public:
    void nhap() {
        char bf;
        cin >> tu >> bf >> mau;
    }
    void in() {
        cout << tu << '/' << mau;
    }
    int ucln() {
        int ttu = abs(tu);
        int mmau = abs(mau);

        while (ttu * mmau != 0) 
            if (ttu > mmau) 
                ttu %= mmau;
            else
                mmau %= ttu;
        // cout << "----" << tu + mau << endl;
        return ttu + mmau;
    }
    void toigian() {
        int uc = ucln();
        tu /= uc;
        mau /= uc;
    }
    PHANSO cong(PHANSO p2) {
        PHANSO tg;
        tg.tu = tu * p2.mau + mau * p2.tu;
        tg.mau = mau * p2.mau;
        tg.toigian();
        return tg;
    }
    PHANSO nhan(PHANSO p2) {
        PHANSO tg;
        tg.tu = tu * p2.tu;
        tg.mau = mau * p2.mau;
        tg.toigian();
        tg.in();
        return tg;
    }
    bool smaller(PHANSO p2) {
        PHANSO tg;
        tg.tu = tu * p2.mau;
        tg.mau = mau * p2.mau;

        p2.tu *= mau;
        p2.mau *= mau;
        return (tg.tu < p2.tu);
    }
};

int main() {
    int n; cin >> n;

    PHANSO p[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan so thu " << i + 1 << ": ";
        p[i].nhap();

    }
    cout << "Day phan so vua nhap: " << endl;
    for (int i = 0; i < n; i++)
    {
        p[i].in();
        cout << "   ";
    }
    //! tinh tong
    PHANSO tong = p[0];
    for (int i = 1; i < n; i++)
    {
        tong = tong.cong(p[i]);
    }
    cout << endl << "Tong cua day phan so: "; 
    tong.in();

    // //!tinh tich
    PHANSO tich = p[0];
    for (int i = 1; i < n; i++)
    {
        tich = tich.nhan(p[i]);
    }
    cout << endl << "tich cua day phan so: "; 
    tich.in();

    //! sap xep theo thu tu giam dan
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (p[i].smaller(p[j])) {
                PHANSO tg = p[i];
                p[i] = p[j];
                p[j] = tg;
            }
    cout << endl << "day phan so da sap xep: ";
    for (int i = 0; i < n; i++)
    {
        p[i].in();
    }
    
    
}