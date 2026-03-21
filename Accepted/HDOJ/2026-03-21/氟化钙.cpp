#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
// #define LNF 1e18
#define LNF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> L(n + 1), R(n + 1);
    stack<PII> sc;
    sc.push({LNF, 0});
    for (int i = 1; i <= n; i++) {
        while (sc.size() && sc.top().first <= arr[i]) sc.pop();
        L[i] = sc.top().second;
        sc.push({arr[i], i});
    }
    while (sc.size()) sc.pop();
    sc.push({LNF, n + 1});
    for (int i = n; i >= 1; i--) {
        while (sc.size() && sc.top().first < arr[i]) sc.pop();
        R[i] = sc.top().second;
        sc.push({arr[i], i});
    }
    map<int, vector<int>> pos;
    for (int i = 1; i <= n; i++) {
        pos[arr[i]].push_back(i);
    }
    // for (int i = 1; i <= n; i++) cout << R[i] << " \n"[i == n];
    int res = 0;
    for (int i = 2; i < n; i++) {
        int num = arr[i];
        if (!(num & 1)) continue;
        int l = L[i], r = R[i];
        int lLen = i - l + 1;
        int rLen = r - i + 1;
        if (lLen < rLen) {
            for (int j = l + 1; j < i; j++) {
                int aid = num + 1 - arr[j];
                // i+1, r-1
                res += upper_bound(pos[aid].begin(), pos[aid].end(), r-1) - lower_bound(pos[aid].begin(), pos[aid].end(), i+1);
            }
        } else {
            for (int j = i + 1; j < r; j++) {
                int aid = num + 1 - arr[j];
                // l+1, i-1
                res += upper_bound(pos[aid].begin(), pos[aid].end(), i-1) - lower_bound(pos[aid].begin(), pos[aid].end(), l+1);
            }
        }
    }

    cout << n * n - 2 * res<< endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
