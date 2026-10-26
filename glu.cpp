#include<iostream>
#include<conio.h>
#include<string>
#include<math.h>
using namespace std;
class human 
{
	protected:
		string name;
		double 	year;
	public:
		human():name("") , year(0){}
		human(string name , double year)
			: name(name) , year(year)
		{}
		virtual  ~human()
		{}
		virtual void inport() 
		{
			cout << "nhap name :";
			getline(cin , name);
			cout << "nhap nam sinh :";
			cin >> year;
			cin.ignore();	
		}
		double tuoi() const 
		{
			return 2026 - year;
		}
		virtual void exportt() const 
		{
			cout << "ten :" << name << endl;
			cout << "tuoi  :" << tuoi() << endl;
		}
};
class teacher : public human
{
	private:
		double namct , mon;
	public:
		teacher() : human() , namct(0) , mon(0) {}
		void inport() override
		{
			human :: inport();
			cout << "nhap nam cong tac :";
			cin >> namct;
			cout << "nhap so mon :" ;
			cin >> mon;
			cin.ignore();
		}
		bool check() const
		{
			return namct > 20 && tuoi() > 50;
		}
		void exportt() const override
		{
			human :: exportt();
			cout << "nam cong tac la :" << namct << ", so mon dang day la :" << mon << endl;
		}	
};
int main()
{
	int n;
	cout << "nhap so nguoi :";
	cin >> n;
	cin.ignore();
	teacher *gv = new teacher[n];
	for(int i = 0 ; i < n ; i++)
	{
		cout << "-------nguoi thu--------\n" << i + 1 << endl;
		gv[i].inport();	
	}
	cout << " danh sach nguoi la :" << endl;
	bool co = false;
	for(int i = 0 ; i < n ; i++)
	{
		if (gv[i].check())
		{
			gv[i].exportt();
			cout << "-------nguoi thu--------\n" ;
			co = true;
		}	
	}
	if(!co)
	{
		cout <<"khong co giang vien nao dat dieu kien" << endl;
	}
	delete[] gv;
	return 0;		
}
