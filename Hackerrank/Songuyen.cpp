#include <iostream>
using namespace std;
 class Songuyen{
 	int n;
 	int *p;
 	char name;
	public:
		Songuyen(){
			n = 0;
			p = NULL;
		
		}
		Songuyen(int a=1, int b=2){
			n=1;
			p=NULL;
		}
		void nhap();
		void xuat();
		void sapxep();
		~Songuyen(){
			cout<<"\nXoa gia tri "<< name;
			delete []p;
		}
 };
 
 void Songuyen::nhap(){
 	cout<<"Nhap so luong phan tu: "; 
 	cin>>n;
 	p = new int(n);
 	for (int i=0; i<n; i++){
 		cout<<"Nhap phan tu thu "<<i+1<<" :";
 		cin>>*(p+i);
 	}
}

void Songuyen::xuat(){
	for (int i=0; i<n; i++)
		cout<<p[i];
	cout<<endl;
}

void Songuyen::	sapxep(){
	for (int i=0; i<n;i++)
		for(int j=i+1; j<n; j++)
			if(p[i] > p[j]){
				int temp = p[i];
				p[i]=p[j];
				p[j]=temp;
			}
}
main(){
	Songuyen a;
	a.nhap();
	a.xuat();
	a.sapxep();
	a.xuat();
}
	
