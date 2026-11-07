#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int ask(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    cout.flush();
    int res;cin >> res;
    return res;
}

void solve(){
    int n;cin >> n;
    int all = ask(1, n);
    if (all == 0 || all == n) {
        cout << "! NO" << endl;cout.flush();
        return;
    }
    if (ask(1, all) == all) {
        cout << "! NO" << endl;cout.flush();
        return;
    }
    cout << "! YES" << endl;cout.flush();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}