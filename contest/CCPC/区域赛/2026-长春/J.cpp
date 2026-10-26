#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve() {
    int n, m, k;cin >> n >> m >> k;
    vector<int> arr(n + 1);
    vector<array<int, 3>> q(m + 1);
    for (int i = 1; i <= m; i++) {
        int x, y, z;cin >> x >> y >> z;
        q[i] = {x, y, z};
        arr[x] |= z;
        arr[y] |= z;
    }

    
    for (int i = 1; i <= m; i++) {
        int x = q[i][0];
        int y = q[i][1];
        int z = q[i][2];
        if ((arr[x] & arr[y]) != z) {
            cout << -1 << endl;
            return;
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) sum += arr[i];
    cout << sum << endl;
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}

