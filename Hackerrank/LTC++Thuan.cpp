#include <iostream>

using namespace std;

class Sinhvien{
	private:
		string ten;
		int masv;
		float diemToan, diemTriet, diemLTC, diemTBC;
	public:
		void sinhvien(){
			ten = "";
			masv = 0;
			diemToan = 0.00;
			diemTriet = 0.00;
			diemLTC = 0.00;
		}
		void setInfor(){
			cin >> ten >> masv >> diemToan >> diemTriet >> diemLTC;
			diemTBC = (diemToan + diemTriet + diemLTC)/3;
		}
		void printInfor(){
			cout << fixed << setprecision(2) << ten << " " << masv << " " << diemToan << " " << diemTriet << " " << diemLTC << " " <<  diemTBC;
		}
};

int main(){
	int n;
	cout << "Nhap so luong sinh vien";
	cin >> n;
	
	Sinhvien arrSV[n];
	
	for(int i = 0; i < n; ++i){
		arrSV[i].setInfor();
	}
	
	cout << "Danh sach sinh vien: \n" << n;
	
	for(int i = 0; i < n; ++i){
		arrSV[i].printInfor();
	}
	return 0;
}
