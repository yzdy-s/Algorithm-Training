#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] & 1) odd++;
    }
    even = n - odd;

    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cnt[i] = (arr[i] & 1) ? -1 : 1;
    }
    int mx = 0;
    int cur = 0;
    for (int i = 1; i <= n; i += 2) {
        cur += cnt[i];
        cur = max(0LL, cur);
        mx = max(mx, cur);
    }
    cur = 0;
    for (int i = 2; i <= n; i += 2) {
        cur += cnt[i];
        cur = max(0LL, cur);
        mx = max(mx, cur);
    }
    // cout << odd << ' ' << even << ' ' << mx << ' ';
    if (odd + mx > even - mx) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
