#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int a, b;cin >> a >> b;
    if (a % 2 == b % 2) {
        if (b > a) {
            cout << -1 << endl;
        } else {
            cout << a << endl;
        }
    } 
    else {
        if (b > a + 1) {
            cout << -1 << endl;
        } else {
            cout << a + 1 << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
