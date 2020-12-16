#include <iostream>

using namespace std;

main(){
	int n;
	cin >> n;
	int arr[n][2];
	
	arr[1][0] = 1;
	arr[1][1] = 1;
	
	arr[2][0] = 2;
	arr[2][1] = 2;
	
	if(n > 2)
		for(int i = 3; i <= n; i++){
			arr[i][0] = (arr[i-1][0] + arr[i-1][1] * arr[i-1][1]) % 998244353;
			arr[i][1] = (arr[i-1][1] + arr[i-2][1]) % 998244353;
		}
	cout << arr[n][0];
}
