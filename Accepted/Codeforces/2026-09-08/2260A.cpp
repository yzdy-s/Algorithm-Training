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
    int cnt = 0;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 2; i < n; i++) if (arr[i] == 0) cnt++;
    if (arr[1] == 0 && arr[n] == 0) {
        cout << 0 << endl;
        return;
    }
    if (arr[1] == 0 || arr[n] == 0) {
        if (cnt >= 1) {
            cout << 1 << endl;
            return;
        }
    }
    if (arr[1] == 1 && arr[n] == 1) {
        if (cnt >= 2) {
            cout << 2 << endl;
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
