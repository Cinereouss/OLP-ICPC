#include <bits/stdc++.h>

using namespace std;

int vtri_max, best, max_gt;
int ip[20];
bool trangthai[20], vt[20];

void quaylui(int vtri){
	if(sobuoc > max_gt) return;
	if(vtri == vtri_max) {
		if(tong > best){
			best = tong;
			for (int i = 0; i < vtri_max; i++)
				vt[i] = trangthai[i];
		}
	}	
		
	else{
		trangthai[vtri]=true;
		quaylui(vtri+1, tong+ip[vtri]);
		trangthai[vtri]=false; 
		quaylui(vtri+1, tong);
	}
}

main(){
	freopen("input.txt",  "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	while( cin >> max_gt >> vtri_max ){
		memset(trangthai, false, sizeof trangthai);
		memset(vt, false, sizeof trangthai);
		for(int  i = 0; i < vtri_max; ++i){
			cin >> ip[i];
		}
		
		best = 0 ;
		
		quaylui(0, 0);
		
		for(int i = 0; i < vtri_max; i++)
			if(vt[i])
				cout << ip[i]<< " ";
		cout << "sum:" << best;

	}
}
