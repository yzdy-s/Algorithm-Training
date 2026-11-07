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
    int mx = 0, idx_1 = -1, idx_2 = -1, cnt = 0;
    for (int i = 1; i < n; i++) {
        int dx = abs(arr[i + 1] - arr[i]);
        if (dx > mx) {
            mx = dx;
            idx_1 = i;
            cnt = 1;
        } else if (dx == mx) {
            idx_2 = i;
            cnt++;
        }
    }
    if (cnt > 2) {
        cout << mx << endl;
    } else if (cnt == 2) {
        int res = 0;
        for (int i = 1; i < idx_1; i++) res = max(res, abs(arr[i] - arr[i + 1]));
        for (int i = idx_2 + 1; i < n; i++) res = max(res, abs(arr[i] - arr[i + 1]));
        for (int i = idx_1 + 1; i < idx_2; i++) res = max(res, abs(2 * arr[i] - 2 * arr[i + 1]));
        res = max(res, abs(arr[idx_1] - 2 * arr[idx_2]));
        res = max(res, abs(arr[idx_2 + 1] - 2 * arr[idx_1 + 1]));
        
        res = min(res, mx);
        cout << res << endl;
    } else {
        int idx = idx_1;
        int nei = 0; // 反转区间内部最大值
        int res = mx; // 整体最大值 的 最小值

        // 前半区间 [i, idx]
        vector<int> preMx(n + 1);
        for (int i = 1; i < n; i++) preMx[i] = max(preMx[i - 1], abs(arr[i] - arr[i + 1]));
        int ba = 0;
        for (int i = idx + 1; i < n; i++) ba = max(ba, abs(arr[i] - arr[i + 1])); // 后半部分不变区间
        if (idx >= 2) res = min(res, max({ba, preMx[idx - 2], abs(2 * arr[idx] - arr[idx - 1]), abs(2 * arr[idx] - arr[idx + 1])}));
        if (idx == 1) res = min(res, max(ba, abs(2 * arr[idx] - arr[idx + 1])));
        for (int i = idx_1 - 1; i >= 1; i--) {
            nei = max(nei, abs(2 * arr[i] - 2 * arr[i + 1]));
            int t = max(ba, nei);
            if (i >= 2) t = max(t, preMx[i - 2]);
            if (i != 1) t = max({t, abs(arr[i - 1] - 2 * arr[idx]), abs(arr[idx + 1] - 2 * arr[i])});
            else t = max({t, nei, abs(2 * arr[i] - arr[idx + 1])});
            res = min(res, t);
        }

        // 后半区间 [idx + 1, i]
        vector<int> bacMx(n + 2);
        for (int i = n; i > 1; i--) bacMx[i] = max(bacMx[i + 1], abs(arr[i] - arr[i - 1]));
        int fr = preMx[idx - 1];
        int t = max(fr, abs(arr[idx] - 2 * arr[idx + 1]));
        if (idx + 2 <= n) t = max(t, abs(arr[idx + 2] - 2 * arr[idx + 1]));
        if (idx + 3 <= n) t = max(t, bacMx[idx + 3]);
        res = min(res, t);
        nei = 0;
        for (int i = idx + 2; i <= n; i++) {
            nei = max(nei, abs(2 * arr[i] - 2 * arr[i - 1]));
            int t = max(fr, nei);
            if (i + 2 <= n) t = max(t, bacMx[i + 2]);
            t = max(t, abs(2 * arr[i] - arr[idx]));
            if (i + 1 <= n) t = max(t, abs(2 * arr[idx + 1] - arr[i + 1]));
            // cout << i << ':' << t << endl;
            res = min(res, t);
        }

        cout << res << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
