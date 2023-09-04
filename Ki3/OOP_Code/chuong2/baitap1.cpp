#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

class Time {
    int hour, min, sec;
    public:
        Time() {

        }
        Time(int hour, int min, int sec) {
            this->hour = hour;
            this->min = min;
            this->sec = sec;
            this->normalize();
        }
        void normalize() {
            if (sec >= 60) sec = 59;
            if (sec < 0) sec = 0;
            if (min >= 60) min = 59;
            if (min < 0) min = 0;
            if (hour >= 24) hour = 23;
            if (hour < 0) hour = 0;
        }
        string getTime() {
            return to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);
        }
        int getHour(){
            return hour;
        }
        int getMin() {
            return min;
        } 
        int getSec() {
            return sec;
        }
        void advance(int h, int m, int s) {
            hour += h;
            min += m;
            sec += s;
            normalize();
        }
        void reset(int h, int m, int s) {
            hour = h;
            min = m;
            sec = s;
            normalize();
        }
        void print() {
            cout << to_string(hour) + ":" + to_string(min) + ":" + to_string(sec) << endl;
        }

        //! khong can chu y den phan nay - nap chong toan tu
        // friend istream& operator >> (istream& in, Time &x) {
        //     in >> x.hour >> x.min >> x.sec;
        //     return in;
        // }
        // friend ostream& operator << (ostream& out, Time x) {
        //     out << to_string(x.hour) + ":" + to_string(x.min) + ":" + to_string(x.sec) << endl;
        //     return out;
        // }

};

int main() {
    int h, m, s;
    cout << "Nhap h:m:s khoi tao: ";
    cin >> h >> m >> s;

    //! khoi tao bien x voi hour = h, min = m, sec = s, chuan hoa tu dong
    Time x(h, m ,s);
    x.print();

    //! x.advance()
    cout << "Nhap h,m,s muon tang len: ";
    cin >> h >> m >> s;
    x.advance(h,m,s);
    x.print();

    //! x.reset()
    cout << "Nhap h:m:s de reset: ";
    cin >> h >> m >> s;
    x.reset(h,m,s);
    x.print();

}