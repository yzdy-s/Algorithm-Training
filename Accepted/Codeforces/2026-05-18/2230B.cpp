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
    s = "#" + s;
    
    vector<int> fr(n + 7), ba(n + 7);
    for (int i = 1; i <= n; i++) {
        fr[i] = fr[i - 1];
        if (s[i] == '4') continue;
        if (s[i] == '2') fr[i]++;
    }

    for (int i = n; i >= 1; i--) {
        ba[i] = ba[i + 1];
        if (s[i] == '4') continue;
        if (s[i] != '2') ba[i]++;
    }

    int res = 0;
    for (int i = 0; i <= n; i++) {
        res = max(res, fr[i] + ba[i + 1]);
    }
    cout << n - res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
