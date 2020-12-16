#include <bits/stdc++.h>

using namespace std;
#define x1 xx1
#define x2 x1231
#define y1 x512x1
#define y2 x152x1
int T;
int x1, y1, x2, y2;
int main()
{
//    freopen("in.in","r",stdin);
    cin >> T;
    while(T--){
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2 && y1 == y2){
            cout << "YES\n";
            continue;
        }
        if(x1 == 0 && y1 == 0){
            cout << "NO" << "\n";
            continue;
        }
        if(x2 == 0 && y2 == 0){
            cout << "NO" << "\n";
            continue;
        }
        int d = __gcd(abs(x1), abs(y1));
        int d1 = __gcd(abs(x2), abs(y2));
        if(d == d1){
            cout << "YES" << "\n";
        } else{
            cout << "NO" << "\n";
        }
    }
    return 0;
}
