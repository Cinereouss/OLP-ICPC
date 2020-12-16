#include <bits/stdc++.h>

using namespace std;

const int N = 10110;
int D[N], T[N];
int n;

class Interval {
    vector <int> t, f;
    int n;
    void pushDown(int i) {
        if (f[i] == 0) return;
        t[i*2] += f[i];
        t[i*2+1] += f[i];
        f[i*2] += f[i];
        f[i*2+1] += f[i];
        f[i] = 0;
    }

    void update(int i, int lo, int hi, int l, int r, int value) {
        if (lo > r || hi < l) return;
        if (lo >= l && hi <= r) {
            t[i] += value;
            f[i] += value;
            return;
        }
        pushDown(i);
        int mid = (lo + hi)>>1;
        update(i*2, lo, mid, l, r, value);
        update(i*2+1, mid+1, hi, l, r, value);
        t[i] = max(t[i*2], t[i*2+1]);
    }

    int get(int i, int lo, int hi, int l, int r) {
        if (lo > r || hi < l) return 0;
        if (lo >= l && hi <= r)
            return t[i];
        pushDown(i);
        int mid = (lo + hi)>>1;
        return max(get(i * 2, lo, mid, l, r), get(i*2+1, mid + 1, hi, l, r));
    }

public:
    Interval(int _n) {
        n = _n;
        t.resize(4 * n + 10, 0);
        f.resize(4 * n + 10, 0);
    }

    void update(int l, int r, int value) {
        update(1, 1, n, l, r, value);
    }

    int get(int l, int r) {
        return get(1, 1, n, l, r);
    }
} it(N -1);


int main() {
    //freopen("a.txt", "r", stdin);
    cin >> n;
    it.update(1, 1, 1);
    //cout << it.get(1, 1) << endl;
    for(int i = 1; i < N; ++i)
        it.update(i, i, -i);
    for(int i = 1; i <= n; ++i) {
        cin >> D[i] >> T[i];
        it.update(D[i], N - 1, T[i]);
        int ans = it.get(1, N - 1);
        cout << max(ans, 0) << endl;
    }
}
