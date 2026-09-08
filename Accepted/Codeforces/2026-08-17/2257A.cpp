#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, q;cin >> n >> q;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        string s;cin >> s;
        st.insert(s[0] - 'a');
    }
    int f = 1;
    while (q--) {
        string s;cin >> s;
        for (auto &c : s) {
            if (!st.count(c - 'A')) {
                f = 0;
                break;
            }
        }
    }
    if (f) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
