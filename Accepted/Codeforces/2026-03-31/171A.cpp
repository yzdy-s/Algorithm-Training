#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int f(int x) {
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoll(s);
}
void solve(){
    int a, b;cin >> a >> b;
    cout << a + f(b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
