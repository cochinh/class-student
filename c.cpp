#include <iostream>
using namespace std;

class PS1 {
protected:
    long long tu, mau;

    static long long ucln(long long a, long long b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0) {
            long long r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

public:
    PS1() : tu(0), mau(1) {}
    PS1(long long tu, long long mau) : tu(tu), mau(mau) {}

    void toigian() {
        if (mau < 0) {           
            tu = -tu;
            mau = -mau;
        }
        long long g = ucln(tu, mau);
        if (g > 1) {
            tu /= g;
            mau /= g;
        }
    }

   
    friend istream& operator>>(istream &in, PS1 &p) {
        cout << "Nhap tu so: ";
        in >> p.tu;
        do {
            cout << "Nhap mau so (khac 0): ";
            in >> p.mau;
        } while (p.mau == 0);
        p.toigian();
        return in;
    }

  
    friend ostream& operator<<(ostream &out, const PS1 &p) {
        if (p.mau == 1) out << p.tu;
        else out << p.tu << "/" << p.mau;
        return out;
    }
};

class PS2 : public PS1 {
public:
    PS2() : PS1() {}
    PS2(long long tu, long long mau) : PS1(tu, mau) {}

    
    PS2& operator=(const PS2 &p) {
        if (this != &p) {
            tu = p.tu;
            mau = p.mau;
        }
        return *this;
    }

    
    bool operator<(const PS2 &p) const {
        return tu * p.mau < p.tu * mau;
    }
};

int main() {
    int n;
    cout << "Nhap so phan so: ";
    cin >> n;

    PS2 *ps = new PS2[n];

    for (int i = 0; i < n; i++) {
        cout << "------ Phan so thu " << i + 1 << " ------\n";
        cin >> ps[i];
    }

    PS2 max = ps[0], min = ps[0];
    for (int i = 1; i < n; i++) {
        if (max < ps[i]) max = ps[i];   
        if (ps[i] < min) min = ps[i];
    }

    cout << "\nCac phan so (da toi gian): ";
    for (int i = 0; i < n; i++) cout << ps[i] << "  ";

    cout << "\nPhan so lon nhat: " << max << endl;
    cout << "Phan so nho nhat: " << min << endl;

    delete[] ps;
    return 0;
}
