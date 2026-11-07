#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MAXN = 3e5 + 7;
vector<int> adj[MAXN];

set<int> st;

void dfs(int x, int fa) {
    st.insert(x);
    for (auto &son : adj[x]) {
        if (son == fa) continue;
        dfs(son, x);
    }
}
void solve(){
    int n;cin >> n;
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n % 2 == 0) {
        cout << n + 1 << endl;
        return;
    }

    // k = n 以 n 为根节点
    for (auto &son : adj[n]) {
        st.clear();
        dfs(son, n);
        for (auto &i : st) {
            if (n - i >= 1 && n - i <= n && st.count(n - i) == 0) {
                cout << n << endl;
                return;
            }
        }
    }

    // k = n + 2 以 1 为根节点
    for (auto &son : adj[1]) {
        st.clear();
        dfs(son, 1);
        for (auto &i : st) {
            if (n + 2 - i >= 1 && n + 2 - i <= n && st.count(n + 2 - i) == 0) {
                cout << n + 2 << endl;
                return;
            }
        }
    }

    cout << n + 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
