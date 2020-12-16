#include <bits/stdc++.h>

using namespace std;


bool isPrime [10000000];

vector <int> prime;

void sieve (vector<int> & arr, int range) {
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	
	for (int i = 2, limit = range; i < limit; ++i) {
		if (isPrime[i]) {
			for (int j = i * i; j <= range; j += i) {
				isPrime[j] = false;
			}
		}
	if(i == limit - 1) cout<<limit<<endl;
	}
	
	for (int i = 2; i < range; ++i) {
		if (isPrime[i]) {
			arr.push_back(i);
		}
	}
}

main(){
	sieve(prime, 20000000);
	cout<<sizeof(isPrime)<<endl;
	cout<< prime.back();
}
