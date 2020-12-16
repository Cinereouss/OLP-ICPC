#include <bits/stdc++.h>
using namespace std;

string temp;
int a, c;

main(){
	freopen("input.txt", "r", stdin);
	cin >> a >> c;
	bool arr[a][c];
	for(int i = 0; i < a; i++){
		cin >> temp;
		for(int j = 0; j < c; j++){
			if(temp[j] == 'M'){
				arr[i][j] = true;
			}
			else{
				arr[i][j] = false;
			}		
		}
	}
	
	for(int i = 0; i < a; i++){
		for(int j = 0; j < c; j++){
			if(arr[i][j] == true){
				cout << "x ";
			}
			else{
				cout << ". ";
			}		
		}
		cout << endl;
	}
}
