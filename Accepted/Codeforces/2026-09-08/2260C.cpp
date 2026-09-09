#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int x, y;cin >> x >> y;
    int s = x + y;
    int a = 0;
    for (int bit = 32; bit >= 0; bit--) {
        if ((s >> bit) & 1) a |= (1 << bit);
        else continue;
        if (a > x) a ^= (1 << bit);
    }
    cout << s << ' ' << x - a << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
