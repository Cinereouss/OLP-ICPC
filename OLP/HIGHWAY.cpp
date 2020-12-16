#include<bits/stdc++.h>

using namespace std;

int n, hMin;
vector <int> arr;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	int temp;
	
	for(int i = 0; i < n; i++){
		cin >> temp;
		arr.push_back(temp);
	}
	sort (arr.begin(), arr.end());
	
	hMin = arr[1] - arr[0];
	
	for(int i = 1; i < n - 1; i++){
		if(hMin > arr[i + 1] - arr[i])
			hMin = arr[i + 1] - arr[i];
	}
	
	cout << hMin;
}
