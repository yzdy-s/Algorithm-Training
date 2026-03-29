#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MOD = 676767677;

int cnt[200007];

void pre() {
    for (int i = 1; i < 200005; i++) for (int j = i; j < 200005; j += i) cnt[j]++;
}

void solve(){
    int x, y;cin >> x >> y;
    if (x == y) {
        cout << 1 << endl;
        for (int i = 1; i <= x; i++) {
            cout << 1 << ' ';
        }
        for (int i = 1; i <= x; i++) {
            cout << -1 << ' ';
        }
        cout << endl;
        return;
    }
    int g = max(x, y) - min(x, y);
    int ans = cnt[g];
    cout << ans % MOD << endl;
    for (int i = 1; i <= x; i++) cout << 1 << ' ';
    for (int i = 1; i <= y; i++) cout << -1 << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    pre();
    int T = 1;cin >> T;
    while (T--) solve();
}
