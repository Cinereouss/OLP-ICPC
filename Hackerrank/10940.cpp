#include <bits/stdc++.h>

using namespace std;
vector<int> arr;

main(){
	int n, count = 0;
	while(cin >> n){
	if(n==0) break;
	for(int i = 1; i <= n; ++i)
		arr.push_back(i);
	while(true){
		if(arr.size() % 2 == 0){
				for(int i = arr.size()-2; i >= 0; i-=2)
					arr.erase(arr.begin()+i);
		}
		else{
				for(int i = arr.size()-3; i >= 0; i-=2)
					arr.erase(arr.begin()+i);
				arr.insert(arr.begin(), arr[arr.size()-1]);
				arr.erase(arr.begin()+arr.size()-1);
		}
		if(arr.size() == 1) break;
	}
	cout <<  arr[0] << endl;
	arr.clear();
}
}

