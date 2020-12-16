#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n;
vector<int> vi;
bool ok;

main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	while(cin>>n){
		vi.clear();
		for(int i = 0, tmp; i<n; ++i){
			cin >> tmp;
			vi.push_back(tmp);
		}
		for(int i = 0; i<vi.size()-1; ++i){
			int diff = abs(vi[i] - vi[i+1]);
			if(1 <= diff && diff <= n-1)
				ok = true;
			else{
				ok = false;
				break;
			}
	}
	
	if(n==1 || ok)
		cout << "Jolly" << endl;
	else 
		cout << "Not jolly" << endl;
	
	}
	
	
}
