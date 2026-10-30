#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int ans = -LNF;

    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) arr[i] += arr[i - 1];
    int cur = 0;
    for (int k = 1; cur <= n; k++) {
        cur += k * 3;
        int i = 1, j = cur;
        for (; j <= n; j++, i++) ans = max(ans, arr[j] - arr[i - 1]);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
