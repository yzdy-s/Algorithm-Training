#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int k, z;cin >> k >> z;
    vector<int> arr(k);
    for (int i = 0; i < k; i++) cin >> arr[i];
    vector<int> ans(k, 3);
    int cur = 1;
    for (int i = k-1; i >= 0; i--) {
        if (arr[i] == 0) {
            ans[i] = 0;
        }
        if (arr[i] != 1) continue;
        if (cur) ans[i] = 1;
        else ans[i] = 0;
        arr[i] = 0;
        cur ^= 1;
    }
    int sum = 0;
    for (int i = 0; i < k; i++) sum += arr[i];
    if ((z + sum) % 2) {
        for (int i = 0; i < k; i++) if (ans[i] == 3) ans[i] = cur;
    } else for (int i = 0; i < k; i++) if (ans[i] == 3) ans[i] = (cur ^ 1);
    for (int i = k-1; i >= 0; i--) cout << ans[i];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;// cin >> T;
    while (T--) solve();
}