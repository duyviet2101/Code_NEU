#include <bits/stdc++.h>
using namespace std;

class KHACHHANG {
  string makh, tenkh;
  int TSD;
public:
//! nhap thong tin khach hang
  void nhap() {
    cout << "Nhap ma khach hang: "; cin >> makh;
    cout << "Nhap ten khach hang: "; getline(cin >> ws, tenkh);
    cout << "Nhap tong so du: "; cin >> TSD;
  }
//! in thong tin khach hang
  void in() {
    cout << "Ma khach hang: " << makh << endl;
    cout << "Ten khach hang: " << tenkh << endl;
    cout << "Tong so du: " << TSD << endl;
  }
//! toan tu so sanh
  bool operator > (KHACHHANG k2) {
    return TSD > k2.TSD;
  }
//! get TSD
  int getTSD() { return TSD; }

};

void nhapDanhSach(KHACHHANG *a, int n) {
  cout << endl << "Nhap danh sach khach hang: " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "Khach hang thu " << i + 1 << " :" << endl;
    a[i].nhap();
    cout <<endl;
  }
}

void inDanhSach(KHACHHANG *a, int n) {
  for (int i = 0; i < n; i++)
  {
    a[i].in();
    cout <<endl;
  }
}

int main() {
  int n; 
  cout << "Nhap so luong khach hang: "; cin >> n;
  KHACHHANG *a = new KHACHHANG[n];
  nhapDanhSach(a, n);
  //! sap xep danh sach giam dan theo TSD
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1 ; j < n ; j++)
        if (!(a[i] > a[j]))
        {
          KHACHHANG temp = a[i];
          a[i] = a[j];
          a[j] = temp;
        }
  cout << endl << "-------------------------------" << endl;
  cout << endl << "Danh sach khach hang sau khi sap xep: " << endl << endl;
  inDanhSach(a, n);

  //! danh sach khach hang co tong so du lon nhat
  cout << endl << "-------------------------------" << endl;
  int i = 0;
  cout << endl << "Danh sach khach hang co TSD lon nhat: " << endl;
  a[i].in();
  while (a[i].getTSD() == a[i + 1].getTSD())
  {
    i++;
    a[i].in();
    cout <<endl;
  }
  
  //! tong so khach hang va tong so du
  cout << endl << "-------------------------------" << endl;
  cout << "Tong so khach hang: " << n << endl;
  int sumTSD = 0;
  for (int i = 0; i < n; i++)
  {
    sumTSD += a[i].getTSD();
  }
  cout << "Tong so du: " << sumTSD << endl;
  cout << endl << "-------------------------------" << endl;
  return 0;

}