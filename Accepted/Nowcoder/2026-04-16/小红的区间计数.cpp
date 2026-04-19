#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int a, b, c, l, r;cin >> a >> b >> c >> l >> r;
    int res = r - l + 1;
    set<int> st;
    st.insert(a);
    st.insert(b);
    st.insert(c);
    for (auto &i : st) {
        if (i >= l && i <= r) res--;
    } 
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
