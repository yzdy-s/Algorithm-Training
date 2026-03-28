#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void baoli() {
    int n;cin >> n;
    vector<int> arr(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i + n] = arr[i];
    }
    for (int i = 1; i <= n; i++) {
        int f = 1;
        int cur = 0;
        for (int j = i; j < (i + n); j++) {
            cur += arr[j];
            if (cur < 0) f = 0;
        }
        if (f) {
            cout << i << endl;
            return;
        }
    }
}

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    // for (int i = 1; i <= n; i++) cout << arr[i] << " \n"[i == n];
    int mn = LNF;
    int cur = 0;
    for (int i = 2; i <= n; i++) {
        cur += arr[i];
        mn = min(mn, cur);
    }
    for (int i = 1; i <= n; i++) {
        // cout << arr[i] << ' ' << mn << endl;
        if (arr[i] >= 0 && arr[i] + mn >= 0) {
            cout << i << endl;
            return;
        }
        mn -= arr[i+1];
        cur -= arr[i+1];
        cur += arr[i];
        mn = min(cur, mn);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) {
        solve();
        // baoli();
    }
}
