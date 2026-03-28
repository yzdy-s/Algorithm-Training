#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e5 + 7;
vector<int> dep(maxN, 1);
vector<int> fa(maxN);

int find(int x) {
    if (x == fa[x]) return x;
    return find(fa[x]);
}

void merge(int u, int v) {
    int u_root = find(u);
    int v_root = find(v);

    if (dep[u_root] == dep[v_root]) {
        fa[u_root] = v_root;
        dep[v_root] += 1;
    } else if (dep[u_root] < dep[v_root]) {
        fa[u_root] = v_root;
    } else {
        fa[v_root] = u_root;
    }
}

void solve(){
    int n, m;cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    while (m--) {
        int op, x, y;cin >> op >> x >> y;
        if (op == 1) merge(x, y);
        else {
            int x_root = find(x);
            int y_root = find(y);
            if (x_root == y_root) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
