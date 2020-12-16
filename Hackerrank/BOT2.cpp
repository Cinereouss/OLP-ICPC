#include <bits/stdc++.h>

using namespace std;

vector <int> a;
vector <int> gt;
vector <int> l;
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int n, tmp; 
	cin >> n;
	
	while(n--){
		cin >> tmp;
		a.push_back(tmp);
	}
	
	 gt[0] = a[0];
	 l[0] = 1;
	int vt;
	for(int i = 1; i <= n; ++i)
		if(max(gt[i-1], gt[i-1]+a[i]) == gt[i-1]){
			gt[i] = gt[i - 1];
			l[i] = l[i-1];
		}
		else{
			vt = i;
			gt[i] = gt[i - 1] + a[i];
			l[i] = i;
		}		
	
	cout << vt - l[vt] - 1 << " " << l[vt]  << " " << gt[vt];
}

