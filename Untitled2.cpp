#include<iostream>
#include<string.h>
#include<conio.h>;
#include<iomanip>
using namespace std;	
class student{
	private:
		string name , id;
		double gpa;
	public:
		friend istream& operator >> (istream &in , student& a);
		friend ostream& operator << (ostream &out , student a);
};
istream& operator >> (istream &in , student& a){
	cout << "nhap ten sinh vien :";
	getline(in , a.name);
	cout << "nhap ma sv :";
	getline(in , a.id);
	cout << "nhap diem sv :";
	in >> a.gpa;
	in.ignore();
}
ostream& operator << (ostream &out , student a){
	cout << " " << a.name << " " << a.id << " " << a.gpa ;
}
int main(){
	student x;
	cin >> x;
	cout << x;
}
