#include <bits/stdc++.h>

using namespace std;

int a[2000];

int main(){
	int n, T1=0, T2=0, idx=0, temp;
	cin>>n;
	
	for(int i = 0; i<n; i++){
		cin>>temp;
		if(temp%2){
			a[idx++] = temp;
		}else{
			a[idx++] = temp/2;
			a[idx++] = temp/2;
		}
	}
	
	sort(a,a+idx, greater<int>());
	for(int i=0; i<idx; i++){
		if(T1<=T2){
			T1+=a[i];
		}else{
			T2+=a[i];
		}
	}
	
	cout<<max(T1,T2);
	
}
