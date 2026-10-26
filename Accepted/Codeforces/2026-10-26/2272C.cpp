#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n, x;
int MAXN = 2e5 + 7;
vector<int> arr(MAXN);
vector<int> vis(MAXN, 0);

bool check(int mid) {
    int use = 0;
    int black = -LNF;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if (arr[i + 1] - arr[i] <= mid) {
            vis[i + 1] = 1;
            vis[i] = 1;
            // if (mid == 1) cout << "A" << ' ';
        } else if (arr[i] - black <= mid || arr[i] - arr[i - 1] <= mid) {
            vis[i] = 1;
            // if (mid == 1) cout << "B" << ' ';
        } else {
            vis[i] = 1;
            use++;
            black = arr[i] + mid;
            // if (mid == 1) cout << "C" << ' ';
        }
    }
    // cout << endl;
    return use <= x;    
}


void solve(){
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    arr[n + 1] = LNF; arr[0] = -LNF;
    int l = 0, r = 1e9 + 7;
    int ans = r;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        for (int i = 1; i <= n; i++) vis[i] = 0;
        if (check(mid)) {
            r = mid;
            ans = mid;
        } else l = mid;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
