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
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i + 1] + (s[i] == '(' ? 1 : -1);
    int res = 0, cnt = 0;
    for (int r = 1; r <= n; r++) {
        
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}