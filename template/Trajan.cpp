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
vector<int> adj[maxN];
vector<int> scc[maxN];
int dfn[maxN], low[maxN], sccNo[maxN], val[maxN], arr[maxN];
stack<int> sc;

void trajan(int x) {
    sc.push(x);
    low[x] = dfn[x] = ++tim;
    for (auto &son : adj[x]) {
        if (!dfn[son]) {
            trajan(son);
            low[x] = min(low[x], low[son]);
        } else if (!sccNo[son]) {
            low[x] = min(low[x], low[son]);
        }
    }

    if (dfn[x] == low[x]) {
        cnt++;
        while (1) {
            int v = sc.top();sc.pop();
            sccNo[v] = cnt;
            val[cnt] += arr[v];
            if (v == x) break;
        }
    }
}

vector<int> dp(maxN, -LNF);

int dfs(int x) {
    if (dp[x] != -LNF) return dp[x];
    dp[x] = val[x];
    int mx = 0;
    for (auto &son : scc[x]) {
        dfs(son);
        mx = max(mx, dp[son]);
    }
    dp[x] += mx;
    return dp[x];
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= m; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) trajan(i);
    }
    vector<int> to(cnt + 1, 1);

    for (int x = 1; x <= n; x++) {
        for (auto &son : adj[x]) {
            if (sccNo[x] != sccNo[son]) {
                scc[sccNo[x]].push_back(sccNo[son]);
                to[sccNo[son]] = 0;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= cnt; i++) {
        if (to[i]) ans = max(ans, dfs(i));
    }
    // for (int i = 1; i <= n; i++) cout << val[i] << " \n"[i == n];
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}