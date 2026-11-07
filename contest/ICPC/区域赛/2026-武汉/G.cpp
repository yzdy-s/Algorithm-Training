#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n, k;cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    ranges::sort(arr.begin() + 1, arr.end(), greater<int>());

    // vector<int> sum(n + 1);
    // sum[n] = arr[n];
    // for (int i = n - 1; i >= 1; i--) sum[i] = sum[i + 1] + arr[i];

    int l = -1, r = 1e18;
    int ans = 0;
    while (l + 1 < r) {
        int mid = l + r >> 1;  // 播放最少的歌曲的播放次数
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i] < mid) sum += mid - arr[i];
        }

        if (sum <= k) {
            l = mid;
            ans = mid;
        } else {
            r = mid;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i] < ans) {
            k -= (ans - arr[i]);
            arr[i] = ans;
        }
    }

    for (int i = 1; i <= n && k; i++) {
        if (arr[i] < ans + 1) {
            k--;
            arr[i]++;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) res += min(ans + 1, arr[i]);
    cout << res << endl;
}

signed main() {
    int T = 1;cin >> T;
    while (T--) solve();
}