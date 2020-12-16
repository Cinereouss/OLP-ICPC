#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

const long long MAX_SIZE = 2E7;

bool isPrime[MAX_SIZE];
vector<llong> primeFactors;
vector<llong> hello;

void sieve (vector<llong> & arr, long long range) {
	memset(isPrime, true, sizeof isPrime);
	
	isPrime[0] = isPrime[1] = false;
	
	for (int i = 2, limit = sqrt(range); i < limit; ++i) {
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

int main()
{
	cout << MAX_SIZE;
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	sieve(primeFactors, 2E7 );
//	for(int i = 1; i < primeFactors.size(); ++i)
//		if (primeFactors[i]-primeFactors[i-1] == 2)
//			hello.push_back(primeFactors[i-1]);
//	int L;
//	while(cin >> L) {
//		llong tmp = hello.at(L-1);
//		cout << "(" << tmp << ", " << tmp + 2 << ")" << endl;
//	}
//	
//	return 0;
}
