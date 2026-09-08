#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    map<int, int> L, R;
    int f = 1;
    int mn = LNF;
    vector<vector<int>> arr(n + 1);
    for (int i = 1; i <= m; i++) {
        int l, r;cin >> l >> r;
        if (l > r) swap(l, r);
        L[l]++, R[r]++;
        mn = min(mn, r);
        arr[l].push_back(r);
        if (l == r) f = 0;
    }
    if (!f) {
        cout << "No" << endl;
        return;
    }
    
    for (int a1 = 2; a1 <= mn; a1++) {
        int x = a1 - 1;
        L.erase(x);
        for (auto &r : arr[x]) {
            R[r]--;
            if (R[r] == 0) R.erase(r);
            L[r]++;
            arr[r].push_back(x + n);
        }
        // cout << L.rbegin()->first << ' ' << R.begin()->first << endl;
        if (R.size() == 0 || L.rbegin()->first < R.begin()->first) {
            if (L.rbegin()->first + 1 <= n) {
                cout << "Yes" << endl;
                cout << a1 << ' ' << L.rbegin()->first + 1 << endl;
                return;
            }
        }
        // if (L.rbegin()->first < R.begin()->first) {
        //     cout << "Yes" << endl;
        //     cout << a1 << ' ' << L.rbegin()->first + 1 << endl;
        //     return;
        // }
    }

    cout << "No" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
