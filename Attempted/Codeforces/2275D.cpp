#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MAXN = 2e5 + 7;
vector<vector<int>> arr(MAXN, vector<int>(3, 0));
int n, k;

bool check(int s) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int a = arr[i][0], b = arr[i][1], c = arr[i][2];
        int sum = arr[i][0] + arr[i][1] + arr[i][2];
        if (sum >= s) continue;
        if (a == b && b == c) return 0;
        int f = 0;
        if ((arr[i][0] > arr[i][1]) || (arr[i][0] > arr[i][2]) || (arr[i][1] > arr[i][2])) {
            res += s - sum;
        } else {
            int mn = 1e18;
            if (a < b) mn = min(mn, c - b + 1);
            if (a < c) mn = min(mn, b - a + 1);
            res += mn * 2 + s - sum;
            if (s == 6) cout << mn << endl;
        }
    }

    return res <= k;
}

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    int l = -1e18, r = 2e18;
    int ans = -1e18;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            l = mid;
            ans = max(ans, mid);
        } else r = mid;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}