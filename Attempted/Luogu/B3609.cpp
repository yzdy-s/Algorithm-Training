#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n, m;
int tim = 0, cnt = 0;
const int maxN = 1e4 + 7;
stack<int> sc;
vector<int> adj[maxN];
vector<int> scc[maxN];
int dfn[maxN], low[maxN], belong[maxN];

void init(int n) {
    tim = cnt = 0;
    while (!sc.empty()) sc.pop();
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        scc[i].clear();
        dfn[i] = low[i] = belong[i] = val[i] = 0;
    }
}

void trajan(int x) {
    sc.push(x);
    low[x] = dfn[x] = ++tim;
    for (auto &son : adj[x]) {
        if (!dfn[son]) {
            trajan(son);
            low[x] = min(low[x], low[son]);
        } else if (!belong[son]) {
            low[x] = min(low[x], dfn[son]);
        }
    }

    if (dfn[x] == low[x]) {
        cnt++;
        while (1) {
            int v = sc.top();sc.pop();
            belong[v] = cnt;
            if (v == x) break;
        }
    }
}


void solve(){
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= m; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) trajan(i);
    }
    cout << cnt << endl;
    map<int, vector<int>> res;
    for (int i = 1; i <= n; i++) {
        res[belong[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (auto &x : res[belong[i]]) {
            cout << x << ' ';
        }
        if (res[belong[i]].size()) {
            cout << endl;
            res[belong[i]].clear();
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}