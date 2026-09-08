#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MAXN = 200007;
vector<int> adj[MAXN];
vector<PII> arr[MAXN]; // 点编号 - {时间 + 深度, 人编号}
int siz[MAXN], zSon[MAXN], ans[MAXN];
bool is_heavy[MAXN];
int deep[MAXN];

set<int> st; // 出局的人
map<int, set<int>> mp; // 时间+深度 - {人编号集合}
set<int> t; // 有问题的时间点
void update_node(int u, int val) {
    for (auto &[x, idx] : arr[u]) {
        if (st.count(idx)) continue;
        if (val == 1) {
            mp[x].insert(idx);
            if (mp[x].size() >= 2) t.insert(x);
        } else {
            mp[x].erase(idx);
        }
    }
}

void dfs1(int x, int f, int h) {
    siz[x] = 1;
    zSon[x] = 0;
    deep[x] = h;
    for (int son : adj[x]) {
        if (son == f) continue;
        dfs1(son, x, h + 1);
        siz[x] += siz[son];
        if (!zSon[x] || siz[son] > siz[zSon[x]]) {
            zSon[x] = son;
        }
    }
}

void add(int u, int f, int val) {
    update_node(u, val);
    for (int son : adj[u]) {
        if (son != f && !is_heavy[son]) {
            add(son, u, val);
        }
    }
}


void dfs2(int x, int f, bool keep) {
    for (int son : adj[x]) {
        if (son != f && son != zSon[x]) {
            dfs2(son, x, false); 
        }
    }

    if (zSon[x]) {
        dfs2(zSon[x], x, true);
        is_heavy[zSon[x]] = true;
    }

    add(x, f, 1);
    for (auto &i : t) {
        for (auto &idx : mp[i]) st.insert(idx);
        mp[i].clear();
    }
    t.clear();
    if (zSon[x]) {
        is_heavy[zSon[x]] = false; 
    }

    if (!keep) {
        add(x, f, -1); 
    }
}


void solve(){
    int n, m;cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0, 1);
    for (int i = 1; i <= m; i++) {
        int x, s;cin >> x >> s;
        arr[x].push_back({s + deep[x], i});
    }
    dfs2(1, 0, 1);
    for (int i = 1; i <= m; i++) {
        if (st.count(i)) cout << 0;
        else cout << 1;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
