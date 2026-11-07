#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    int odd_a = 0, odd_b = 0;
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        odd_a += x & 1;
    }
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        odd_b += x & 1;
    }
    if (odd_a == odd_b) {
        cout << "YES" << endl;
        return;
    }
    if (odd_a < odd_b && k % 2 == 1) {
        cout << "YES" << endl;
        return;
    }
    if (odd_a > odd_b && k % 2 == 0) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
