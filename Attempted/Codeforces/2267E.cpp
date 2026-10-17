#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, q;cin >> n >> q;
    string s;cin >> s;
    int zero = 0, one = 0;
    vector<int> f(n + 1);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            f[i] = 1;
            ans += i * (n - i);
        } 
    }

    while (q--) {
        int pos;cin >> pos;

    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}