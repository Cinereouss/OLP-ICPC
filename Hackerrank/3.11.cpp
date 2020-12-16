#include <bits/stdc++.h>

using namespace std;

main(){
	freopen("input.txt",  "r", stdin);
//	freopen("output.txt", "w", stdout);
	int  n, tmp;
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
	
	int dem  = 0;
	tmp = n-1;
	
	for(int i =  n-1; i >= 0; --i){
		while (a[tmp] >= b[i]){
			tmp--;
			if(a[tmp]<b[i]) {
			dem++;
			break;
			}
		}
	}
	
	cout << dem;
}
