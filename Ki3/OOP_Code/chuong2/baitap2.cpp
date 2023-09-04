#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
       31, 31, 30, 31, 30, 31};

class Date {
    int d, m, y;
public:
    //! ham tao
    Date() {

    }
    //!ham nhap - function
    void nhap() {
        cout << "Nhap dd mm yy: ";
        cin >> d >> m >> y;
        normalize();
    }
    //!daysIn
    int daysIn(int month) {
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
                return 29;
            else
                return 28; 
        default:
            return 30;
        }
    }
    //! ham normalize()
    void normalize() {
        if (d > daysIn(m))  d = daysIn(m);
        if (d <= 0)  d = 1;

        if (m > 12) m = 12;
        if (m < 1) m = 1;
        
        if (y < 1) y = 1;
        
    }

    //! advance()
    void advance(int year, int month, int day) {
        y += year;
        m += month;
        d += day;

        while (m > 12) {
            m -= 12;
            y++;
        }

        while (d > daysIn(m)) {
            d -= daysIn(m);
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }
        normalize();
    }
    
    //!hàm trả về số năm nhuận từ mốc 0/0/0 đến thời điểm hiện tại
    int countLeapYears() {
        int years = y;
        // kiểm tra nếu tháng trong năm là 1 hoặc 2 thì nghĩa là không cần kiểm tra năm hiện tại là năm nhuận hay không vì không ảnh hưởng
        if (m <= 2)
            years--;

        return years / 4 - years / 100 + years / 400;
    }
    //! toán tử - trả về số ngày giữa 2 thời điểm
    friend int operator - (Date a, Date b) {    
        
        //*tính số ngày từ mốc 0/0/0 đến thời điểm a
        ll cnt1 = a.y * 365 + a.d;
        for (int i = 0; i < a.m - 1; i++)
        {
            cnt1 += monthDays[i];
        }
        cnt1 += a.countLeapYears();

        //*tính số ngày từ mốc 0/0/0 đến thời điểm b
        ll cnt2 = b.y * 365 + b.d;
        for (int i = 0; i < b.m - 1; i++)
        {
            cnt2 += monthDays[i];
        }
        cnt2 += b.countLeapYears();

        return abs(cnt2 - cnt1);
    }

    //!reset
    void reset(int year, int month, int day) {
        y = year;
        m = month;
        d = day;
        normalize();
    }

    //! print
    void print() {
        cout << d << "/" << m << "/" << y << endl;
    }

    //! ham lay du lieu
    int getMonth() {
        return m;
    }
};

int main() {
    Date a,b;
    cout << "Nhap Date a: " << endl;
    a.nhap();
    a.normalize();
    cout << "Nhap Date b: " << endl;
    b.nhap();
    b.normalize();

    cout << a.daysIn(a.getMonth()) << endl;
    cout << b.daysIn(b.getMonth()) << endl;

    cout << "Advance a - nhap y,m,d: ";
    int y, m, d; cin >> y >> m >> d;
    a.advance(y, m, d);
    a.print();

    cout << "So ngay giua date a va date b: " << a - b << endl;

    cout << "reset date a - nhap y, m, d: ";
    cin >> y >> m >> d;
    a.reset(y, m, d);
    a.print();
}