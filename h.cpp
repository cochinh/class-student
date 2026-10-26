#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class ps1
{
	protected:
		long long tu , mau;
		static long long ucln(long long a , long long b)
		{
			if (a < 0) a = -a;
			if (b < 0) b = -b;
			while(b != 0)
			{
				long long r = a % b;
				a = b;
				b = r;
			}
			return a;
		}
	public:
		ps1(): tu(0) , mau(1){}
		ps1 (long long tu , long long mau)
			: tu(tu) ,  mau(mau){}
		virtual ~ps1(){}
		virtual void toigian()
		{
			if (mau < 0)
			{
				tu = -tu;
				mau = -mau;
			}
			long long c = ucln(tu , mau);
			if(c > 1)
			{
				tu = tu / c;
				mau = mau / c;
			}
		}
		friend istream& operator >>(istream &in , ps1 &p)
		{
			cout << "nhap tu so:";
			in >> p.tu;
			do
			{
				cout << "nhap  mau so :";
				in >> p.mau;
			}while(p.mau == 0);
			p.toigian();
			return in;
		}
		friend ostream& operator <<(ostream &out , const ps1 &p)
		{
			if (p.mau == 1) out << p.tu;
			else out << p.tu << " / " << p.mau;
			return out;
		}	
};
class ps2 : public ps1
{
	public:
		ps2() : ps1() {}
		ps2 (long long tu , long long mau): ps1(tu , mau) {}
		ps2& operator = (const ps2 &p)
		{
			if (this != &p)
			{
				tu = p.tu;
				mau = p.mau;
			}
			return *this;
		}
		bool operator <(const ps2 &p) const
		{
			return tu * p.mau < p.tu * mau;
		}
				
		 
};
int main()
{
	int n; 
	cout << "nhap so phan so:";
	cin >> n;
	cin.ignore();
	ps2 *ps = new ps2[n];
	for( int i = 0 ; i < n ; i++)
	{
		cout << "------phan so thu-------" << i + 1 ;
		cin >> ps[i];
	}
	ps2  max = ps[0] , min = ps[0];
	for( int i = 1 ; i < n ; i++)
	{
		if (max < ps[i]) max = ps[i];
		if (ps[i] < min) min = ps[i];
	
	}
	cout << "-----danh sach phan so da sap xep la------" << endl;
	for (int i = 0 ; i < n ; i++)
	{
		cout << ps[i];
	}
	cout << "max :" << max << endl;
	cout << "min :" << min << endl;
	delete[] ps;
	return 0;
}
