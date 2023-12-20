#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

class Phong {
protected:
  string ma_phong, ten_phong;
  float don_gia;
public:
  static int tsdt;
  Phong() {
    tsdt++;
  }
  ~Phong() {
    tsdt--;
    cout << "Huy doi tuong" << endl;
  }
  void Nhap() {
    cout << "Nhap ma phong (DB: dac biet, T: Thuong): ";
    fflush(stdin); getline(cin, ma_phong);

    cout << "Nhap ten phong: "; 
    fflush(stdin); getline(cin, ten_phong);
  }
  bool operator>(Phong tmp) {
    tsdt++;
    return don_gia < tmp.don_gia;
  }
};
int Phong::tsdt = 0;

class Phong_dac_biet : virtual public Phong {
protected:
  float vi_tri, chi_so_phuc_vu, gia_co_ban;
public:
  void Nhap_dac_biet() {
    cout << "Nhap vi tri: "; cin >> vi_tri;
    cout << "Nhap chi so phuc vu: "; cin >> chi_so_phuc_vu;
    cout << "Nhap gia co ban: "; cin >> gia_co_ban;
    don_gia = (vi_tri + chi_so_phuc_vu) * gia_co_ban;
  }
};

class Phong_thuong : virtual public Phong {
protected:
  float he_so_phong, gia_co_ban;
public:
  void Nhap_thuong() {
    cout << "Nhap he so phong: "; cin >> he_so_phong;
    cout << "Nhap gia co ban: "; cin >> gia_co_ban;
    don_gia = he_so_phong * gia_co_ban;
  }
};

class thue_phong : public Phong_dac_biet, public Phong_thuong {
public:
  thue_phong *next;
  void Nhap_thue_phong() {
    Nhap();
    if (ma_phong[0] == 'D' || ma_phong[0] == 'd') Nhap_dac_biet();
    else Nhap_thuong();
  }

  friend void sapxep(thue_phong *list) {
    // thue_phong *i = list;
    // thue_phong *j = NULL;

    for (thue_phong *i = list; i != NULL; i = i->next) {
      for (thue_phong *j = i->next; j != NULL; j = j->next) {
        if (i->don_gia > j->don_gia) {
          thue_phong tg;
          
          tg.ma_phong = i->ma_phong;
          i->ma_phong = j->ma_phong;
          j->ma_phong = tg.ma_phong;
          
          tg.ten_phong = i->ten_phong;
          i->ten_phong = j->ten_phong;
          j->ten_phong = tg.ten_phong;
          
          tg.don_gia = i->don_gia;
          i->don_gia = j->don_gia;
          j->don_gia = tg.don_gia;
        }
      }
    }
  }

  friend void In(thue_phong *list) {
    thue_phong *p = list;
    for (int i = 0; i < tsdt; i++, p = p->next)
    {
      cout << "|" << setw(3) << i + 1 << "|" << setw(9) << p->ma_phong << "|" << setw(29) << p->ten_phong << "|" << setw(15) << p->don_gia << "|" << endl;
      cout << "-------------------------------------------------------------" << endl;
    }
  }
};

int main () {
  thue_phong *list = NULL, *last = NULL, *node = NULL;
  char tiep = 'c';
  while (tiep == 'c') {
    node = new thue_phong;
    node->Nhap_thue_phong();
    node->next = NULL;

    if (list == NULL) {
      list = last = node;
    } else {
      last->next = node;
      last = node;
    }

    cout << "Nhap tiep (c = tiep): ";
    tiep = getch();
    cout << endl;
  }

  sapxep(list);

  cout << "=============================================================" << endl;
  cout << "|" << setw(3) << "STT" << "|" << setw(9) << "Ma Phong" << "|" << setw(29) << "Ten phong" << "|" << setw(15) << fixed << setprecision(0) << "Don gia" << "|" << endl;
  cout << "=============================================================" << endl;
  In(list);

  cout << "Tong so phong: " << thue_phong::tsdt << endl;
}