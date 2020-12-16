#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;
class Matrix{
	private:
		float **a;
		int m,n; // m hang,n cot
	public:
		Matrix(){
			m=0;
			n=0;
			a=NULL;
		}
		Matrix( Matrix & p);
		~Matrix();
		void nhap();
		void xuat();
		void nhap2();
		void xuat2();
		void nhaptufile();
		void xuatrafile();		
		friend Matrix & operator + (const Matrix &x,const Matrix & y);
		friend Matrix & operator * (const Matrix &x,const Matrix & y);
		void cpy(float &tmp, Matrix a );
	//	friend Matrix & operator [] (const Matrix &x);
		int indexcolumn()
		{
			return n;
		}
		
		int indexrow()
		{
			return m;
		}
		
		void Max(){
			ofstream fo("ketqua2.txt",ios::out);
			float max=a[0][0];
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
					if(a[i][j]>max){
					max=a[i][j];
				}
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
					if(a[i][j]==max){				
			fo<<"Phan tu lon nhat cua ma tran la:";
			fo<<"a["<<i<<"]["<<j<<"]="<<a[i][j]<<endl;
		}	
			fo.close();				
}

		float dinhthuc(float a[100][100],int n){ 
				float s;
				float sum=0;
				if(n==1) return a[0][0];
				if(n==2) return (a[0][0]*a[1][1] - a[1][0]*a[0][1]);
			
				for(int k=0;k<n;k++){
					float smaller[100][100];
					for(int i=0;i<n;i++){
						for(int j=1;j<n;j++){
							if(i<k) smaller[i][j-1]=a[i][j];
							else if(i>k) smaller[i-1][j-1]=a[i][j];
						}
					}
					if(k%2==0) s=1;
					else s=-1;
					sum+=a[k][0]*s*dinhthuc(smaller,n-1);
				}
				return sum;
		}
};
Matrix::Matrix(Matrix &p){
	m=p.m;
	n=p.n;
	a=new float*[m];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			a[i]=new float [n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			a[i][j]=p.a[i][j];		
}
void Matrix::cpy(float &tmp, Matrix a){
			float tmp[m][n];
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
					tmp[i][j] = a[i][j];
}
Matrix::~Matrix(){
	for(int i=0;i<m;i++)
		delete []a[i];
			delete []a;
}		
void Matrix::nhap(){
	do{
	cout<<"Nhap so hang va so cot:";
	cin>>m>>n;
}while((m<=0)||(n<=0));	
	a=new float*[m];
	for(int i=0;i<m;i++)
		a[i]=new float[n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			cout<<"Nhap a["<<i<<"]["<<j<<"]:";
			cin>>a[i][j];
		}
}
void Matrix::xuat()
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
void Matrix::nhaptufile(){
	ifstream fi("dauvao1.txt",ios::in);
	fi>>m>>n;
	a=new float*[m];
	for(int i=0;i<m;i++)
		a[i]=new float[n];
		
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			fi>>a[i][j];
	fi.close();				
}
void Matrix::nhap2(){
	cin>>m>>n;
	a=new float*[m];
	for(int i=0;i<m;i++)
		a[i]=new float[n];
		
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
}	
void Matrix::xuatrafile(){
	ofstream fo1;
	fo1.open("ketqua.txt",ios::out);
	fo1<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			fo1<<a[i][j]<<" ";
		fo1<<endl;
	}
	fo1.close();
}
void Matrix::xuat2(){
	cout<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}	
bool kiemtracong(Matrix a, Matrix b){
	return (a.indexcolumn()==b.indexcolumn()&&a.indexrow()==b.indexrow());
}

bool kiemtranhan(Matrix a, Matrix b){
	return (a.indexcolumn()==b.indexrow());
}
Matrix & operator + (const Matrix &x,const Matrix &y){
	static Matrix kq;
	kq.m=x.m;
	kq.n=x.n;
	kq.a=new float*[kq.m];
	for(int i=0;i<kq.m;i++)
		kq.a[i]=new float[kq.n];
 	for(int i=0;i<kq.m;i++)
		for(int j=0;j<kq.n;j++)
			kq.a[i][j]=x.a[i][j]+y.a[i][j];
	return kq;
}
Matrix & operator * (const Matrix &x,const Matrix & y)
{
	static Matrix kq;
	kq.m=x.m;
	kq.n=y.n;
	kq.a=new float*[kq.m];
	for(int i=0;i<kq.m;i++)
		kq.a[i]=new float[kq.n];
	for(int i=0;i<kq.m;i++)
		for(int j=0;j<kq.n;j++)
		{
			kq.a[i][j]=0;
			for(int k=0;k<x.n;k++)
				kq.a[i][j]+=x.a[i][k]*y.a[k][j];
		}
	return kq;
}
void ghidatavaofile(){
	int m,n;
	ofstream fo("dauvao.txt");
	do{
	cout<<"nhap so hang va so cot:";
	cin>>m>>n;
	}while((m<=0)||n<=0);
	srand(time(NULL));
	fo<<m<<" "<<n<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			fo<<rand()%100<<" ";
		}
		fo<<endl;
	}
	fo.close();
}
//float &Matrix::operator[](int i,int j){
//	if(0<=i&&i<n) return a[i][j];
//}
main(){
//	Matrix a,b,c,d;
//	int smt;
//	ghidatavaofile();
//	a.nhaptufile();
//	cout<<"Ma tran A:"<<endl;
//	a.xuatrafile();
//	b.nhaptufile();
//	cout<<"Ma tran B:"<<endl;
//	b.xuatrafile();
//	c=a+b;
//	c.xuatrafile();
//	d=a*b;
//	d.xuatrafile();
	
//	int lc;
//	cout << "Nhan 1 de nhap tu file 0 de bo qua: ";
//	cin >> lc;
//	if(lc){
//		freopen("dauvao.txt", "r", stdin);
//		freopen("ketqua1.txt", "w", stdout);
//	}
//	Matrix c,a,b,d;
//	cout<<"Ma tran A:"<<endl;
//	a.nhap2();
//	a.xuat2();
//	
//	cout<<endl<<"Ma tran B:"<<endl;
//	b.nhap2();
//	b.xuat2();
//	
//	cout<<endl<<"Ma tran ket qua sau khi cong:"<<endl;
//	if(kiemtracong(a,b))
//	{
//	c=a+b;
//	c.xuat();
//	}else 
//	{
//	cout<<"2 ma tran khong thoa man"<<endl;
//	}
//	
//	cout<<endl<<"Ma tran ket qua sau khi nhan:"<<endl;
//	
//	if(kiemtranhan(a,b))
//	{
//	d=a*b;
//	d.xuat();
//	}else 
//	{
//	cout<< endl<<"2 ma tran khong thoa man"<<endl;
//	}
//}

Matrix b;
b.nhap();
b.xuat();
float tmp[100][100];
Matrix::cpy(tmp, b)
cout << Matrix::dinhthuc(tmp , 4);
}










	

