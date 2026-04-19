#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e5 + 7;
vector<int> adj[maxN];
string s;
vector<int> fa(maxN);

int find(int x) {
    if (x == fa[x]) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

bool merge(int u, int v) {
    int u_fa = find(u);
    int v_fa = find(v);
    if (u_fa == v_fa) return false;
    fa[u_fa] = v_fa;
    return true;
}

void solve(){
    int n, m;cin >> n >> m;
    cin >> s;
    s = '#' + s;
    vector<PII> res;
    int f = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
    set<char> sc;
    for (int i = 1; i <= n; i++) sc.insert(s[i]);
    if (sc.count('A') && !sc.count('B')) {cout << "No" << endl;return;}
    if (!sc.count('A') && sc.count('B')) {cout << "No" << endl;return;}
    if (sc.count('C') && !sc.count('D')) {cout << "No" << endl;return;}
    if (!sc.count('C') && sc.count('D')) {cout << "No" << endl;return;}
    vector<PII> t;
    for (int i = 1; i <= m; i++) {
        int u, v;cin >> u >> v;
        if ((s[u] == 'A' || s[u] == 'B') && (s[v] == 'A' || s[v] == 'B')) {
            if (merge(u, v)) res.push_back({u, v});
        }else if ((s[u] == 'C' || s[u] == 'D') && (s[v] == 'C' || s[v] == 'D')) {
            if (merge(u, v)) res.push_back({u, v});
        } else {
            t.push_back({u, v});
        }
    }
    vector<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0), d(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int root = find(i);
        if (s[i] == 'A') a[root] = 1;
        if (s[i] == 'B') b[root] = 1;
        if (s[i] == 'C') c[root] = 1;
        if (s[i] == 'D') d[root] = 1;
    }

    for (int i = 1; i <= n; i++) {
        int root = find(i);
        if ((a[root] && b[root]) || (c[root] && d[root])) continue;
        cout << "No" << endl;
        return;
    }

    for (auto &[u, v] : t) {
        if (merge(u, v)) res.push_back({u, v});
    }

    if (res.size() == n - 1) {
        cout << "Yes" << endl;
        for (auto [u, v] : res) {
            cout << u << ' ' << v << endl;
        }
    } else cout << "No" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
