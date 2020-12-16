#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

map <char , int> mp;
float xuly(float a){
	float b = a%100;
	return(a = a/100+ b);	
}
main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int cases;
	cin >> cases;
	
	for(int i = 0; i < cases; ++i) {
		int nchars;
		cin >> nchars;
		
		char key;
		int value;
		for (int i = 0; i < nchars; ++i){
			char char_tmp;
			int int_tmp;
			cin>>char_tmp>>int_tmp;
			mp[char_tmp] = int_tmp;
		}
		
		int lines;
		cin >> lines;
		string tmp;
		float tong = 0;
		cin.ignore('\n');
		for(int i = 0; i < lines; ++i){
			getline(cin, tmp);
			for(int i = 0; i < tmp.length(); ++i)
				tong += mp[tmp[i]];
		}
		cout <<  tong / 100 << tong % 100 <<"$";
	}

}
