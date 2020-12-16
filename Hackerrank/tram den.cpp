#include <bits/stdc++.h>

using namespace std;

main(){
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	long long k, m, n, tmpn, tmpm, diff;


	while (t--){
		bool ktra = false;
		cin >> k;
		diff = k;
		for(int m = 1; m <= sqrt(2*k); ++m){
			if((2*k-1-m)%(2*m+1) == 0){
				n = (2*k-1-m)/(2*m+1);
				if(n>=m && n-m < diff){
					ktra = true;
					tmpn = n;
					tmpm = m;
					diff = n-m;
				}
			}
		}
		if(!ktra) cout << -1 << " " << -1 << endl;
		else cout << tmpm <<" "<< tmpn << endl;
	}
}
