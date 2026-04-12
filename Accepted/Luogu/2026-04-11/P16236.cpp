#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    s = "#" + s;
    int fr = 0;
    vector<int> bac(n + 7);
    for (int i = n; i >= 1; i--) {
        bac[i] = bac[i + 1];
        if (s[i] == '?' || s[i] == 'Q') bac[i]++;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') {
            fr++;
            continue;
        } else if (s[i] == 'Q') continue;

        if (fr < bac[i + 1]) {
            s[i] = 'L';
            fr++;
        } else s[i] = 'Q';
    }

    int res = 0;
    fr = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') {
            fr++;
        } else res += fr;
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
