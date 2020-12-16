#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <bitset>

using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

#define fi first
#define se second

#define rep(i, l, r) for(int i = l; i <=r; i++)
#define repd(i, r, l) for (int i = r; i >= l; i--)
//bitset<10*1000000> bs;
short int bs[10*1048999];
short int tree[4*10*1048999];

//bitset<4*10*1000000> tree;

int m, n, k;

int td(int x, int y) { return x*8 + (7-y);}

void init(int l, int r, int root) {
	if (l == r) {
		tree[root] = bs[l];
	}else {
		int mid = l + (r-l)/2;
		init(l, mid, root*2);
		init(mid+1, r, root*2+1);
		tree[root] = tree[root*2] || tree[root*2+1];
	}
}

void clear(int l, int r, int root, int froml, int tor) {
	//printf("clearing l: %d r: %d\n", l, r);
	if (froml <= l && r <= tor) {
		tree[root] = 0;
	} else {
		int mid = l + (r-l)/2;
		if ( (l <= tor && tor <= mid) || (l <= froml && froml <= mid) 
		|| (froml <= l && mid <= tor))
		 {
			if (tree[root*2] == 1)
				clear(l, mid, root*2, froml, tor);
		}
		if ( (mid+1 <= tor && tor <= r) || (mid+1 <= froml && froml <= r) 
		|| (froml <= mid+1 && r <= tor)
		) {
			if (tree[root*2+1] == 1)
				clear(mid+1, r, root*2 +1, froml, tor);
		}
		tree[root] = tree[root*2] || tree[root*2+1];
			
	}
}

bool check(int l, int r, int root, int from, int to) {
	if (from <= l && r <= to) return tree[root];
	else {
		int mid = l + (r-l)/2;
		if ( (l <= to && to <= mid) || (l <= from && from <= mid) 	|| (from <= l && mid <= to))
			if (tree[root*2] == 1) {
				bool rl = check(l, mid, root*2, from, to);
				if (rl) return rl;
			}
		if ( (mid+1 <= to && to <= r) || (mid+1 <= from && from <= r) || (from <= mid+1 && r <= to)
		)
			if (tree[root*2+1] == 1) {
				bool rl=check(mid+1, r, root*2 +1, from, to);
				if (rl) return rl;
			}
			
		return 0;
	}
}

void inn(int l, int r, int root) {
	if (l==r) {
		if (tree[root]) printf("1 "); else printf("0 ");
	} else {
		if (tree[root] == 0) rep(i, l, r) printf("0 "); else {
		
		int mid = l + (r-l)/2;
		inn(l, mid, root*2);
		inn(mid+1, r, root*2+1);
		}
	}
}

int main(){
	freopen("STONE.INP", "r", stdin);
	freopen("STONE.OUT", "w", stdout);
		
	scanf("%d %d %d", &m, &n, &k);
	rep(i, 0, m-1) {
		int v;
		scanf("%d", &v);
		rep(k, 0, 7) bs[td(i, k)] =  ((1 << k) & v) > 0; 
	}
	
	/*
	rep(i, 0, m*8-1) 
		if (bs[i])
			printf ("1 "); else printf("0 ");
	cout << endl;
	*/
	
	init(0, 8*m - 1, 1);
	
	/*
	printf("n: %d\n", n);
	inn(0, 8*m-1, 1);
		cout << endl;
	*/
	
	rep(i, 1, n) {
		int c, p, d, q;
		scanf("%d %d %d %d", &c, &p, &d, &q);
		int td1 = td(c, p);
		int td2 = td(d, q);
		//printf("td1: %d td2: %d\n", td1, td2);
		clear(0, 8*m - 1, 1, td1, td2);
		//inn(0, 8*m-1, 1);
		//cout << endl;
	}

	rep(i, 1, k) {
		int c, p, d, q;
		scanf("%d %d %d %d", &c, &p, &d, &q);
		int td1 = td(c, p);
		int td2 = td(d, q);
		
		if (check(0, 8*m - 1, 1, td1, td2)) printf("YES\n");
		else printf("PASS\n");
	}

	return 0;
}
