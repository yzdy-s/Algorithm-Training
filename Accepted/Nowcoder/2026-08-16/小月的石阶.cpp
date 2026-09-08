#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int cur = 0;
    int l = 1;
    int ans = 0;
    for (int r = 2; r <= n; r++) {
        cur += abs(arr[r] - arr[r - 1]);
        while (l < r && cur > k) {
            cur -= abs(arr[l + 1] - arr[l]);
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
