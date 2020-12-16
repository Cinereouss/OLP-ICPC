#include <bits/stdc++.h>
 
#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)
 
#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 
 
using namespace std;
 
const int MAXN = 1E6 + 7;
const int MAXL = 1E9;
int n, l[MAXN];
 
long long abs (long long x) {
    return x < 0 ? -x : x;
}
 
long long calculate (int pos) {
    long long total = 0;
    REP(i, 0, n) {
        // total += abs(pos - l[i]);
        total += min(abs(pos - l[i]), abs(l[i]));
    }
    return total;
}
 
long long ternary_search (int l1, int l2, int num_step) {
    int left = l1;
    int right = l2;
 
    REP(step, 0, num_step) {
        int m1 = left + (right - left) / 3;
        int m2 = right - (right - left) / 3;
 
        if (calculate(l[m1]) < calculate(l[m2])) {
            right = m2;
        }
        else {
            left = m1;
        }
    }
 
    long long ans = calculate(l[left]);
 
    FOR(x, left+1, right) {
        ans = min(ans, calculate(l[x]));
    }
 
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("input.txt", "r", stdin);
 
    cin >> n;
 
    REP(i, 0, n) {
        cin >> l[i];
    }
 
    sort(l, l + n);
 
    int idx = upper_bound(l, l+n, -1) - l;
    long long ans = ternary_search(0, idx, 88);
    if (idx + 1 < n) {
        ans = min(ans, ternary_search(idx+1, n - 1, 88));
    }
    cout << ans << endl;
    // cout << "--------------\n";
    // REP(i, 0, n) {
    //     cout << calculate(l[i]) << "(" << l[i] << ")" << endl;
    // }
    return 0;
}
