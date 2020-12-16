#include <bits/stdc++.h>

using namespace std;

const int MAX = 1E6+5;
bool isPrime [MAX];
vector <int> arr;

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
	
	sang(arr, 1E6);
	int input;

	while(cin>>input && input != 0){
		int danhdau = 1; 
		for(int i:arr){
			if(isPrime[input-i]){
				cout << input << " = " << i << " + " << input-i << endl;
				danhdau = 0;
				break;
			}
		}
		if(danhdau) cout << "Goldbach's conjecture is wrong." << endl;
	}
}
