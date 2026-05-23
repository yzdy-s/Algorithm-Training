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

    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + abs(arr[i]);

    int mx = 0;
    int idx = 0;
    for (int i = 1; i <= n; i++) mx += arr[i];

    int bac = 0;
    for (int i = n; i >= 1; i--) {
        bac += arr[i];
        if (arr[i] < 0) continue;
        int x = sum[i - 1] + bac - 2 * arr[i];
        if (x > mx) {
            mx = x;
            idx = i;
        }
    }

    if (idx == 0) {
        cout << 0 << endl << endl;
        return;
    }

    vector<int> res;
    int cur = 0;
    for (int i = idx - 1; i >= 1; i--) {
        if (arr[i] > 0 && cur == 0) {
            res.push_back(i);
            cur ^= 1;
        } else if (arr[i] < 0 && cur == 1) {
            res.push_back(i);
            cur ^= 1;
        }
    }
    res.push_back(idx);
    cout << res.size() << endl;
    for (auto &i : res) cout << i << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
