#include <bits/stdc++.h>

using namespace std;
const int MAX = 20000000;

bool arr_1[MAX];

vector <int> snt;

void sangnguyento (vector<int> &arr){
	memset (arr_1, true, sizeof arr_1);
	
	for(int i = 2; i <= MAX; ++i)
		if(arr_1[i])
			for (int j = i * i; j <= MAX; j += i)
				arr_1[j] = false;
		
	for (int i = 2; i < MAX; ++i)
		if (arr_1[i])
			arr.push_back(i);
}

main(){
	sangnguyento(snt);
	cout << snt.size();
}
		
	
