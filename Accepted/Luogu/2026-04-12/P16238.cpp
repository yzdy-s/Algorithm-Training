#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<int> sum(n + 1);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        int k = b[i] - a[i];
        if (k == 0) sum[i] = 1;
        else {
            mp[k].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
    int tot = sum[n];
    int res = sum[n];
    for (auto &i : mp) {
        int k = i.first;
        vector<int> vec = i.second;
        int cur = tot + 1;
        res = max(res, cur);
        for (int j = 1; j < vec.size(); j++) {
            cur += 1;
            cur -= sum[vec[j]] - sum[vec[j - 1] - 1];
            cur = max(tot + 1LL, cur);
            res = max(cur, res);
        }
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
