#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class Giangvien
{
protected:
    char ho_ten[30];
    float gio_nghien_cuu;
    char ma_so[30];
public:
    static int tsdt;
    Giangvien()
    {
        tsdt++;
    }
    Giangvien(char maso[30], char hoten[30])
    {
        strcpy(ma_so,maso);
        strcpy(ho_ten,hoten);
        tsdt++;
    }
    ~Giangvien()
    {
        cout<<"Huy doi tuong"<<endl;
    }
    void Nhap()
    {
        cout<<"Nhap ma so giang vien: "<<endl;cin.get(ma_so,30);cin.ignore();
        cout<<"Nhap ten giang vien: "<<endl;cin.get(ho_ten,30);cin.ignore();
    }
    void Xuat()
    {
        cout<<ma_so<<setw(20)<<ho_ten<<setw(10)<<setw(10)<<endl;
    }
    bool operator>(Giangvien a)
    {
        if(this->gio_nghien_cuu>a.gio_nghien_cuu)
            return true;
        else return false;
    }
};
int Giangvien::tsdt = 0;

class Giang_vien_co_huu:virtual public Giangvien
{
private:
    int So_bai_bao;
    float Huong_dan_nghien_cuu, He_so_nghien_cuu, Gio_bai_bao;
public:
    void Nhap_co_huu()
    {
        cout<<"Nhap so bai bao:"<<endl; cin>>So_bai_bao;
        cout<<"Nhap huong dan nghien cuu:"<<endl; cin>>Huong_dan_nghien_cuu;
        cout<<"Nhap he so nghien cuu:"<<endl; cin>>He_so_nghien_cuu;
        cout<<"Nhap gio bai bao:"<<endl; cin>>Gio_bai_bao;
        gio_nghien_cuu = So_bai_bao*Gio_bai_bao+Huong_dan_nghien_cuu*He_so_nghien_cuu;
    }
};

class Giang_vien_kiem_giang:virtual public Giangvien
{
private:
    int So_bai_bao;
    float Gio_kiem_giang,Gio_bai_bao;
public:
    void Nhap_kiem_giang()
    {
        cout<<"Nhap gio kiem giang:"<<endl; cin>>Gio_kiem_giang;
        cout<<"Nhap so bai bao:"<<endl; cin>>So_bai_bao;
        cout<<"Nhap gio bai bao:"<<endl; cin>>Gio_bai_bao;
        gio_nghien_cuu = So_bai_bao*Gio_bai_bao+Gio_kiem_giang;
    }
};

class Giang_day:public Giang_vien_co_huu, public Giang_vien_kiem_giang
{
public:
    Giang_day*next;
    void Nhap_giang_day()
    {
        Nhap();
        if(ma_so[0]=='c') Nhap_co_huu();
        else Nhap_kiem_giang();
    }
    friend void hoanvi(Giang_day*dau)
    {
        Giang_day*i = dau;
        Giang_day*j;
        while(i!=NULL)
        {
            j=i->next;
            while(j!=NULL)
            {
                if(i->gio_nghien_cuu<j->gio_nghien_cuu)
                {
                    Giang_day tg;
                    tg.gio_nghien_cuu = i->gio_nghien_cuu; i->gio_nghien_cuu = j->gio_nghien_cuu; j->gio_nghien_cuu = tg.gio_nghien_cuu;
                    strcpy(tg.ho_ten,i->ho_ten); strcpy(i->ho_ten,j->ho_ten); strcpy(j->ho_ten,tg.ho_ten);
                    strcpy(tg.ma_so,i->ma_so); strcpy(i->ma_so,j->ma_so); strcpy(j->ma_so,tg.ma_so);
                }
                j=j->next;
            }
            i=i->next;
        }
    }
    friend void Hienthi(Giang_day*a,int dem)
    {
        for(int i=0;i<dem;i++)
        {
            cout<<"|"<<setw(3)<<i<<"|"<<setw(9)<<a->ma_so<<"|"<<setw(29)<<a->ho_ten<<"|"<<setw(29)<<a->gio_nghien_cuu<<"|"<<endl;
            cout<<"---------------------------------------------------------------------------"<<endl;
            a=a->next;
        }
    }
};
int main()
{

//   cout << "Tong so doi tuong truoc khi in: "<<Giangvien::tsdt<<endl;
//   Giangvien a("ms_01","Nguyen Danh An");
//   a.Xuat();
//   Giangvien b;
//   b.Nhap();
//   b.Xuat();
//   cout << "Tong so doi tuong sau khi in: "<<Giangvien::tsdt<<endl;

   Giang_day*dau=NULL,*cuoi=NULL,*node=NULL;
   int dem = 0;
   char tiep = 'c';
   do
    {
        node=new Giang_day;//3 dong duoi la de tao 1 node moi//
        node->Nhap_giang_day();
        node->next=NULL;
        if(dau==NULL)
        {
            dau = cuoi = node;
            dem++;
        }
        else
        {
            cuoi->next=node;
            cuoi = node;
            dem++;
        }
        cout<<endl<<"Nhap tiep: c=tiep";cin>>tiep;cin.ignore();
    }while(tiep=='c');
    cout<<endl<<"dem:"<<dem<<endl;
    cout<<"Truoc khi sap xep:"<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<"|STT|"<<setw(10)<<"Ma so |"<<setw(30)<<"Ho ten|"<<setw(30)<<"Gio nghien cuu |"<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    Hienthi(dau,dem);

    hoanvi(dau);
    cout<<"Sau khi sap xep:"<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<"|STT|"<<setw(10)<<"Ma so |"<<setw(30)<<"Ho ten|"<<setw(30)<<"Gio nghien cuu |"<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    Hienthi(dau,dem);
}
