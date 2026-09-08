#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n;
const int maxN = 5e5 + 7;
vector<int> adj[maxN];
vector<int> dep(maxN);
vector<int> siz(maxN, 0);
vector<int> top(maxN, 1);
vector<int> zSon(maxN, 0);
vector<int> fa(maxN);
vector<int> dfn(maxN);
int cur = 1;

void cnt(int x, int f, int h) {
    fa[x] = f;
    siz[x] = 1;
    dep[x] = h;
    for (auto &son : adj[x]) {
        if (son == f) continue;
        cnt(son, x, h+1);
        if (!zSon[x] || (siz[zSon[x]] < siz[son])) zSon[x] = son;
        siz[x] += siz[son];
    }
}

void dfs(int x, int fa) {
    dfn[x] = cur++;
    if (x != zSon[fa]) {
        top[x] = x;
    }else{
        top[x] = top[fa];
    }
    for (auto &son : adj[x]) {
        if (son == fa) continue;
        dfs(son, x);
    }
}

int LCA(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return (dep[x] < dep[y] ? x : y);
}


void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cnt(1, 0, 1);
    dfs(1, 0);
    // for (int i = 1; i <= n; i++) cout << top[i] << ' ';
    // cout << endl;
    vector<int> leaf;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}