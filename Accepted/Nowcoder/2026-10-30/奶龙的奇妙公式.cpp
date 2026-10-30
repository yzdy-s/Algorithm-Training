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
    //ranges::sort(arr.begin() + 1, arr.end());
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += arr[i] * i;
    cout << ans << endl;
    // ans = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = i; j <= n; j++) {
    //         ans += min(arr[i], arr[j]) + max(0ll, arr[j] - arr[i]);
    //     }
    // }
    // cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
