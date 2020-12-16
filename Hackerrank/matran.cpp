#include <iostream>

using namespace std;

class Matran{
	public:
		int hang, cot;
		float *p;
		Matran(){
			hang = cot = 0;
			p = NULL;
		}
		Matran(int gt1, int gt2){
			hang = gt1;
			cot = gt2;
			p = new float[hang*cot];
		}
		~Matran(){
			cout << endl << "Da huy" << endl;
			delete []p;
		}
		Matran(Matran &p);
		void input();
		void output();
};

Matran::Matran(Matran &a){
	hang = a.hang;
	cot =a.cot;
	p = new float(hang*cot);
	for (int i = 0; i < hang*cot; i++)
		*(p+i) = *(a.p+i);
};

void Matran::input(){
	cout<<"Nhap hang va cot: "<<endl;
	cin>>hang>>cot;
	p = new float(hang*cot);
	for (int i = 0; i < hang*cot; i++){
		cout<<"Nhap gia tri cho phan tu "<<i+1<<" :";
		cin>>*(p+i);
	}
};

void Matran::output(){
	for (int i = 0; i < hang*cot; i++){
		cout<<*(p+i)<<" ";
		if((i+1)%cot==0)
			cout<<endl;
	}
	cout<<endl;
};

void nhan(Matran a, Matran b, Matran &c){

		for(int i = 0; i < a.hang; i++)
			for(int j = 0; j < b.cot; j++)
				for(int k=0;k<a.cot;k++)
			    	*(c.p+i+j*c.hang)+=*(a.p+i+k*a.hang) * *(b.p+k+j*b.hang);
}

main(){
	Matran a,b;
	a.input();
	b.input();
	
	a.output();
	b.output();
	cout<<"Ket qua cua 2 ma tran tren la: "<< endl;
	Matran c(a.hang, b.cot);
	nhan(a,b,c);
	c.output();
}
