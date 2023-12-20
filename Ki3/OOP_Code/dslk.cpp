#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

class hoadon
{
private:
    int shd;
    string tenhang;
    float tienban;
    static int tshd;
    static float tstb;

public:
    hoadon()
    {
        tshd++; // cu tao la hoadon tang len
    }
    ~hoadon()
    {
        tshd--;
        tstb -= tienban;
    }
    void nhap()
    {
        cout << endl
             << "Nhap so hoa don: ";
        cin >> shd;
        cout << endl
             << "Nhap ten hang: ";
        cin.ignore();
        getline(cin, tenhang);
        cout << endl
             << "Tien ban: ";
        cin >> tienban;
        tstb += tienban;
    }
    void in()
    {
        cout << endl
             << setw(5) << shd << setw(30) << tenhang << setw(10) << tienban;
    }
    static void in_ts()
    {
        cout << endl
             << "Tong so hoa don: " << tshd << " . Tong so tien ban: " << tstb;
    }
    int get_shd()
    {
        return shd;
    }
    hoadon *next;
};
int hoadon ::tshd = 0;
float hoadon ::tstb = 0.0;
int main()
{
    /* hoadon :: in_ts();
     hoadon *p = new hoadon;
     hoadon :: in_ts();
     p->nhap();
     hoadon :: in_ts();*/
    // THUAT TOAN TAO DANH SACH LIEN KET LK DON
    hoadon *list = NULL, *last = NULL, *node = NULL; // list la cai moc , last la cai cuoi , node la noi dung ;
    char tiep = 'c';
    while (tiep == 'c')
    {
        node = new hoadon;
        node->nhap();
        node->next = NULL;
        if (list == NULL)
        {
            list = node;
            last = node;
        }
        else
        {
            last->next = node;
            last = node;
        }
        cout << endl
             << "Nhap tiep hay khong (c: tiep) ";
        tiep = getch();
    }
    // IN DANH SACH LK DON
    hoadon *i = list;
    while (i != NULL)
    {
        i->in();
        i = i->next;
    }
    hoadon ::in_ts();

    // loai bo 1 hoa don ra khoi danh sach
    int shd_xoa;
    cout << endl
         << "Nhap so hoa don can xoa : ";
    cin >> shd_xoa;
    i = list;
    hoadon *p_last = list; // tro den vi truoc cau last
    while (i != NULL)
    {
        p_last = i;
        if (i->get_shd() == shd_xoa)
        {
            last = i;
            break;
        }
        p_last = i;
        i = i->next;
    }
    p_last->next = last->next;
    delete last;
    hoadon::in_ts();
}