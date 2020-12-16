#include <bits/stdc++.h>

using namespace std;

vector <int>A;
vector <int>B;

bool binarySearch(int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
        if (B[mid] == x)   
            return true; 
        if (B[mid] > x)  
            return binarySearch(l, mid-1, x); 
  		else
        	return binarySearch(mid+1, r, x); 
   } 
   return false; 
} 

main(){
	int sizeA, sizeB;
	int tg;
	freopen("input.txt",  "r", stdin);
//	freopen("output.txt", "w", stdout);
	while(cin >> sizeA >> sizeB){
		int dem = 0;
		for(int i = 0; i < sizeA; ++i){
			cin >> tg;
			A.push_back(tg);
		}
		
		for(int i = 0; i < sizeB; ++i){
			cin >> tg;
			B.push_back(tg);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		for(int i = 0 ; i < A.size() ; ++i)
			if(A[i]!=A[i+1])
				if(binarySearch(0,B.size(),A[i])) dem++;
			else 
				continue;
		cout << dem;
	}
}
