#include <bits/stdc++.h>

using namespace std;
template <class T>
class Danhsach{
	private:
		int spt;
		T *a;
	public:
		Danhsach(){
			spt = 0;
			a = NULL;
		}
		~Danhsach(){
			delete []a;
			spt = 0;
			cout << "Huy " << this;
		}
		
		void nhap(){
			cout << "Nhap spt: ";
			cin >> spt;
			a = new T(spt);
			for(int i = 0; i < spt; ++i){
				cout <<"Nhap phan tu thu " << i+1 << ": ";
				cin >> a[i];
			}
		}
		
		void xuat(){
			cout << endl << "Danh sach da nhap: " << endl;
			for(int i = 0; i < spt; ++i)
				cout << a[i] << " ";
		}
		
		void swap(T &a, T &b){
			T temp = a;
			a = b;
			b = temp;
		}
		
		void sortds(){
			for(int i = 0; i < spt; ++i)
				for(int j = i+1; j < spt; ++j)
					if(a[i] > a[j])
						swap(a[i], a[j]);
		}
		
		int maxds(){
			int vtmax = 0, max = 0;
			for(int i = 0; i < spt; ++i){
				if(a[i] > a[vtmax]){
					vtmax = i;
					max = a[i];
				}
			}
			return vtmax;
		}
		
		int minds(){
			int vtmin = 0, min = 0;
			for(int i = 0; i < spt; ++i){
				if(a[i] < a[vtmin]){
					vtmin = i;
					min = a[i];
				}
			}
			return vtmin;
		}
		T get(int vt){
			return a[vt];
		}
};


main(){
	Danhsach<char> a;
	a.nhap();
	a.xuat();
	int imax = a.maxds();
	int imin = a.minds();
	cout << endl << "Vi tri Max: " << a.maxds()+1<< endl;
	cout << "Vi tri Min: " << a.minds()+1<< endl;
	a.sortds();
	a.xuat();
}

