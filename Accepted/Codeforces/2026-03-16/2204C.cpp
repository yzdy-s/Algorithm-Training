#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int a, b, c, m;cin >> a >> b >> c >> m;
    int lcmABC = lcm(lcm(a, b), c);
    int cntABC = m / lcmABC;
    int cntAB  = m / lcm(a, b);
    int cntAC  = m / lcm(a, c);
    int cntBC  = m / lcm(b, c);
    int resA = cntABC * 2 + (cntAB + cntAC - cntABC * 2) * 3 + (m / a - cntAB - cntAC + cntABC) * 6;
    int resB = cntABC * 2 + (cntAB + cntBC - cntABC * 2) * 3 + (m / b - cntAB - cntBC + cntABC) * 6;
    int resC = cntABC * 2 + (cntAC + cntBC - cntABC * 2) * 3 + (m / c - cntAC - cntBC + cntABC) * 6;
    cout << resA << ' ' << resB << ' ' << resC << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
