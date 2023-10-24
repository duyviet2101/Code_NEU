#include <bits/stdc++.h>
using namespace std;

class Nguoi
{
  protected:
  string maso, hoten;
  int luong;
  static int ts;

  public:
  void nhap() {
    cout << "Nhap ma so: "; cin >> maso;
    cout << "Nhap ho ten: "; getline(cin >> ws, hoten);
  }
  void in() {
    cout << "Ma so: " << maso << endl;
    cout << "Ho ten: " << hoten << endl;
  }
};

class Bienche : virtual public Nguoi //! đảm bảo chỉ có một lớp Nguoi được kế thừa nếu có lớp khác kết thừa Bienche 
{
  protected:
  int luongcoban, phucap;
  float hesoluong;

  public:
  void nhap() {
    cout << "Nhap luong co ban: "; cin >> luongcoban;
    cout << "Nhap he so luong: "; cin >> hesoluong;
    cout << "Nhap tien phu cap chuc vu: "; cin >> phucap;

    luong = luongcoban * hesoluong + phucap;
  }
  void in() {
    cout << "Luong co ban: " << luongcoban << endl;
    cout << "He so luong: " << hesoluong << endl;
    cout << "Phu cap chuc vu: " << phucap << endl;
    cout << "Luong: " << luong << endl;
  }
};

class Hopdong : virtual public Nguoi //! đảm bảo chỉ có một lớp Nguoi được kế thừa nếu có lớp khác kết thừa Hopdong
{
  protected:
  int tiencong, songaylam;
  float hesovuotgio;

  public:
  void nhap() {
    cout << "Nhap tien cong lao dong: "; cin >> tiencong;
    cout << "Nhap so ngay lam viec trong thang: "; cin >> songaylam;
    cout << "Nhap he so vuot gio: "; cin >> hesovuotgio;

    luong = songaylam < 26 ? tiencong * songaylam : tiencong * (26 + hesovuotgio * (songaylam - 26)); 
  }
  void in() {
    cout << "Tien cong lao dong: " << tiencong << endl;
    cout << "So ngay lam viec trong thang: " << songaylam << endl;
    cout << "He so vuot gio: " << hesovuotgio << endl;
    cout << "Luong: " << luong << endl;
  }
};

class Nhanvien : public Bienche, Hopdong { //! Lúc này chỉ có một lớp người được kế thừa bởi Nhanvien, không gây lỗi nhờ virtual ở Bienche và Hopdong
  public:
  void nhap() {
    Nguoi::nhap();
    if (maso[0] == 'b') 
      Bienche::nhap();
    else 
      Hopdong::nhap();
  }
  void in() {
    Nguoi::in();
    if (maso[0] == 'b') 
      Bienche::in();
    else 
      Hopdong::in();
  }
  int getLuong() {
    return luong;
  }
  char getMaso() {
    return maso[0];
  }
};

int main()
{
  int n;
  cout << "Nhap so nhan vien: "; cin >> n;
  Nhanvien *nv = new Nhanvien[n];

  for (int i = 0; i < n; i++) {
    cout << "Nhap thong tin nhan vien thu " << i + 1 << endl;
    nv[i].nhap();
    cout << endl;
  }
  cout << endl << "---------------------------------" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "Thong tin nhan vien thu " << i + 1 << endl;
    nv[i].in();
    cout << endl;
  }
  
}