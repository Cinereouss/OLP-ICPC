#include <iostream>
#include <memory.h>
#include <math.h>

using namespace std;


#define REP(i, a, b)  for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)  for(int i = a, _b = b; i <= b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= b; --i)

const int MAXN = 1E6 + 7;

int a[MAXN], count[MAXN];
bool isPrime[MAXN];

void sieve (int limit) {
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = false;
	isPrime[1] = false;
	FOR(i, 2, sqrt(limit)) {
		if(isPrime[i]) {
			for(int j = i*i; j < limit; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int find (int i, int n) {
	int l = i, r = n;
	while(l < r) {
		int m = (l + r + 1) / 2;
		if (count[m] < 0) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	return l;
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   //freopen("input.txt", "r", stdin);

   int n;
   cin >> n;
   
   FOR(i, 1, n) {
       cin >> a[i];
   }
   
   sieve(1e6);
   
   count[0] = 0;
   FOR(i, 1, n) {
   	if (isPrime[a[i]]) {
   		count[i] = count[i-1] + 1;
   	}
   	else {
   		count[i] = count[i-1] - 1;
   	}
   }
   
   int x = 0;
   
   FOR(i, 1, n) {
   	if (!isPrime[a[i]]) {
   		int j = find(i, n);
   		x += (j - i + 1);
   	}
   }
   cout << max(n*(n+1)/2 - x  - x*(x-1)/2, 0) << endl;
   return 0;
}

