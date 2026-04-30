#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n, k;
const int maxN = 3e5 + 7;
vector<int> arr(maxN);
int sum = 0;
int check(int x) {
    for (int i = 1; i <= n; i++) arr[i] -= x;
    vector<int> dp(n + 1);
    vector<int> cnt(n + 1);
    if (arr[1] >= 0) {
        cnt[1] = 1;
        dp[1] = arr[1];
    }
    for (int i = 2; i <= n; i++) {
        if (dp[i - 2] + arr[i] > dp[i - 1]) {
            dp[i] = dp[i - 2] + arr[i];
            cnt[i] = cnt[i - 2] + 1;
        } else if (dp[i - 2] + arr[i] == dp[i - 1]) { // 相同收益下贪心选择cnt多的情况
            if (cnt[i - 2] + 1 >= cnt[i - 1]) {
                dp[i] = dp[i - 2] + arr[i];
                cnt[i] = cnt[i - 2] + 1;
            } else {
                dp[i] = dp[i - 1];
                cnt[i] = cnt[i - 1];
            }
        } else {
            dp[i] = dp[i - 1];
            cnt[i] = cnt[i - 1];
        }
    }
    sum = dp[n];
    for (int i = 1; i <= n; i++) arr[i] += x;
    return cnt[n];
}

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    if (check(0) <= k) {
        cout << sum << endl;
        return;
    }

    int l = -1e6, r = 1e6;
    int ans = LNF;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        int cnt = check(mid);
        if (cnt >= k) {
            ans = sum + k * mid;
            l = mid;
        } else r = mid;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
