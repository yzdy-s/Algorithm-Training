#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

const int maxN = 1e5 + 7;
vector<PII> adj[maxN];
vector<int> res(maxN);

void dfs(int x) {
    for (auto &[son, m] : adj[x]) {
        res[son] = min(m, res[x]);
        dfs(son);
    }
}

signed main() {
    int n;cin >> n;
    for (int i = 1; i < n; i++) {
        int fa, m;cin >> fa >> m;
        adj[fa].push_back({i, m});
    }
    set<int> leaf;
    for (int i = 1; i < n; i++) {
        if (adj[i].size() == 0) leaf.insert(i);
    }
    res[0] = 1e9;
    dfs(0);
    map<int, vector<int>> ans;
    int mx = -1;
    for (auto &i : leaf) {
        ans[res[i]].push_back(i);
        mx = max(mx, res[i]);
    }
    cout << mx << endl;
    for (int i = 0; i < ans[mx].size(); i++) {
        cout << ans[mx][i] << " \n"[i == ans[mx].size() - 1];
    }
}