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

    int ans = 0;
    vector<int> b;
    for (int i = 1; i <= n; i++) {
        if (i >= k && i <= n - k + 1) {
            ans += arr[i];
        } else b.push_back(arr[i]);
    }

    int aid = max(0ll, (int)b.size() - k + 1);
    int i = 0, j = b.size() - 1;
    while (aid--) {
        ans += max(b[i++], b [j--]);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
