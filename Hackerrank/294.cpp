#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

const int MAX_SIZE = 1E3+7;

llong L, U;
bool isPrime[MAX_SIZE];
vector<llong> arr;

void sieve (vector<llong> & arr, int range) {
	memset(isPrime, true, sizeof isPrime);
	
	isPrime[0] = isPrime[1] = false;
	
	for (int i = 2, limit = range; i < limit; ++i) {
		if (isPrime[i]) {
			for (int j = i * i; j <= range; j += i) {
				isPrime[j] = false;
			}
		}
	}
	
	for (int i = 2; i < range; ++i) {
		if (isPrime[i]) {
			arr.push_back(i);
		}
	}
}

main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N, L, U, dem, tong, max, value;
	cin >> N;
	sieve (arr, 1E3+7);
	
	while(N--){
		cin >> L >> U;
		for(int i = L; i <= U; ++i){
			tong = 1;
			int cpy_i = i;
			for(int j = 0; j < arr.size(); ++j){
				dem=0;
				while(cpy_i % arr[j] == 0){
					cpy_i/=arr[j];
					dem++;
				}
				tong*=(dem+1);
			}	 
			if(tong > max){
				max = tong;
				value = i;
			}
		}
	printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, value, max);
	max = value = 0;
	}
}
