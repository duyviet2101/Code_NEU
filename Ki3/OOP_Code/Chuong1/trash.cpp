#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct SV
{
    int msv;
    char ht[50];
    int lop;
    float dtb;

};

int main()
{
    SV *sv;
    int i,n,j;
    cout << "Nhap vao so sinh vien : " ;
    cin>> n;
    sv = new SV[n+1];
    if( sv == NULL)
    {
        cout << "Loi cap phat cung nho" << endl;
        getch();
        exit(0);
    }
    for( i = 0 ; i < n ; i++ )
    {
        cout << "Nhap vao thong tin sinh vien: "<< i+1<< endl;
        cout << "Nhap msv : " ;
        cin >> sv[i].msv;
        
        cin.ignore();

        cout << "Nhap ho ten : " ;
        
        cin >> sv[i].ht;
        cout << "Nhap lop: " ;
        cin >> sv[i].lop;
        cout << "Nhap diem trung binh: " ;
        cin >> sv[i].dtb;
    }
    for ( i = 0; i< n-1; i++)
    {
        for(j=i+1;j<n;++j)
        {
            if(sv[i].dtb > sv[j].dtb)
            {
                SV temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
    for(i = 0 ; i<n;i++)
    {
        cout <<"\n"<< " Danh sach sinh vien sau khi sap xep la: "<< "\n" <<
            setw(50)<<sv[i].ht<<setw(6)<<sv[i].dtb;

    }
    delete sv;
    getch();
}