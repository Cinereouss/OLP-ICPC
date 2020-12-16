#include <bits/stdc++.h>

using namespace std;


bool check(string s){
    int len = s.size();
    for(int i = 0; i < s.size() - 1; i++){
        string sfirst = s.substr(0, i + 1);
        string ssecond = s.substr(i + 1, len - (i + 1));
        if(sfirst >= ssecond) return false;
    }
    return true;
}

string tryZero(string s, int id){
    for(int i = id + 1; i < s.size(); i++){
        if(s[i] == '1'){
            s[i] = '0';
            if(!check(s)){
                s[i] = '1';
            }
        }
    }
    if(check(s)) return s;
    return "";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("a.txt", "r", stdin);
    int nTest;
    cin >> nTest;
    for (int i = 1; i <= nTest; i++) {
        string s;
        cin >> s;
        string preS = s;
        int id = -1;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '0'){
                s[i] = '1';
                if(tryZero(s, i) == ""){
                    s[i] = '0';
                    continue;
                }
                s = tryZero(s, i);
                break;
            }
        }
        if(!check(s) || preS == s) cout << "\n";
        else
        cout << s << "\n";
    }
}
