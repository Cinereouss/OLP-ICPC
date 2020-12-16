#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

const int MAX_SIZE = 1E3+7;

llong L, U;
bool isPrime[MAX_SIZE];
vector <int> p;
vector <int> e;
vector<llong> arr;
vector <int> result;

int mu(int a, int n){
	if(n == 2)	return a*a;
	if(n == 1)	return a;
	if(n == 0) 	return 1;
	int tmp = mu(a, n/2);
	return n%2 ? tmp*tmp : tmp*tmp*a;
}

void quaylui(int i, int k, int v){
	if(i == k)	result.push_back(v);
	else{
		for(int somu = 0; somu <= e[i]; ++somu)
			quaylui(i+1, k, v*mu(p[i], somu));
	}
}
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
	//freopen("output.txt", "w", stdout);
	
	int N, L, U;
	cin >> N;
	sieve (arr, 1E3+7);
	
	while(N--){
		cin >> L >> U;
		
		int value, count = 0;
		for(int i = L; i <= U; ++i){
			int tong = 1;
			int cpy_i = i;
			for(int j = 0; j < arr.size(); ++j){
				int dem=0;
				while(cpy_i % arr[j] == 0){
					cpy_i/=arr[j];
					dem++;
				}
				tong*=(dem+1);
			}	 
			if(tong > count){
				count = tong;
				value = i;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, value, count);
		
		int n = value;
		for(int j = 0; j < arr.size(); ++j){
			if (arr[j] > sqrt(n)) break;
				int dem=0;
				while(n % arr[j] == 0){
					n /= arr[j];
					dem++;
				}
				if(dem){
					p.push_back(arr[j]);
					e.push_back(dem);
				}
			}
		if(n>1){
		p.push_back(n);
		e.push_back(1);		
		}

	
		quaylui(0, p.size(), 1);
		for(int ii: result)
			cout << ii << " ";
	}
}
