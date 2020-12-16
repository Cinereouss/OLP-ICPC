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

int T1[4*1048999];
int T2[4*1048999];
ll Sum1, Sum2;
int a[1000099];
int n;

void addtree1(int l, int r, int root, int num) {
	if (l < r) {
		int mid = l + (r-l)/2;
		int rl = 2*root;
		int rr = 2*root + 1;
		if (num <= mid) addtree1(l, mid, rl, num); else
						addtree1(mid+1, r, rr, num);
	}
	T1[root]++;
	
}

void addtree2(int l, int r, int root, int num) {
	if (l < r) {
		int mid = l + (r-l)/2;
		int rl = 2*root;
		int rr = 2*root + 1;
		if (num <= mid) addtree2(l, mid, rl, num); else
						addtree2(mid+1, r, rr, num);
	}
	T2[root]++;
}

int count1(int l, int r, int root, int num) {
	if (l == r && r > num) return T1[root]; else {
		if (r==l) return 0;
		int mid = l + (r-l)/2;
		if (num <= mid) return count1(l, mid, root*2, num) + T1[root*2 + 1];
		else return count1(mid+1, r, root*2 + 1, num);
	}
}


int count2(int l, int r, int root, int num) {
	if (l == r && r < num) return T2[root]; else {
		if (r==l) return 0;
		int mid = l + (r-l)/2;
		if (num <= mid) return count2(l, mid, root*2, num);
		else return count2(mid+1, r, root*2 + 1, num) + T2[root*2];
	}
}

int main(){
//	ll t1=time(0);
	freopen("SQ.INP", "r", stdin);
	freopen("SQ.OUT", "w", stdout);
		
	scanf("%d",&n);
	rep(i, 1, n) scanf("%d", &a[i]);
	
	{
	
	int ln = 1;
	while (a[ln] > 0 && ln <= n) {
		addtree1(1, n, 1, a[ln]);
		ln++;
	}
	//printf("left nu: %d",ln);
	int rn = ln+1;
	while (a[rn] > 0 && rn <= n) {
		rn++;
	}
	//printf("right nu: %d",rn);
	int d= rn+1;
	while (d <= n) {
		while (a[d] > 0 && d <=n) {
			Sum1 += count1(1, n, 1, a[d]);
			d++;
			
		}
		if (d <=n) {
			rep(i, ln, rn) if (a[i] > 0) addtree1(1, n, 1, a[i]);
			ln = rn;
			rn = d;
			d++;
		}
	}
	//cout << Sum1 <<" ";	
	}
	//cout << endl;
	{
	
	int ln = 1;
	while (a[ln] < 0 && ln <= n) {
		addtree2(1, n, 1, -a[ln]);
		ln++;
	}
	//printf("left nam: %d",ln);
	int rn = ln+1;
	while (a[rn] < 0 && rn <= n) {
		rn++;
	}
	//printf("right nam: %d",rn);
	int d= rn+1;
	while (d <= n) {
		while (a[d] < 0 && d <=n) {
			Sum2 += count2(1, n, 1, -a[d]);
			d++;
			
		}
		if (d <=n) {
			rep(i, ln, rn) if (a[i] < 0) addtree2(1, n, 1, -a[i]);
			ln = rn;
			rn = d;
			d++;
		}
	}
	//cout << Sum2 <<" ";	
	}
	
	cout << Sum1 << " " << Sum2 << endl;
//	ll t2 = time(0);
//	cout << t2 << endl;
	return 0;
}
