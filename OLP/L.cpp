#include <bits/stdc++.h>

using namespace std;

int n, temp,demLe = 0, S;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp % 2 == 0)
			S += temp/2;
		else {
			S += temp/2;
			demLe++;
		}
	}
	if(demLe % 2 == 0){
		S+= demLe/2;
	}
	else
		S+= demLe/2 + 1;
		
	cout << S;
}
