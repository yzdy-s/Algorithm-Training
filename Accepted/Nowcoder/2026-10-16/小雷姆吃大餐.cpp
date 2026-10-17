#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n, k;
const int MAXN = 2e5 + 7;
vector<int> arr(MAXN);

bool check(int x) {
    int cnt = 0;
    int i = 1;
    while (i <= n) {
        cnt++;
        int sum = arr[i], mx = arr[i];
        int j = i + 1;
        while (j <= n) {
            int ns = sum + arr[j];
            int nm = max(mx, arr[j]);
            if (ns - nm > x) break;
            sum = ns, mx = nm;
            j++;
        }
        i = j;
    }
    return cnt <= k;
}

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int l = -1, r = 1e18;
    int ans = LNF;
    while (l + 1 < r) {
        int mid = l + r >> 1;
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
    int T = 1;//cin >> T;
    while (T--) solve();
}
