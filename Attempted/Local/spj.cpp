#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    vector<int> ans(n + 1, 1);
    while(m--) {
        int x;cin >> x;
        ans[x] = 0;
        for (int i = 1; i <= n; i++) ans[i] = (ans[i - 1] | ans[i + 1]); 
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}