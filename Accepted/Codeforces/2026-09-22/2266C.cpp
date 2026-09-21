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
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            fr = i;
            break;
        }
    }

    // if (fr == 0) {
    //     cout << 0 << endl;
    //     return;
    // }

    vector<int> cnt0(n + 2, 0);
    vector<int> cnt1(n + 2, 0);
    for (int i = n; i >= 1; i--) cnt0[i] = cnt0[i + 1] + (s[i] == '0' ? 1 : 0);
    for (int i = 1; i <= n; i++) cnt1[i] = cnt1[i - 1] + (s[i] == '1' ? 1 : 0);
    
    if (fr == 1) {
        cout << cnt0[1] << endl;
        return;
    }

    int ans = LNF;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            ans = min(ans, cnt1[i - 1] + cnt0[i + 1]);
        }
    }
    if (s[1] == '0') {
        ans = min(ans, cnt1[n]);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
