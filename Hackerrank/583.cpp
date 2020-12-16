#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 50000;
bool isPrime [MAX_N];

vector <int> arr;
vector <int> tmp;



void sang(vector <int> &arr , int range){

	memset(isPrime, true, sizeof isPrime );
	isPrime[0] = isPrime[1] = false;
	
	for (int i = 2, limit = sqrt(range); i <= limit; ++i)
		if(isPrime[i])
			for(int j = i*i; j < range; j+=i)
				isPrime[j] = false;	
				
	for(int i = 0; i < range; ++i)
		if(isPrime[i])
			arr.push_back(i);
}

main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	sang(arr, MAX_N);
	
	int n, cpy_n;
	while(cin >> n && n !=0){
		cpy_n = n;
		
		if(n < 0){
			n= abs(cpy_n);
			tmp.push_back(-1);
		}
		
		for(int i = 0; arr[i] <= sqrt(n); ++i){
			
			while(n % arr[i] == 0){
				tmp.push_back(arr[i]);
				n/=arr[i];
			}
		} 
		if ( n > 1 ) tmp.push_back(n);
		cout << cpy_n <<" = ";
		for(int i = 0; i < tmp.size(); ++i){
			if(i == tmp.size()-1){
				cout << tmp.at(i) << endl;
				break;
			}
			cout << tmp.at(i) << " x ";
		}
	tmp.clear();
	}	
}	
	
