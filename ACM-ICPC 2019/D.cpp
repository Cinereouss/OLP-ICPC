#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2011110, M = 2011110;
const int base = M;
int  s[M + M];
int a[M + M];
int prime[M + M];
int n;

void eratos() {
    for(int i = 2; i < N; ++i)
        prime[i] = 1;
    for(int i = 2; i * i <= N; ++i) {
        if(prime[i]) {
            for(int k = i + i; k <= N; k+=i)
                prime[k] = 0;
        }
    }
}

int c[1000010], d[1000010];
int f[1000010];
int B[M + M];

void update(int x){
    while(x < 2 * M){
        B[x] ++;
        x += x & -x;
    }
}

int get(int x){
    int res = 0;
    while(x){
        res += B[x];
        x -= x & -x;
    }
    return res;
}

signed main() {
    eratos();
    int cur = 0;
    long long ans = 0;
    cin >> n;
    update(5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = c[i - 1];
        d[i] = d[i - 1];
        if(prime[a[i]] == 1) c[i]++;
        else d[i]++;
        f[i] = c[i] - d[i] + 210000;
        ans += get(f[i]);
        update(f[i]);
    }
    cout << ans;
}
