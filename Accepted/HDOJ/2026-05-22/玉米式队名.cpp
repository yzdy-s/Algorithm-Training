#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    string s;cin >> s;
    int n = s.size();
    string aid = "execute";
    for (int i = n - 7; i >= 0; i--) {
        int f = 1;
        for (int k = 0; k < 7; k++) {
            if (aid[k] != s[i + k]) {
                f = 0;
                break;
            }
        }
        if (f) s[i] = '1';
    }
    cout << s << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
