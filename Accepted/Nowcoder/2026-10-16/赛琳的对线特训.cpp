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
    vector<int> sum(n + 1), mx(n + 1);
    for (int i = 1; i <= n; i++) sum[i] += sum[i - 1] + arr[i];
    for (int i = 1; i <= n; i++) mx[i] = max(mx[i - 1], arr[i]);

    for (int i = 1; i <= n; i++) {
        if (sum[i] + mx[i] >= k) {
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
