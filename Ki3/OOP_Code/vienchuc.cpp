#include <bits/stdc++.h>
#include <conio.h>

using namespace std;
using ll = long long;
ll a[10000001];
#define fi first
#define se second

class NGUOI {
private:
  string hoten;
protected:
  string maso;
  float luong;
public:
  void nhap() {
    cout << endl << "Nhap ma so (BC: bien che, HD: hop dong): ";
    getline(cin >> ws, maso);
    cout << endl << "Nhap ho ten: ";
    getline(cin >> ws, hoten);
  }
  void in() {
    cout << endl
         << setw(10)<< maso << setw(30) << hoten << setw(15) << fixed << setprecision(2) << luong;
  }
};

class BIENCHE : virtual public NGUOI {
private:
  float hsl, phucap, lcb = 1800000;
public:
  void nhapBC() {
    cout << endl
      << "Nhap he so luong: ";
    cin >> hsl;
    cout << endl
         << "Nhap phu cap: ";
    cin >> phucap;
    luong = hsl * lcb + phucap;
  }
};

class HOPDONG : virtual public NGUOI {
private:
  int ngaycong, tiencong;
  float hsvg;
public: 
  void nhapHD() {
    cout << endl
         << "Ngay ngay cong: ";
    cin >> ngaycong;
    cout << endl
         << "Nhap tien cong: ";
    cin >> tiencong;
    cout << endl
         << "Nhap he so vuot gio: ";
    cin >> hsvg;
    luong = ngaycong <= 26 ? ngaycong * tiencong : (26 + (ngaycong - 26) * hsvg) * tiencong;
  }
};

class VIENCHUC : public BIENCHE, public HOPDONG {
private:
  //! thuoc tinh thong ke:
  static int tsvc;
  static float tsluong;
  static int tsbc;
  static float tsluongbc;
  static int tshd;
  static float tsluonghd;
public:
  VIENCHUC *next;

  VIENCHUC() {
    tsvc++;
  }
  ~VIENCHUC() {
    tsvc--;
    tsluong -= luong;
  }
  void nhapVC() {
    nhap();
    if (maso[0] == 'B' || maso[0] == 'b') {
      nhapBC();
      //! thuoc tinh thong ke
      tsbc ++;
    }
    else {
      nhapHD();
      //! thuoc tinh thong ke
      tshd++;
    }
    tsluong += luong;
  }

  //! toan tu cong, so sanh
  int operator+(VIENCHUC b) {
    return luong + b.luong;
  }
  bool operator>(VIENCHUC b) {
    return luong > b.luong;
  }
  //!end toan tu cong, so sanh

  //! in cac thong so thong ke
  static void in_ts() {
    cout << endl
         << "Tong so vien chuc: " << tsvc
         << endl
         << "Tong so luong vien chuc: " << fixed << setprecision(2) << tsluong
         << endl
         << "Tong so bien che: " << tsbc
         << endl
         << "TOng so luong bien cheL: " << fixed << setprecision(2) << tsluongbc
         << endl
         << "Tong so hop dong: " << tshd
         << endl
         << "Tong so luong hop dong: " << fixed << setprecision(2) << tsluonghd;
  }
  //! end in cac thong so thong ke

  string getMaso() {
    return maso;
  }
};

int VIENCHUC::tsvc = 0;
float VIENCHUC::tsluong = 0;

int VIENCHUC::tshd = 0;
float VIENCHUC::tsluonghd = 0;

int VIENCHUC::tsbc = 0;
float VIENCHUC::tsluongbc = 0;

//! ds lk don
//? thêm viên chức
void insertNode(VIENCHUC *&head, VIENCHUC *&last) {
  VIENCHUC *newVIENCHUC = new VIENCHUC;
  newVIENCHUC->nhapVC();
  newVIENCHUC->next = NULL;
  if (head == NULL) {
    head = newVIENCHUC;
    last = newVIENCHUC;
    return;
  } else 
    last->next = newVIENCHUC;
    last = newVIENCHUC;
  return;
}
//? bớt viên chức
void deleteNode(VIENCHUC *&head, VIENCHUC *&last, string maso) {
  VIENCHUC *p = head;
  if (head == NULL) return;

  if (head == last && head->getMaso() == maso) {
    head = last = NULL;
    delete p;
    return;
  }

  while (p != NULL) {
    if (p->getMaso() == maso) {
      if (p == head) {
        head = p->next;
        delete p;
        return;
      }
      if (p == last) {
        VIENCHUC *tmp = head;
        while (tmp->next != last) tmp = tmp->next;
        last = tmp;
        last->next = NULL;
        delete p;
        return;
      }

      VIENCHUC *tmp = head;
      while (tmp->next != p) tmp = tmp->next;
      tmp->next = p->next;
      delete p;
      return;
    }
    p = p->next;
  }
}

void indslk(VIENCHUC *head) {
  VIENCHUC *p = head;

  if (head == NULL) {
    cout << "Danh sach trong!" << endl;
    return;
  }

  while (p != NULL) {
    p->in();
    p = p->next;
  }
}

void sapxep(VIENCHUC *head) {
  for (VIENCHUC *i = head; i != NULL; i = i->next) {
    for (VIENCHUC *j = i->next; j != NULL; j = j->next) {
      if (!(*i > *j)) {
        //! swap dữ liệu nhưng vẫn cần giữ nguyên con trrỏ next
        VIENCHUC *ptri = i->next;
        VIENCHUC *prtj = j->next;
        VIENCHUC tmp = *j;
        *j = *i;
        *i = tmp;
        i->next = ptri;
        j->next = prtj;
      }
    }
  }
}
//! end ds lk don

int main() {
  VIENCHUC *head = NULL, *last = NULL;
  char tiep = 'c';
  while (tiep == 'c') {
    //! thêm viên chức
    insertNode(head, last);
    cout << endl << "Nhap tiep? (c: tiep)" << endl;
    tiep = getche();
  }
  cout << endl << "DANH SACH VIEN CHUC: ";
  indslk(head);

  cout << endl << "Sau sap xep: ";
  sapxep(head);
  indslk(head);

  //! tìm bc lương max, hd lương max
  VIENCHUC *bcmax = NULL, *hdmax = NULL, *p = head;
  while (p != NULL) {
    if (tolower(p->getMaso()[0]) == 'b') {
      bcmax = p;
      break;
    }
    p = p->next;
  }
  p = head;
  while (p != NULL) {
    if (tolower(p->getMaso()[0]) == 'h') {
      hdmax = p;
      break;
    }
    p = p->next;
  }
  cout << endl << "Bien che luong cao nhat: ";
  if (bcmax != NULL) bcmax->in(); else cout << "NULL";
  cout << endl << "Hop dong luong cao nhat: ";
  if (hdmax != NULL) hdmax->in(); else cout << "NULL";
  //! end tìm bc lương max, hd lương max

  //! xoá viên chức bằng maso
  string masoDelete; 
  cout << endl << "Nhap ma so can xoa: "; getline(cin >> ws, masoDelete);
  deleteNode(head, last, masoDelete);
  cout << endl << "Sau khi xoa: ";
  indslk(head);
  //! end xoá viên chức bằng maso
}