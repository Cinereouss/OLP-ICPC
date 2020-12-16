#include <iostream>

using namespace std;

int power (int a, int n, int mod){
	if(n==0) return 1%mod;
	if(n==1) return a%mod;
	long long tmp = power ( a, n/2, mod);
	if(n % 2 == 0) 
		return tmp*tmp%mod;
	else 
		return (tmp*tmp%mod)*a%mod;
}

main(){
	freopen ("input.txt" , "r", stdin);
	freopen ("output.txt", "w", stdout);
	int B, P, M;
	while(cin >> B >> P >> M){
		cout << power (B,P,M) << endl; 
	}
}
