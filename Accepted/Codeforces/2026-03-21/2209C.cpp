#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

bool query(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    cout.flush();
    int res;cin >> res;
    return res;
}

void solve(){
    int n;cin >> n;
    for (int i = 1; i < n; i++) {
        int res = query(2*i-1, 2*i);
        if (res) {
            cout << "! " << 2*i << endl;
            cout.flush();
            return;
        }
    }
    int t = query(1, 2*n);
    if (t) {
        cout << "! " << 2*n << endl;
        cout.flush();
        return;
    }
    t = query(2, 2*n);
    if (t) {
        cout << "! " << 2*n << endl;
        cout.flush();
        return;
    }
    cout << "! " << 2*n-1 << endl;
    cout.flush();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
