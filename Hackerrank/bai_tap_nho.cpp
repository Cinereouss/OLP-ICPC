#include <bits/stdc++.h>
#define PI 3.14159265
using namespace std;

class hinh{
	public:
		input(char)
};

class haichieu: public hinh{
	protected:
		float cv, ctg1, ctg2, ctg3, r;
	public:
		void set_cv(float x){
			cv = x;
		}
 		void set_r(float x){
			r = x;
		}
		void set_ctg(float x, float y, float z){
			ctg1 = x;
			ctg2 = y;
			ctg3 = z;
		}
};

class bachieu:hinh{
	protected: 
		float clp, r;
	public:
		void set_clp(float x){
			clp = x;
		}
 		void set_r(float x){
			r = x;
		}
};

class hinhtron: public haichieu{
	public:
		float chuvi(){
				return 2*r*PI;
		}
		float dientich(){
				return r*r*PI;
		}
};

class hinhvuong: public haichieu{
	public:
		float chuvi(){
			return cv*4;
		}
		float dientich(){
			return cv*cv;
		}
};

class tamgiac: public haichieu{
	public: 
		float chuvi(){
			return ctg1+ctg2+ctg3;
		}
		float dientich(){
			float p = chuvi()/2;
			return p*(p-ctg1)*(p-ctg2)*(p-ctg3);
		}
};

class lapphuong: public bachieu{
	public:
		float dientichtp(){
			return 6*clp*clp;
		}
		float dientichxq(){
			return 4*clp*clp;
		}
		float thetich(){
			return clp*clp*clp;
		}
};

class cau: public bachieu{
	public:
		float thetich (){
			return (4*PI*r*r*r)/3;	
		}
		float dientich (){
			return 4*PI*r*r*r;
		}
};

main(){
	hinhvuong a;
	a.set_cv(5);
	cout << "S: " << a.dientich();
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
}

