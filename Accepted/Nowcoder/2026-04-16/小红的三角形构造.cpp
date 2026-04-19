#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int x;cin >> x;
    if (x == 1 || x == 2) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    int t = x * x;
    if (t & 1) {
        int a = t / 2;
        int c = (t + 1) / 2;
        cout << x << ' ' << a << ' ' << c << endl;
    } else {
        int a_c = t / 2;
        int c = (a_c + 2) / 2;
        int a = (a_c - 2) / 2;
        cout << x << ' ' << a << ' ' << c << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
