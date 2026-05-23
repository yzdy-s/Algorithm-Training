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
    int cur = 0;
    vector<int> res;
    for (int i = n; i >= 1; i--) {
        if (arr[i] > 0 && cur == 0) {
            cur ^= 1;
            res.push_back(i);
        } else if (arr[i] < 0 && cur == 1) {
            cur ^= 1;
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for (auto &i : res) {
        cout << i << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
