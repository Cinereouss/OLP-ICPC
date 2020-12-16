#include <bits/stdc++.h>

using namespace std;

const int MAX = 1E6 + 10;

vector <int> vt;
int f[MAX];
int l[MAX];

main(){
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int n, tmp, p = 0, q = 0;
	cin >> n;
	
	while(cin >> tmp){
		vt.push_back(tmp);
	}

// Duyet trau: 	
//	for(int i = 0; i < vt.size(); ++i){
//		int tong = vt.at(i);
//		for(int j = i+1; j <vt.size(); ++j){
//			tong+=vt.at(j);
//			if(tong > max){
//				max =  tong;
//				p = i;
//				q = j;
//			}
//		}
//	}
//	cout << p+1 << " " << q+1 << " " << max;
		
		f[0] = vt.at(0);
		l[0] = 1;
		
	for(int i = 1; i < vt.size(); ++i){
		f[i] = max(vt.at(i), f[i-1]+ vt[i]);
		if(f[i] == vt.at(i))
			l[i] = 1;
		else 
			l[i] = l[i-1]+1;
	}
	
//	int max2 = 0;
	int vtt = 0;
	
	for(int i = 0; i < n; ++i){
		if(f[i] > f[vtt]){
			vtt = i;
		}
	}
	
	cout << vtt - l[vtt] +2 << " " << vtt + 1 << " " << f[vtt]; 
}
