#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int popcnt(int x) {
    int res = 0;
    while (x) {
        res += (x & 1);
        x >>= 1;
    }
    return res;
}

void solve(){
    int a = 2, b = 17, c = 687;
    int x;cin >> x;
    if (x <= a) cout << a << endl;
    else if (x <= b) cout << b << endl;
    else if (x <= c) cout << c << endl;
    else cout << -1 << endl;
}

signed main() {
    int T = 1;cin >> T;
    while (T--) solve();
}
