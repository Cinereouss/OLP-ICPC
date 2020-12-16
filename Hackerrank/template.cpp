#include<iostream>
#include<math.h>
using namespace std;
template <class T>
class ds{
	int spt;
	T *a;
	public:
		ds(int n=0){
			spt = n;
			a = new T[spt];
		}
		void nhap();
		void in();
		T tmax();
		int tvtmin();
		T pt();
		friend istream &operator >> (istream &is, ds<T> &p);
		friend ostream &operator << (ostream &os, ds<T> &p);
		 
};

template <class T>
istream &operator >> (istream &is, ds<T> &p){
	is >> p.nhap();
	return is;
}
template <class T>
ostream &operator << (istream &os, ds<T> &p){
	os << p.in();
	return os;
}
template <class T>
void ds<T>::nhap(){
	cout<<"Nhap so phan tu: ";
	cin>>spt;
	a = new T[spt];
	for(int i=0;i<spt;i++){
		cout<<"Nhap phan tu thu "<<i+1<<": ";
		cin>>a[i];
	}
}
template <class T>
void ds<T>::in(){
	cout<<"Danh sach la: ";
	for(int i=0;i<spt;i++){
		cout<<a[i]<<", ";
	}
}
template <class T>
T ds<T>::tmax(){
	int i=0;
	T max;
	a[0] = max;
	for(i=1;i<spt;i++){
		if(a[i] > max)
		max = a[i];
	}
	cout<<endl<<"Phan tu lon nhat la: "<<max<<endl;
}
template <class T>
int ds<T>::tvtmin(){
	int vt = 0;
	for(int i=1;i<spt;i++){
		if(a[i]>a[vt])
		vt = i;
	}
	cout<<"Vi tri lon nhat la: "<<vt+1;
}
template <class T>
T ds<T>::pt(){
	int vt;
	cout<<"\n Nhap vao vi tri muon truy xuat: ";
	cin>>vt;
	for(int i=0;i<spt;i++){
		if((i+1)==vt)
		a[vt] = a[i] ;
	}
	cout<<"Gia tri can truy xuat: "<<a[vt];
}
main(){
	ds<int> A;
	cin >> A;
	cout << A;
	A.in();
	A.tmax();
	A.tvtmin();
	A.pt();
}
