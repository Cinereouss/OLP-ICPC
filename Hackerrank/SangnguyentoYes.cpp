#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

const int MAX_SIZE = 1E6+7;

llong L, U;
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
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	// b1: Sang doan [0, sqrt(U)]
	sieve(primeFactors, 46464); // sqrt(U) <= sqrt(2^31) <= 46464
	while(cin >> L >> U) {
		L = max(2LL, L);
		memset(isPrime, true, sizeof isPrime);
		// b2: Sang doan [L, U]
		for (auto p: primeFactors) {
			llong bound = max(2LL * p, (L + p - 1) / p * p);
			for (llong i = bound; i <= U; i += p) {
				isPrime[i - L] = false;
			}
		}
		
		for (llong i = L; i <= U; ++i) {
			if (isPrime[i - L]) {
				primes.push_back(i);
//				cout << i << endl;
			}
		}
		
		if (primes.size() >= 2) {
			int pmin = 1, pmax = 1;
			for (int i = 1; i < primes.size(); ++i) {
				if (primes[i] - primes[i-1] < primes[pmin] - primes[pmin-1]) {
					pmin = i;
				}
				if (primes[i] - primes[i-1] > primes[pmax] - primes[pmax-1]) {
					pmax = i;
				}
			}
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n",
			primes[pmin-1], primes[pmin],
			primes[pmax-1], primes[pmax]
			);
		}
		else {
			printf("There are no adjacent primes.\n");
		}
		primes.clear();
	}
	
	return 0;
}
