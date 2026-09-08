#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, d;cin >> n >> d;
    string s;cin >> s;
    int cur = d;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') cur++;
        else cur--;
        if (cur == 10) cur = 0;
        else if (cur == -1) cur = 9;
        if (cur == d) res++;
    }
    cout << cur << ' ' << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
