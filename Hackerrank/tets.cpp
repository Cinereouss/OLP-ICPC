#include <iostream>

using namespace std;

main(){
	freopen("input.txt" , "r", stdin);
	freopen("output.txt" , "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string a;
	
	while(getline(cin, a))
		cout << endl <<  a << " dong: " << endl; 
}
