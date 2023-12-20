#include <bits/stdc++.h>
#include <conio.h>
using namespace std;


class GIANGVIEN {
protected:
	string ma_so, ho_ten;
	int gio_nghien_cuu;
public:
	// cau 2
	static int ts;
	//cau 1
	GIANGVIEN() {
		ts++;
	}		
	~GIANGVIEN() {
		ts--;
	}
	void nhap_giangvien() {
		cout << "Nhap ma so: "; cin >> ma_so;
		cout << "Nhap ho ten: "; getline(cin >> ws, ho_ten);
	}
	//cau 3
	bool operator>(GIANGVIEN tmp) {
		ts++; //! sau khi hàm nạp chồng chạy xong, nó sẽ huỷ biến GIANGVIEN tmp dẫn đến ts bị giảm đi 1, ảnh hưởng đến ts chung nên cần cộng ts lên 1 trước để bù lại.
		return gio_nghien_cuu > tmp.gio_nghien_cuu;
	}
};
// cau 2
int GIANGVIEN::ts = 0;

//cau 4
class Giang_vien_co_huu : virtual public GIANGVIEN {
protected:
	int so_bai_bao, huong_dan_nghien_cuu, gio_bai_bao;
	double he_so_nghien_cuu;
public:
	void nhap_giangviencohuu() {
		cout << "Nhap so bai bao: "; cin >> so_bai_bao;
		cout << "Nhap gio bai bao: "; cin >> gio_bai_bao;
		cout << "Nhap huong dan nghien cuu: "; cin >> huong_dan_nghien_cuu;
		cout << "Nhap he so nghien cuu: "; cin >> he_so_nghien_cuu;
		gio_nghien_cuu = so_bai_bao * gio_bai_bao + huong_dan_nghien_cuu * he_so_nghien_cuu;
	}
};
class Giang_vien_kiem_giang :virtual public GIANGVIEN {
protected:
	int so_bai_bao, gio_bai_bao, giokiemgiang;
public:
	void nhap_giangvienkiemgiang() {
		cout << "Nhap so bai bao: "; cin >> so_bai_bao;
		cout << "Nhap gio bai bao: "; cin >> gio_bai_bao;
		cout << "Nhap gio kiem giang: "; cin >> giokiemgiang;
		gio_nghien_cuu = so_bai_bao * gio_bai_bao + giokiemgiang;
	}
};

//cau5
class Giang_day : public Giang_vien_co_huu, public Giang_vien_kiem_giang {
public:
	Giang_day* next;
	void nhap_giangday() {
		nhap_giangvien();
		if (ma_so[0] == 'c') nhap_giangviencohuu();
		else nhap_giangvienkiemgiang();
	}

	static void sapxep(Giang_day *list) {
		Giang_day *i = list;
		Giang_day *j;
		while (i != NULL) {
			j = i->next;
			while (j != NULL) {
				if (!((*i) > (*j))) {
					Giang_day tg;
					tg.gio_nghien_cuu = i->gio_nghien_cuu; i->gio_nghien_cuu = j->gio_nghien_cuu; j->gio_nghien_cuu = tg.gio_nghien_cuu;
					tg.ho_ten = i->ho_ten; i->ho_ten = j->ho_ten; j->ho_ten = tg.ho_ten;
					tg.ma_so = i->ma_so; i->ma_so= j->ma_so; j->ma_so = tg.ma_so;
				}
				j = j->next;
			}
			i = i->next;
		}
	}
	static void in(Giang_day *list) {
		Giang_day *p = list;
		for	(int i = 1; i <= ts; i++) {
			cout << "|" << setw(3) << i << "|" << setw(9) << p->ma_so << "|" << setw(29) << p->ho_ten << "|" << setw(29) << p->gio_nghien_cuu << "|" << endl;
			cout << "---------------------------------------------------------------------------" << endl;
			p = p->next;
		}
	}
};

int main() {
	Giang_day *list = NULL, *last = NULL, *node = NULL;
	char tiep = 'c';
	while (tiep == 'c') {
		node = new Giang_day;
		node->nhap_giangday();
		node->next = NULL;
		if (list == NULL) {
			list = node;
			last = node;
		} else {
			last->next = node;
			last = node;
		}
		cout << endl << "Nhap tiep (c = tiep): "; tiep = getch();
		cout << endl;
	}

	Giang_day::sapxep(list);

	cout << "---------------------------------------------------------------------------" << endl;
	cout << "|" << setw(3) << "STT" << "|" << setw(9) << "Ma so" << "|" << setw(29) << "Ho ten" << "|" << setw(29) << "Gio nghien cuu" << "|" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	Giang_day::in(list);

	cout << "Tong so giang vien: " << Giang_day::ts << endl;
}
