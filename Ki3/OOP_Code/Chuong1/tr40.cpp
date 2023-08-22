#include <bits/stdc++.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct TS {
    char ht[20];
    long sobd;
    float td;
};

int main() {
    int n;
    cout << "Nhap so thi sinh: ";
    cin >> n;
    
    TS *ts;
    ts = new TS[n + 1];
    if (ts == NULL) {
        cout << "\nLoi cap phat vung nho";
        getch();
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\nThi sinh thu: " << i + 1;
        cout << "\nHo ten: ";
        cin.ignore(1);
        cin.get(ts[i].ht, 20);
        cout << "So bao danh: ";
        cin >> ts[i].sobd;
        cout << "tong diem: ";
        cin >> ts[i].td;
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1 ; j < n ; j++)
            if (ts[i].td < ts[j].td) {
                TS tg = ts[i];
                ts[i] = ts[j];
                ts[j] = tg;
            }
    for (int i = 0; i < n; ++i)
    {
        cout << "\n" << setw(20) << ts[i].ht << setw(6) << ts[i].td;
    }
    delete ts;
    getch();
}