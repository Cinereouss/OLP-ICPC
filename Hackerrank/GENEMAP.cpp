#include <bits/stdc++.h>

using namespace std;

vector<string> vs;
map<int, int> m1, m2;
string s;

int MOD = 1E9 + 7;

typedef long long llong;

llong sub (llong a, llong b) {
	if (a >= b) return a - b;
	return a + MOD - b;
}


//llong getHash (int k) {
//	llong hash = 0;
//	for (int i = 0; i < k; ++i) {
//		hash = hash * 31 + s[i] - 'a' % MOD;
//	}
//	
//	for	
//}

int main() {
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	
	
	for(int i = 0; i < n; ++i) {
		cin >> s;
		if (s.length() >= k) {
			m1[1]++;
		}
		if (s.length() >= k + 1) {
			m2[1]++;
		}
	}
	
	long long total = 0;
	for (auto it = m1.begin(); it != m1.end(); ++it) {
//		cout << it->first << ":" << it->second << endl;
		long long count = it->second;
		if (count >= 2) {
			total += count * (count - 1) / 2 % MOD;
			total %= MOD;
		}
	}
//	cout << total << endl;
	for (auto it = m2.begin(); it != m2.end(); ++it) {
//		cout << it->first << ":" << it->second << endl;
		int count = it->second;
		if (count >= 2) {
			total = sub(total, count * (count - 1) / 2 % MOD);
		}
	}
	cout << total << endl;
	return 0;
}

