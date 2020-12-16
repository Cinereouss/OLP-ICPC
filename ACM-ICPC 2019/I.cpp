#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 3 * 101110;
map <int, int> mp;
int gcd[N], A[N], ne[N];
int n;

int GCD(int u,int v) {
    return v == 0 ? u : GCD(v, u % v);
}

signed main() {
    //freopen("task.inp", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> A[i];
    gcd[n] = A[n];
    ne[n] = n + 1;
    mp[A[n]]++;
    for(int i = n - 1; i >= 1; --i) {
        gcd[i] = A[i];
        ne[i] = i + 1;
        int u = i, k = i;
        while(u <= n) {
            while(k <= n && gcd[k] % gcd[u] == 0)
                k = ne[k];
            ne[u] = k;
            //cout << k << " " << u << " " << gcd[u] << " " << mp[gcd[u]] << endl;
            mp[gcd[u]] += k - u;
            //cout << i << " " << u << " " << k << " " << gcd[u] << " " << mp[2] << endl;
            gcd[k] = GCD(gcd[k], gcd[u]);
            u = k;
        }
    }
    int q, u;
    cin >> q;
    while(q--) {
        cin >> u;
        cout << mp[u] << endl;
    }
}
