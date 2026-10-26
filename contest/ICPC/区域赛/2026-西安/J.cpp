#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 4e5 + 7;
vector<int> fa(MAXN);

int find(int x) {
    if (x == fa[x]) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

void solve() {
    int n;cin >> n;
    for (int i = 1; i <= 2 * n; i++) fa[i] = i;
    vector<int> cx(n + 7);
    for (int i = 1; i <= 2 * n; i++) {
        int x;cin >> x;
        if (cx[x]) {
            fa[cx[x]] = i;
        } else cx[x] = i;
    }

    stack<int> st;
    vector<int> ans(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        if (st.empty()) {
            st.push(i);
            ans[i] = 0;
        } else {
            int t = st.top();
            int a_fa = find(t);
            int b_fa = find(i);
            if (a_fa != b_fa) {
                st.pop();
                fa[a_fa] = b_fa;
                ans[i] = 1;
            } else {
                st.push(i);
                ans[i] = 0;
            }
        }
    }
    ans[2 * n] = 1;
    for (int i = 1; i <= 2 * n; i++) {
        if (ans[i]) cout << ')';
        else cout << '(';
    }
    cout << endl;
}

signed main() {
    int T;cin >> T;
    while (T--) solve();
}