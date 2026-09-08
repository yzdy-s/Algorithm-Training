#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MAXN = 1e5 + 7;
vector<int> adj[MAXN];
vector<int> arr(MAXN);

vector<int> ans;
vector<int> t;
void dfs(int x, int fa, int k) {
    if (arr[x]) {
        if (k == 1) ans.push_back(x);
        else t.push_back(x);
        k = 1;
    }

    for (auto &son : adj[x]) {
        dfs(son, x, k);
    }
}

void solve(){
    int n;cin >> n;
    ans.clear();
    t.clear();
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        arr[i] = 0;
    }
    for (int i = 2; i <= n; i++) {
        int fa;cin >> fa;
        adj[fa].push_back(i);
    }

    int m;cin >> m;
    for (int i = 1; i <= m; i++) {
        int x;cin >> x;
        arr[x] = 1;
    }
    dfs(1, 0, 0);

    if (t.size()) t.pop_back();
    for (auto &i : t) ans.push_back(i);
    cout << ans.size() << ' ';
    for (auto &x : ans) cout << x << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
