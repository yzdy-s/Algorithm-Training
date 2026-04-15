#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> cnt(n + 1);
    arr[0] = -1;
    int mx = 1;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == arr[i - 1]) {
            cnt[i] = cnt[i - 1] + 1;
        } else cnt[i] = 1;
        mx = max(mx, cnt[i]);
    }
    if (mx >= m) cout << "NO" << endl;
    else cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
