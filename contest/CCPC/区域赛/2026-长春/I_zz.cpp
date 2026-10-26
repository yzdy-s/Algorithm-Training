/* 

1010  11 1 0010110
1010 011 1 001100110
1010 011 0 010010

*/


#include <bits/stdc++.h>
using namespace std;
#define int long long

void fr() {
    int n; string s; cin >> n >> s; s = '#' + s;
    string res;
    
    for (int i = 1; i <= n; ++i) {
        if (i == n) {
            res += s[i];
            break;
        }
        if (i == n - 2 
          && s[i]   == '1'
          && s[i+1] == '1'
          && s[i+2] == '1') {
            res += "1001";
            break;
        }

        if (s[i] == '0' && s[i+1] == '0') {
            res += "001";
            ++i;
        }
        else if (s[i] == '1' && s[i+1] == '1') {
            res += "011";
            ++i;
        }
        else res += s[i];
    }
    cout << res.size() << '\n';
    cout << res << '\n';
}

void se() {
    int n; string s; cin >> n >> s; s = '#' + s;
    string res;

    for (int i = 1; i <= n; ++i) {
        if (i > n - 2) {
            res += s[i];
            continue;
        }
        string t = s.substr(i, 3);
        if (t == "001") { res += "00"; i += 2; }
        else if (t == "011") { res += "11"; i += 2; }
        else if (i == n - 3 && t == "100" && s[n] == '1') { res += "111"; break; }
        else res += s[i];
    }
    
    cout << res.size() << '\n';
    cout << res << '\n';
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int op; cin >> op;
        if (op == 1) fr();
        else se();
    }
}