#include<iostream>
#include<string.h>
#include<conio.h>;
#include<iomanip>
using namespace std;
class student {
	protected:
		string id , name , lop;
		double gpa , toan , ly , hoa;
	public:
		student(string id , string name , string lop , double gpa , double toan , double ly , double hoa){
			this -> id = id;
			this -> name = name;
			this -> lop = lop;	
			this -> toan = toan;
			this -> ly = ly;
			this -> hoa = hoa;
			this -> gpa = gpa;
		} 
		~student(){
			
		}
		student() {
        	id = "";
       	 	name = "";
        	lop = "";
        	gpa = 0;
			toan = 0;
			ly = 0;
			hoa = 0;
    	}
    	
		void import(){
			cout << "nhap ma sv: \n";
			getline(cin , id);
			cout << "nhap name sv : \n";
			getline(cin , name);
			cout << "nhap lop : \n";
			getline(cin , lop);
			cout << "nhap toan :\n";
			cin >> toan;
			cout << "nhap ly :\n";
			cin >> ly;
			cout << "nhap hoa :\n";
			cin >> hoa;
			cin.ignore();	
			gpa = (toan + ly + hoa) / 3;
		}
		void exportt(){
			cout << "ma sv la : " << id << endl;
			cout <<  "name sv : " << name << endl;
			cout << "lop sv la : " << lop << endl;
			cout << "gpa : \n" << fixed << setprecision(2) << gpa << "\n" << endl;
		}
		double getgpa(){
			return gpa;
		}
		void setgpa(double gpa){
			this -> gpa = gpa;
		}
		double gettoan(){
			return toan;
		}
		double getly(){
			return ly;
		}
		double gethoa(){
			return hoa;
		}
		class student : public chinh(int age){
			 this -> age = age;
			 chinh{
			 	age = 0;
			 }
		};
};
int main(){
	student *sv;
	int n;
	cout << "nhap so luong sv: ";
	cin >> n;
	cin.ignore();
	sv = new student[n];
	for(int i = 0 ; i < n ; i++){
		cout << "=====nhap sinh vien======" << i + 1 << endl;
		sv[i].import();
	}cout << "===== danh sach sinh vien ==== \n" << endl;
	for(int i = 0 ; i < n ; i++){
				if(sv[i].getgpa() >= 5 && sv[i].gettoan() > 5 && sv[i].getly() > 5 && sv[i].gethoa() > 5 ){
					cout << "===== sinh vien thu : ==== " << i + 1 << endl;
					sv[i].exportt();
			}
		
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j < n ; j++){
			if(sv[i].getgpa() < sv[j].getgpa()){
				student tg = sv[i];
				sv[j] = sv[i];
				sv[j] = tg;
			 	cout << "danh sach student da sap xep :" << i + 1 << endl;
				sv[i].exportt();
			}
		}
	}
	delete[] sv;
	return 0;
	
}
