#include<iostream>
#include<conio.h>
#include<string>
#include<math.h>
using namespace std;
class hv
{
	protected:
		double canh;
	public:
		hv():canh(0){}
		virtual ~hv(){}
		hv(double canh)
			:canh(canh){}
		virtual void inport()
		{
			cout << "nhap do dai canh:";
			cin >> canh;	
		}
		virtual void exportt() const 
		{
			cout << "canh :" << canh << endl;
		}
};
class hcnhat : public hv
		{
			private:
				double canh2;
			public:
				hcnhat() : hv() , canh2(0) {}
				void inport() override
				{
					hv :: inport();
					cout << "nhap canh 2:";
					cin >> canh2;
				}
				double chuvi() const
				{
					return canh * 2 + canh2 * 2;
				}
				double dientich() const
				{
					return canh * canh2;
				}
				void exportt() const override
				{ 
					cout << " canh :" << canh << ", canh 2:" << canh2 << endl;
					cout << " chu vi hinh la :" << chuvi() << ", dien tich la :" << dientich() << endl;
				}
		};
		
int main()
{
	int n ;
	cout << " nhap so hinh :";
	cin >> n;
	cin.ignore();
	hcnhat *hcn = new hcnhat[n];
	for(int i = 0; i < n ; i++)
	{
		cout << "-----hinh thu-----\n" << i + 1 << endl;
		hcn[i].inport();
	}
	for(int i = 0; i < n ; i++)
	{
		for(int j = i + 1; j < n ; j++)
		{
			if (hcn[i].dientich() > hcn[j].dientich())
			{
				swap(hcn[i] , hcn[j]);
			}
		}
	}
	cout << " danh sach hinh la :" << endl;
	for (int i = 0 ; i < n ; i++)
	{
		cout << "-----hinh-----\n" ;
		hcn[i].exportt();
	}
	delete [] hcn;
	return 0;
}


