#include <bits/stdc++.h>
using namespace std;
#define int long long

void fr() {
    int n;cin >> n;
    string s;cin >> s;
    s = "#" + s;
    string ans = "";
    for (int i = 1; i <= n; i += 2) {
        if (i == n) {
            ans += s[i];
            break;
        }
        string cur = "";
        cur += s[i]; cur += s[i + 1];
        string nx = "";
        if (i + 2 <= n) nx += s[i + 2];
        if (i + 3 <= n) nx += s[i + 3];
        // cout << cur << endl << nx << endl;

        if (cur == "00") {
            if (nx == "11") ans += "100";
            else ans += "001";
        } else if (cur == "11") {
            if (nx == "00") ans += "011";
            else ans += "110";
        } else if (cur == "01") {
            if (nx == "11" || nx == "10") ans += "010";
            else ans += "011";
        } else if (cur == "10") {
            if (nx == "01" || nx == "00") ans += "101";
            else ans += "100";
        }
    }
    cout << ans.size() << endl;
    cout << ans << endl;
}

void se() {
    int n;cin >> n;
    string s;cin >> s;
    s = "#" + s;
    string ans;
    for (int i = 1; i <= n; i += 3) {
        if (i == n) {
            ans += s[i];
            break;
        }
        string cur = "";
        cur += s[i]; cur += s[i + 1]; cur += s[i + 2];
        string nx = "";
        if (i + 3 <= n) nx += s[i + 3];
        if (i + 4 <= n) nx += s[i + 4];
        if (i + 5 <= n) nx += s[i + 5];

        if (cur == "101") {
            ans += "10";
        } else if (cur == "010") {
            ans += "01";
        } else if (cur == "100") {
            if (nx == "110") ans += "00";
            else ans += "10";
        } else if (cur == "011") {
            if (nx == "001") ans += "11";
            else ans += "01";
        } else if (cur == "001") ans += "00";
        else if (cur == "110") ans += "11";
    }
    cout << ans.size() << endl;
    cout << ans << endl;
}

signed main() {
    int T = 1;cin >> T;
    while (T--) {
        int op;cin >> op;
        if (op == 1) fr();
        else se();
    }
}