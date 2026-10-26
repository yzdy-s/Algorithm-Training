#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 3e4 + 7;
vector<int> adj[MAXN];
vector<int> deep(MAXN);

int ask(int u, int k) {
    cout << "? " << u << ' ' << k << endl;
    cout.flush();
    int res;cin >> res;
    return res;
}

bool check(int mid) {
    return ask(1, mid) == 1;
}

int ans;

void pre (int x, int fa) {
    if (adj[x].size() == 0) {
        deep[x] = 0;
        return;
    }

    for (auto &son : adj[x]) {
        pre(son, x);
    }
    for (auto &son : adj[x]) {
        deep[x] = max(deep[x], deep[son] + 1);
    }
}

void dfs(int x, int dis) {
    if (dis == 0) {
        ans = x;
        return;
    }
    if (adj[x].size() == 1) {
        dfs(adj[x][0], dis - 1);
    } else {
        int a = adj[x][0], b = adj[x][1];
        if (deep[a] < dis - 1) dfs(b, dis - 1);
        else if (deep[b] < dis - 1) dfs(a, dis - 1);
        else if (ask(a, dis - 1)) dfs(a, dis - 1);
        else dfs(b, dis - 1);
    }
}

void solve() {
    int n;cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        deep[i] = 0;
    }
    for (int i = 2; i <= n; i++) {
        int fa;cin >> fa;
        adj[fa].push_back(i);
    }
    int r = n , l = 0;
    int height = n;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid-1;
            height = min(height, mid);
        } else l = mid+1;
    }

    pre(1, 0);
    dfs(1, height);
    cout << height << endl;
    for (int i = 1; i <= n; i++) cout << deep[i] << " \n"[i == n];
    cout << "! " << ans << endl;
    cout.flush();
}

signed main() {
    int T = 1;cin >> T;
    while (T--) solve();
}