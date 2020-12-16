#include <bits/stdc++.h>

using namespace std; 

//map <int, bool> mp;

const int MAXN = 1E6+7;

bool isPrime[MAXN];

vector<int> Nguyento;
vector<int> tmp_Nguyento;

void sieve ( int range ){
		
	memset(isPrime, true, sizeof isPrime);  // cap  phat mot mang co ta ca value = true
	
	isPrime [0] = isPrime[1] = false;
	
	for(int i = 2, limit = sqrt(range); i < limit; ++i)
		if(isPrime[i]){
			for(int j = i*i; j < range; j += i){
				isPrime[j]=false;
			}
		Nguyento.push_back(i);
		}
}

main(){
	int u, l;
	cout << "Nhap L - U: ";
	cin >> l >> u;
	for (auto s : Nguyento) {
		if(l<=Nguyento[s] && Nguyento[s]<<l)
			tmp_Nguyento.push_back(Nguyento[s]);
	}

	for (auto s : tmp_Nguyento)
		cout << tmp_Nguyento[s]<< " ";
	
}
