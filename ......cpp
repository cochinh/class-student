#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class sinhvien{
	private:
		string name , id;
		double toan , ly , hoa ;
	public:
		sinhvien() : name("") , id("") , toan(0) , ly(0) , hoa(0) 
		{
			
		}
		sinhvien(const string &name ,const string &id ,double toan , double ly , double hoa)
			: name(name) , id(id) , toan(toan) , ly(ly) , hoa(hoa) 
			{
			
			}
		~sinhvien()
		{
			
		}
		void inport()
		{
			cout << "nhap ten sinh vien:";
			getline(cin , name);
			cout << "nhap ma sv:";
			getline(cin ,id);
			cout << "nhap diem ba mon:";
			cin >> toan >> ly >> hoa;
			cin.ignore();
		}
		double sum() const
		{
			return toan + ly + hoa;
		}
		bool doidiem() const
		{
			if ( 10 > toan , ly , hoa >= 8.5 )
			{
				cout << "A+" << endl;
			}
			else if (8.5 > toan , ly , hoa >= 7)
			{
				cout << "B" << endl;
			}
			else if (7 > toan , ly , hoa >= 4)
			{
				cout << "C" << endl;
			}
			else
			{
				cout << "D" << endl;
			}
		}
		void exportt() const
		{
			cout << "name sinh vien la :" << name << endl;
			cout << "ma sinh vien:" << id << endl;
			cout << "diem toan ly hoa la:" << toan << " "
										   << ly << " "
										   << hoa << endl;
			cout << "sum: " << sum() << endl;
		}
		
};
int main()
{
	int n;
	cout << "nhap so sinh vien:";
	cin >> n;
	cin.ignore();
	sinhvien *sv;
	sv = new sinhvien[n];
	for(int i = 0 ;i < n ;i++)
	{
		cout <<"------ sinh vien thu -------\n" << i + 1 << endl;
		sv[i].inport();
	}
	for(int i = 0 ; i < n ; i++)
	{
		if(sv[i].doidiem())
		  sv[i].exportt();
	}
	for(int i = 0; i < n ; i++)
	{
		for(int j = i + 1 ; j < n ; j++)
		{
			if (sv[i].sum() < sv[j].sum())
			{
				sinhvien tg = sv[j];
				sv[j] = sv[i];
				sv[i] =  tg;
			}
		}
	}
	cout <<"---------danh sach sinh vien---------\n";
	for(int i = 0 ;i < n ;i++)
	{
		sv[i].exportt();
	}
	
	delete[] sv;
	return 0;
}
