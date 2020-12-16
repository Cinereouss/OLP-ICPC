#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1E6 + 7;

bool isPrime[MAX_SIZE];
vector<int> primeFactors;
int e[MAX_SIZE];

int luythua(int a, int n){
	if(n==0) return 1;
	if(n==1) return a;
	int tmp = luythua(a, n/2);
	return n%2? tmp*tmp*a : tmp*tmp;
}
void locnguyento(int n){
	for(auto p : primeFactors){
		if(p>n) break;
		int power = 1, mu = 0;
		while((long long) power * p <= n){
			power *=p;
			mu++;
		}
		e[p]=mu;
	}
}
void sieve (vector<int> & arr, int range) {
	memset(isPrime, true, sizeof isPrime);
	
	isPrime[0] = isPrime[1] = false;
	
	for (int i = 2, limit = sqrt(range); i < limit; ++i) {
		if (isPrime[i]) {
			for (int j = i * i; j < range; j += i) {
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
	sieve(primeFactors, MAX_SIZE); 
	int n;
	while(cin >> n && n != 0){
		locnguyento(n);
		int S=1;
		if(e[2] > 0 && e[5] > 0){
			int tmp = min(e[2], e[5]);
			e[2] -= tmp;
			e[5] -= tmp;
		}
		for(auto p : primeFactors) {
			if (p > n) break;
			if(e[p]>0){
				int tmp = luythua(p, e[p]);
				S *= tmp;
				S %= 10;
			}
		}
		cout << S <<endl;
	}
}
	
