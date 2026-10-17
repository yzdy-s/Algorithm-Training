#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> ans(n + 1, 0);
    string s;cin >> s;
    s = "#" + s;
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        char c = s[i];
        if (c == '1') {
            st.push(i);
        } else if (c == '2') {
            if (st.size()) {
                ans[st.top()] = 1;
                st.pop();
            } else ans[i] = 1;
        } else {
            ans[i] = 1;
        }
    }

    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (!ans[i]) res.push_back(i);
    }
    cout << res.size() << endl;
    for (auto &i : res) cout << i << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
