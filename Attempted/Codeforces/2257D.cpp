#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int S, q;cin >> S >> q;
    vector<PII> ys;
    for (int i = 1; i * i <= S; i++) {
        if (S % i == 0) {
            ys.push_back({i, S / i});
            if (i * i != S) ys.push_back({S / i, i});
        }
    }
    ranges::sort(ys);
    vector<int> arr;
    vector<int> X;
    int k = 0;
    for (auto [a, b] : ys) {
        arr.push_back((a - k) * b);
        k = a;
        X.push_back(k);
    }
    vector<int> sum(arr.size());
    sum[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) sum[i] = sum[i - 1] + arr[i];
    // for (auto &i : arr) cout << i << ' ';
    // cout << endl;
    // for (auto &i : sum) cout << i << ' ';
    // cout << endl;
    // for (auto &i : X) cout << i << ' ';
    // cout << endl;
    while (q--) {
        int x, y;cin >> x >> y;
        int k = 0;
        int idx1 = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
        int idx2 = upper_bound(arr.begin(), arr.end(), y) - arr.begin() - 1;

        // cout << idx1 << ' ' << idx2 << endl;
        int res = sum[idx1] - (S / X[idx1]) * (X[idx1] - x);
        int tep = sum[idx2] - (S / X[idx2]) * (X[idx2] - y);
        tep = sum.back() - tep;
        res -= tep;
        res = min(res, x * y);
        cout << res << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}