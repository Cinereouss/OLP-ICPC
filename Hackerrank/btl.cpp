#include <bits/stdc++.h>

using namespace std;

#define PI  3.141592654
char select_yn;

class hinhtron{
	private: 
		float r;
	public:
		float chuvi(){
			return 2*r*PI;
		}
		float dientich(){
			return r*r*PI;
		}
		void ip_tron(int lcc){
			if(lcc!=2)
				cout << "Nhap ban kinh (R): ";
			if(cin >> r) cout <<  endl;
		}
		void out_tron(){
			system("cls");
			cout << endl
				 << ".-=====================-.-===============-." <<endl
				 << "|Chu vi:                |" << setw(17) << right << chuvi() << "|" << endl
				 << "|Dien tich:             |" << setw(17) << right << dientich() << "|" << endl
				 << "*-=====================-*-===============-*"<<endl;
		}
};

class hinhvuong{
	private:
		float canh;
	public:
		float chuvi(){
			return canh*4;
		}
		float dientich(){
			return canh*canh;
		}
		void ip_vuong(int lcc){
			if(lcc!=2)
				cout << "Nhap do dai 1 canh : ";
			if(cin >> canh) cout <<  endl;
		}
		void out_vuong(){
		system("cls");
		cout << endl
			 << ".-=====================-.-===============-." <<endl
			 << "|Chu vi:                |" << setw(17) << right << chuvi() << "|" << endl
			 << "|Dien tich:             |" << setw(17) << right << dientich() << "|" << endl
			 << "*-=====================-*-===============-*"<<endl;
		}
};

class tamgiac{
	private:
		float canh1, canh2, canh3;
	public:
		void ip_tamgiac(int lcc){
			if(lcc!=2)
				cout << "Nhap 3 canh tuong ung: ";
			if(cin >> canh1 >> canh2 >> canh3) cout << endl;
		}
		float chuvi(){
			return canh1+canh2+canh3;
		}
		float dientich(){
			float p = chuvi()/2;
			return p*(p-canh1)*(p-canh2)*(p-canh3);
		}
		void out_tamgiac(){
			system("cls");
			if(dientich()>0)
				cout << endl
					 << ".-=====================-.-===============-." <<endl
					 << "|Chu vi:                |" << setw(17) << right << chuvi() << "|" << endl
					 << "|Dien tich:             |" << setw(17) << right << dientich() << "|" << endl
					 << "*-=====================-*-===============-*"<<endl;
		  	else 
		  		cout << "Gia tri nhap vao khong thoa man!" << endl;
		}
};

class cau{
	private: 
		float r;
	public:
		float thetich (){
			return (4*PI*r*r*r)/3;	
		}
		float dientich (){
			return 4*PI*r*r*r;
		}
		void ip_cau(int lcc){
			if(lcc!=2)
				cout << "Nhap ban kinh (R): ";
			if(cin >> r) cout <<  endl;
		}	
		void out_cau(){
			system("cls");
			cout << endl
				 << ".-=====================-.-===============-." <<endl
				 << "|Dien tich:             |" << setw(17) << right << dientich() << "|" << endl
				 << "|The tich:              |" << setw(17) << right << thetich() << "|" << endl
				 << "*-=====================-*-===============-*"<<endl;
		}
};

class lapphuong{
	private:  
		float canh;
	public:
		float dientichtp(){
			return 6*canh*canh;
		}
		float dientichxq(){
			return 4*canh*canh;
		}
		float thetich(){
			return canh*canh*canh;
		}
		void ip_lapphuong(int lcc){
			if(lcc!=2)
				cout << "Nhap do dai 1 canh : ";
			if(cin >> canh) cout << endl;
		}
		void out_lapphuong(){
			system("cls");
			cout << endl
				 << ".-=====================-.-===============-." <<endl
			  	 << "|Dien tich xung quanh:  |" << setw(17) << right << dientichxq() << "|" << endl
				 << "|Dien tich toan phan:   |" << setw(17) << right << dientichtp() << "|" << endl
				 << "|The tich:              |" << setw(17) << right << thetich() << "|" << endl
				 << "*-=====================-*-===============-*"<<endl;
		}
};

class haichieu : public hinhtron, public hinhvuong, public tamgiac{
	public:
		void ip_haichieu(int lcc){
			int lc;
			if(lcc!=2){
				cout << ".-=======================================-."<<endl
					 << "|Chon 1: Hinh tron                        |"<<endl
					 << "|Chon 2: Hinh vuong                       |"<<endl
					 << "|Chon 3: Tam giac                         |"<<endl
					 << "|Chon phim bat ky: Exit                   |"<<endl
					 << "*-=======================================-*"<<endl;
				cout << ">> Lua chon hinh: " << endl;
			}
			cin >> lc;
			switch (lc){
				case 1:{ hinhtron a; a.ip_tron(lcc); a.out_tron(); break;}
				case 2:{ hinhvuong a; a.ip_vuong(lcc); a.out_vuong(); break; }
				case 3:{ tamgiac a; a.ip_tamgiac(lcc); a.out_tamgiac(); break; }
				default:{break;}
			}
		}
};

class bachieu: public cau, public lapphuong{
	public:
		void ip_bachieu(int lcc){
			int lc;
			if(lcc!=2){
				cout << ".-=======================================-."<<endl
					 << "|Chon 1: Hinh cau                         |"<<endl
					 << "|Chon 2: Hinh lap phuong                  |"<<endl
					 << "|Chon phim bat ky: Exit                   |"<<endl
					 << "*-=======================================-*"<<endl;
				cout << "Lua chon hinh: " << endl;
			}
			cin >> lc;
			switch (lc){
				case 1:{ cau a; a.ip_cau(lcc); a.out_cau(); break;}
				case 2:{ lapphuong a; a.ip_lapphuong(lcc); a.out_lapphuong(); break; }
				default:{break;}
			}
		}
};

class hinhhoc: public haichieu, public bachieu{
	public: 
		void input(int lcc){
			if(lcc!=2){
				cout << ".-=======================================-."<<endl
					 << "|Chon 1: He toa do 2 chieu (Oxy)          |"<<endl
					 << "|Chon 2: He toa do 3 chieu (Oxyz)         |"<<endl
					 << "|Chon phim bat ky: Exit                   |"<<endl
					 << "*-=======================================-*"<<endl;
				cout << " >> Chon he toa do: " << endl;
			}
			int luachon;
			cin >> luachon;
			switch (luachon){
				case 1:{ haichieu::ip_haichieu(lcc); break; }
				case 2:{ bachieu::ip_bachieu(lcc); break;}
				default:{select_yn = 'N'; break;}
			}
		}
};

main(){
	int select_io;
	cout << ".-=======================================-."<<endl
		 << "|          CHON PHUONG THUC NHAP          |"<<endl
		 << "*-=======================================-*"<<endl
		 << "|Chon 1: Nhap thu cong                    |"<<endl
		 << "|Chon 2: Nhap tu file text (*.txt)        |"<<endl
		 << "*-=======================================-*"<<endl;
	cin >> select_io;
	if(select_io == 1)
		do{
			select_yn = ' ';
			system("cls");
			cout << "******************************************"<<endl
				 << "*        CHUONG TRINH TINH TOAN          *"<<endl
				 << "******************************************"<<endl;
			hinhhoc tong;
			tong.input(1);
			if(select_yn == ' '){
				cout << "Tiep tuc tinh toan (Y/N): ";
				cin >> select_yn;
			}
		}while(select_yn == 'y' || select_yn =='Y');
	else{
		char cf;
		cout << "Chu y:" << endl
			 << "1.File input co ten la input.txt va duoc dat tai cung thu muc voi flie *.exe." << endl
			 << "2.Voi moi lan tinh toan trong file input cac dinh dang nhap nhu sau: " << endl
			 << "	*Doi voi hinh tron, hinh vuong, hinh cau, hinh lap phuong cu phap:" << endl
			 << "		<he toa do> <hinh> <value> <tham so dieu khien> "	<< endl
			 << "		Vi du:  1 1 3 Y " << endl
			 << "	*Doi voi hinh tam giac cu phap nhap:" << endl
			 << "		1 3 <canh 1> <canh2> <canh3> <tham so dieu khien>" << endl
			 << "		Vi du: 1 3 1 2 3 Y" << endl
			 << "3.Cac gia tri tuong ung." << endl
			 << "	<he toa do> " << endl
			 << "		1 neu la 2 chieu" << endl
			 << "		2 neu la 3 chieu" << endl
			 << "	<hinh> " << endl
			 << "		doi voi he 2 chieu:" << endl
			 << "			1 hinh tron" << endl
			 << "			2 hinh vuong" << endl
			 << "			1 hinh tam giac" << endl
			 << "		doi voi he 3 chieu:" << endl
			 << "			1 hinh cau" << endl
			 << "			2 hinh lap phuong" << endl	
			 << "	<tham so dieu khien> " << endl
			 << " 		Day la tham so dung de xac nhan lan thuc hien, Y neu ban muon thuc hien tiep va ban cung co the ket thuc lan thuc hien bang 1 dong lenh 0" << endl
			 << ">>>>>>>>>>>>>>>> Xac Nhan (y/n):";
			 cin >> cf;
			 if(cf = 'y'){
			 	freopen("input.txt", "r", stdin);
		 		freopen("output.txt", "w", stdout);
				select_yn = 'y';
				while(select_yn == 'y' || select_yn =='Y'){
					hinhhoc tong;

					tong.input(2);
					cin >> select_yn;
				}
			 }
	}
}
