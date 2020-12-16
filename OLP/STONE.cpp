#include<bits/stdc++.h>

using namespace std;

int m, n, k, c, p, d, q, arr[1000000];

int cutBinary(int n, int x, bool type){
	int rt = 0, temp[8];
	
	for (int i = 7; i >= 0; i--) { 
    	int k = n >> i; 
        if (k & 1) 
            temp[i] = 1;
        else
            temp[i] = 0;
    } 
    
	if(type){
		for (int i = 7; i >= 0; i--){
			if( i <= x)
				temp[i] = 0;
			else
				if(temp[i] == 1)
					rt += pow(2, i);
		}		
	}
	else{
		for (int i = 0; i <= 7; i++){
			if(i < x){
				if(temp[i] == 1)
					rt += pow(2, i);
			}
			else
				temp[i] = 0;
		}
	}
	return rt;
}

int cutBinary2(int n, int p, int q){
	int rt, temp[8];
	
	for (int i = 7; i >= 0; i--) { 
    	int k = n >> i; 
        if (k & 1) 
            temp[i] = 1;
        else
            temp[i] = 0;
    } 
	for (int i = 7; i >= 0; i--){
		if( i >= p && i <= q)
			temp[i] = 0;
		else
			if(temp[i] == 1)
				rt += pow(2, i);
	}
	return rt;
}

bool proc(int c, int p, int d, int q) 
{ 
	bool check = false;
	if(c == d){
		int temp = cutBinary2(arr[c],p,q);
		if(arr[c] != temp){
				check = true;
				arr[c] = temp;
			}
	}
	else {
		for(int i = c + 1; i < d; i++)
			if(arr[i] != 0){
				check = true;
				arr[i] = 0;
			}
		int leftBinary = cutBinary(arr[c], p, true);
		int rightBinary = cutBinary(arr[d], q, false);
		if(arr[c] != leftBinary){
			arr[c] = leftBinary;
			check = true;
		}
		if(arr[d] != rightBinary){
			arr[d] = rightBinary;
			check = true;
		}
	}
	return check;
} 

int main(){
	freopen("STONE.INP", "r", stdin);

	cin >> m >> n >> k;
	
	for(int i = 0; i < m; i++){
		cin >> arr[i];
	}
	
	for(int i = 0; i < n; i++){
		cin >> c >> p >> d >> q;
		cout << proc(c,p,d,q);
	}
	freopen("STONE.OUT", "w", stdout);
	for(int i = 0; i < k; i++){
		cin >> c >> p >> d >> q;
		if(proc(c,p,d,q))
			cout << "YES" << endl;
		else
			cout << "PASS" << endl;
	}
	
}
