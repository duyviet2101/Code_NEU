#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

class Date
{
    int d, m, y;

public:
    //! ham tao
    Date()
    {
        d = m = y = 0;
    }
    Date(int day, int month, int year)
    {
        d = day;
        m = month;
        y = year;
    }
    //! ham nhap - function
    void nhap()
    {
        cout << "Nhap dd/mm/yy: ";
        char bf;
        cin >> d >> bf >> m >> bf >> y;
        normalize();
    }
    //! in
    void in()
    {
        cout << d << "/" << m << "/" << y;
    }
    //! daysIn
    int daysIn(int month)
    {
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
    void normalize()
    {
        while (m > 12)
        {
            m -= 12;
            y++;
        }

        while (d > daysIn(m))
        {
            d -= daysIn(m);
            m++;
            if (m > 12)
            {
                m = 1;
                y++;
            }
        }
        if (y < 1)
            y = 1;
        if (m < 1)
            m = 1;
        if (d < 1)
            d = 1;
    }

    //! advance()
    void advance(int year, int month, int day)
    {
        y += year;
        m += month;
        d += day;

        while (m > 12)
        {
            m -= 12;
            y++;
        }

        while (d > daysIn(m))
        {
            d -= daysIn(m);
            m++;
            if (m > 12)
            {
                m = 1;
                y++;
            }
        }
        normalize();
    }

    //! hàm trả về số năm nhuận từ mốc 0/0/0 đến thời điểm hiện tại
    // int countLeapYears()
    // {
    //     int years = y;
    //     // kiểm tra nếu tháng trong năm là 1 hoặc 2 thì nghĩa là không cần kiểm tra năm hiện tại là năm nhuận hay không vì không ảnh hưởng
    //     if (m <= 2)
    //         years--;

    //     return years / 4 - years / 100 + years / 400;
    // }
    //! toán tử - trả về số ngày giữa 2 thời điểm
    // friend int operator-(Date a, Date b)
    // {

    //     //*tính số ngày từ mốc 0/0/0 đến thời điểm a
    //     ll cnt1 = a.y * 365 + a.d;
    //     for (int i = 0; i < a.m - 1; i++)
    //     {
    //         cnt1 += monthDays[i];
    //     }
    //     cnt1 += a.countLeapYears();

    //     //*tính số ngày từ mốc 0/0/0 đến thời điểm b
    //     ll cnt2 = b.y * 365 + b.d;
    //     for (int i = 0; i < b.m - 1; i++)
    //     {
    //         cnt2 += monthDays[i];
    //     }
    //     cnt2 += b.countLeapYears();

    //     return abs(cnt2 - cnt1);
    // }

    int operator-(Date d2)
    {
        int nd = 0;
        while (d != d2.d || m != d2.m || y != d2.y)
        {
            nd++;
            d2.d++;
            d2.normalize();
        }
        return (nd);
    }

    //! toan tu <
    friend bool operator<(Date a, Date b)
    {
        // if (a.y != b.y)
        // {
        //     if (a.y > b.y)
        //         return true;
        //     else if (a.y < b.y)
        //         return false;
        // }
        // if (a.m != b.m)
        // {
        //     if (a.m > b.m)
        //         return true;
        //     else if (a.m < b.m)
        //         return false;
        // }
        // if (a.d != b.d)
        // {
        //     if (a.d > b.d)
        //         return true;
        //     else if (a.d < b.d)
        //         return false;
        // }

        // return false;

        Date d;
        if (a - d < b - d) return true;
        return false;
    }

    //! reset
    void reset(int year, int month, int day)
    {
        y = year;
        m = month;
        d = day;
        normalize();
    }

    //! ham lay du lieu
    int getMonth()
    {
        return m;
    }
};

int main()
{
    // Date a, b;
    // cout << "Nhap Date a: " << endl;
    // a.nhap();
    // a.in();
    // cout << endl;
    // a.normalize();
    // cout << "Nhap Date b: " << endl;
    // b.nhap();
    // b.in();
    // cout << endl;
    // b.normalize();

    // cout << a.daysIn(a.getMonth()) << endl;
    // cout << b.daysIn(b.getMonth()) << endl;

    // cout << "Advance a - nhap y,m,d: ";
    // int y, m, d; cin >> y >> m >> d;
    // a.advance(y, m, d);
    // a.in();

    // cout << "So ngay giua date a va date b: " << a - b << endl;

    // cout << "reset date a - nhap y, m, d: ";
    // cin >> y >> m >> d;
    // a.reset(y, m, d);
    // a.in();

    // ! nhập dãy các mốc thời gian
    int n;
    cout << "Nhap so moc date: ";
    cin >> n;
    Date d[n];
    for (int i = 0; i < n; i++)
    {
        d[i].nhap();
    }
    //! sap xep theo thu tu giam dan
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (d[i] < (d[j]))
            {
                Date tg = d[i];
                d[i] = d[j];
                d[j] = tg;
            }
    cout << "sau khi sap xep giam dan: " << endl;
    for (int i = 0; i < n; i++)
    {
        d[i].in();
        cout << "    ";
    }
}