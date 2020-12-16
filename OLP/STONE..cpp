#include<bits/stdc++.h>

using namespace std;

int m, n, k, c, p, d, q;
vector<int> arr;

int decToBinary(int n) 
{ 
    for (int i = 31; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) 
            cout << "1"; 
        else
            cout << "0"; 
    } 
} 

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	cin >> m >> n >> k;
//	int temp;
//	
//	for(int i = 0; i < m; i++){
//		cin >> temp;
//		arr.push_back(temp);
//	}
//	
//	for(int i = 0; i < n; i++){
//		cin >> c >> p >> d >> q;
//	}

cin n;
decToBinary(n);
}
