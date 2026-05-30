#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    map<char, int> a;
    int res = 0;
    string s;cin >> s;
    for (auto &c : s) a[c]++;
    for (auto &[c, cnt] : a) {
        if (cnt == 1) res++;
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
