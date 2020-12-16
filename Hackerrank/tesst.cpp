#include <bits/stdc++.h>

using namespace std;

#define PI = 3.141592654;

class hinhtron{
	private: 
		float r;
	public:
		float chuvi();
		float dientich();
		void ip_tron(){
			cout << "Nhap ban kinh (R): ";
			if(cin >> r) cout << "Done!";
		}
};

class hinhvuong{
	private:
		float canh;
	public:
		float chuvi();
		float dientich();
		void ip_vuong(){
			cout << "Nhap do dai 1 canh : ";
			if(cin >> canh) cout << "Done!";
		}
};

class tamgiac{
	private:
		float duongcao;
		float day;
	public:
		void ip_tamgiac(){
			cout << "Nhap duong cao va canh day tuong ung: ";
			if(cin >> duongcao >> day) cout << "Done!";
		}
};

class cau{
	private: 
		float r;
	public:
		float thetich ();
		float dientich ();
		void ip_cau(){
			cout << "Nhap ban kinh (R): ";
			if(cin >> r) cout << "Done!";
		}	
};

class lapphuong{
	private: 
		float canh;
	public:
		float dientichtp();
		float dientichxq();
		float thetich();
		void ip_lapphuong(){
			cout << "Nhap do dai 1 canh : ";
			if(cin >> canh) cout << "Done!";
		}
};

class haichieu: public tron{
	public:
		void ip_haichieu(){
			int lc;
			cout << "Lua chon hinh: ";
			cin >> lc;
			switch (lc){
				case 1:{ hinhtron a; a.tron() ; break;}
				case 2:{ hinhvuong a; a.ip_vuong() ; break; }
				case 3:{ tamgiac a; a.ip_tamgiac(); break; }
			}
};

class bachieu: public cau, public lapphuong {
	public:
		void ip_bachieu(){
			int lc;
				cout << "Lua chon hinh: ";
				cin >> lc;
				switch (lc){
					case 1:{ cau a; a.ip_cau() ; break;}
					case 2:{ lapphuong a; a.ip_lapphuong() ; break; }
			}
		}
};

class hinhhoc: public haichieu, public bachieu{
	public: 
		void input(){
			int luachon;
			cout << "Chon he toa do: ";
			cin >> luachon;
			switch (luachon){
				case 1:{ haichieu::ip_haichieu(); break; }
				case 2:{ bachieu::ip_bachieu(); break; }
			}
};
main(){
}
