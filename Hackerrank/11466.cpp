#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 31622776+2;

bool test[MAX_SIZE];
vector <long long> snt;

void sangnguyento(vector <long long> &arr, int range ){
	
	memset (test, true, sizeof test);
	test[0] = test [1] = false;
	
	for (int i=2, limit = sqrt(range) ;i <= limit; ++i)
		if(test[i])
			for(int j = i*i; j < range; j+=i)
				test[j]=false;
				
	for(int i = 0; i < range; ++i )
		if(test[i])
			arr.push_back(i);
}

main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	sangnguyento(snt, MAX_SIZE);
	
	long long n, input;
	
	while(cin >> input && input != 0){
		long long tmp = -1, dem = 0;	
		int i = 0;
		n = abs(input);
		for(int i: snt){
			if(i>n){
				break;
			}
			if(n%i==0){
				dem ++;
				tmp = i;
				while(n%i==0)
					n/=i;
			}
		}
		if(n>1){
			dem++;
			tmp = n;
		}
		
		dem >= 2 ? cout << tmp << endl : cout << "-1" << endl;
	}
}

