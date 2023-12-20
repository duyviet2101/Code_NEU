#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

class hoadon{
    private: 
        int shd;
        string tenhang;
        float tienban;
        static int tshd;
        static float tstb;

    public:
        hoadon()
        {
            tshd++;// cu tao la hoadon tang len
        }
        ~hoadon()
        {
            tshd--;
            tstb -= tienban;
        }
        void nhap()
        {
            cout << endl <<"Nhap so hoa don: "; cin >>shd;
            cout << endl << "Nhap ten hang: ";
            cin.ignore();getline(cin,tenhang);
            cout <<endl <<"Tien ban: "; cin >> tienban;
            tstb += tienban;
        }
        void in()
        {
            cout << endl << setw(5) << shd << setw(30) << tenhang << setw(10) << tienban;

        }
        static void in_ts(){
            cout << endl << "Tong so hoa don: " << tshd << " . Tong so tien ban: " << tstb;
        }
        hoadon *next;

};
int hoadon :: tshd = 0;
float hoadon :: tstb = 0.0;
int main()
{
   /* hoadon :: in_ts();
    hoadon *p = new hoadon;
    hoadon :: in_ts();
    p->nhap();
    hoadon :: in_ts();*/
    hoadon *list = NULL, *last = NULL , *node = NULL; // list laf cai moc , last laf cais cuoi , node la noi dung ;
    char tiep = 'c';
    while(tiep == 'c')
    {
        node = new hoadon;
        node->nhap();
        node->next = NULL;
        if(list == NULL)
        {
            list = node;
            last = node;

        }
        else{
            last->next = node;
            last = node;
        }
        cout << endl << "Nhap tiep hay khong (c: tiep): ";
        tiep = getch();
    }
    hoadon *i = list;
    
    while (i != NULL)
    {
        i->in();
        i = i->next;
    }

    // !loai bo 1 hoa don khoi ds
    int shd_xoa;
    cout << endl << "Nhap so hoa don can xoa: "; cin >> shd_xoa;
    
}