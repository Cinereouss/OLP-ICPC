#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

#define fi first
#define se second

#define rep(i, l, r) for(int i = l; i <=r; i++)
#define repd(i, r, l) for (int i = r; i >= l; i--)

int A[1000099];
int n;
int lmin;

int main(){
	freopen("HIGHWAY.INP", "r", stdin);
	freopen("HIGHWAY.OUT", "w", stdout);
	
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &A[i]);
	sort(A+1, A+1+n);
	lmin = A[2] - A[1];
	rep(i, 2, n) 
		if (A[i] - A[i-1] < lmin) lmin = A[i] - A[i-1];
	
	printf("%d\n", lmin);
	return 0;
}
