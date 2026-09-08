#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int a, b, c;cin >> a >> b >> c;

    // 3999   1000000
    cout << 3;
    for (int i = 1; i < a; i++) cout << 9;
    cout << ' ';
    cout << 1;
    for (int i = 1; i < b; i++) cout << 0;
    cout << ' ';

    // 39999长度大于10099999
    cout << 3;
    for (int i = 1; i < a; i++) cout << 9;
    for (int i = 0; i <= 2 * b; i++) cout << 9;
    cout << ' ';
    cout << 1;
    for (int i = 1; i < b; i++) cout << 0;
    cout << 9;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;// cin >> T;
    while (T--) solve();
}
