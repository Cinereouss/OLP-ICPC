#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

const int MAX_SIZE = 1E6+7;

llong L;
bool isPrime[MAX_SIZE];
vector<llong> primeFactors; // cac so nguyen to trong doan [0,sqrt(U)]
vector<llong> primes; // cac so nguyen to trong doan [L, U]

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

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	// b1: Sang doan [0, sqrt(U)]
	sieve(primeFactors, 1000000); // sqrt(U) <= sqrt(2^31) <= 46464
	cout<<primeFactors.back();
}
