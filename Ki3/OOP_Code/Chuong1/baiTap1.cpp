#include <bits/stdc++.h>
using namespace std;

struct SV
{
    string msv, ht, lop;
    float dtb;
    SV *next;
};

void insertSV(SV*& head, string msv, string ht, string lop, float dtb) {
    SV* newSV = new SV;
    newSV->msv = msv;
    newSV->ht = ht;
    newSV->lop = lop;
    newSV->dtb = dtb;
    newSV->next = NULL;

    if (!head) {
        head = newSV;
    } else {
        SV* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newSV;
    }
}

void sortSV(SV*& head) {
    for(SV *i = head; i != NULL; i = i->next) {
        for (SV *j = i->next; j != NULL; j = j->next) {
            if (i->dtb < j->dtb) {
                swap(i->msv, j->msv);
                swap(i->ht, j->ht);
                swap(i->lop, j->lop);
                swap(i->dtb, j->dtb);
            }
        }
    }
}

void inSV(SV *& head) {
    cout << "Danh sach sinh vien sau sap xep giam dan theo diem trung binh: " << endl;
    for (SV *i = head; i != NULL; i = i->next) {
        cout << "MSV: " << i->msv << endl;
        cout << "Ho ten: " << i->ht << endl;
        cout << "Lop: " << i->lop << endl;
        cout << "Diem trung binh: " << i->dtb << endl;
        cout << "_________________________" << endl;
    }
}


int main() {
    int n; 
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    SV *head = NULL;
    for (int i = 0; i < n; i++)
    {
        cout << "Sinh vien thu " << i + 1 << ":" << endl;
        string msv, ht, lop;
        float dtb;
        cout << "MSV: "; cin >> msv;
        cin.ignore();
        cout << "Ho ten: "; getline(cin, ht);
        cout << "Lop: "; getline(cin, lop);
        cout << "Diem trung binh: "; cin >> dtb;
        cout << "________________________" << endl;
        insertSV(head, msv, ht, lop, dtb);
    }
    sortSV(head);
    cout << endl;
    inSV(head);
    while (head != NULL) {
        SV *temp = head;
        head = head->next;
        delete temp;
    }
}