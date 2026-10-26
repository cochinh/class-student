#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class sp
{
	private:
		double thuc , ao;
		static double module(double a , double b)
		{
			return sqrt(a * a + b * b);
		}
	public:
		sp() : thuc(0) , ao(0){}
		sp (double thuc , double ao)
			: thuc(thuc) , ao(ao){}
		friend istream& operator >>(istream &in , sp &p)
		{
				cout << "phan thuc :" ;
				in >> p.thuc;
				cout << "phan ao :";
				in >> p.ao;
				return in;
		}	
		friend ostream& operator <<(ostream &out , sp &p)
		{
			out << p.thuc;
			if (p.ao < 0)
				out << "-" << -p.ao << " i ";
			else
				out << " + " << p.ao << " i ";
			return out;
		}
		friend bool operator <(const sp& a, const sp &b)
		{
			return module(a.thuc, a.ao)
				< module(b.thuc , b.ao);
		}
};
int main()
{
	int n;
	cout << " nhap n so phuc :";
	cin >> n;
	cin.ignore();
	sp *p1 = new sp[n];
	for (int i = 0 ; i < n ; i++)
	{
		cout << "-----nhap------" << i + 1 << endl ;
		cin >> p1[i];
	}
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (p1[i] < p1[j])
			{
				swap(p1[i] , p1[j]);
			}
		}
	}
	cout << "----danh sach so phuc------\n";
	for (int i = 0 ; i < n ; i++)
	{
		cout << "--------so phuc thu:--------" << i + 1 << "  " << p1[i] << endl;
	}
	delete[] p1;
	return 0;
}
