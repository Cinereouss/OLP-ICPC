#include <bits/stdc++.h>

using namespace std;
	int n;
	
bool ktra(int kt, int a[], int b[]){
	for (int i = 0; i < kt; ++i){
		if(a[kt-i]>=b[n-1-i])
			return false;
	}
	return true;
}
main(){
	freopen("input.txt",  "r", stdin);
//	freopen("output.txt", "w", stdout);
	int tmp;
	cin >> n;
	int a[n];
	int b[n];
	
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a, a+n);
	
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
	sort(b, b+n);
	
	int left = 0;
	int right = n-1;
	int  mid;
	while(left != right){
		mid = (left+right)/2;
		if(ktra(mid, a, b))
			left = mid+1;
		else
			right = mid-1;
	}
	cout << left;
}
