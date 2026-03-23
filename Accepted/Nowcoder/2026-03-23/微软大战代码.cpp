#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define PCI pair<string, int>

const int maxN = 1e5 + 7;
vector<pair<char, int>> adj[maxN];
vector<int> dis(maxN, LNF);

void dijkstra(int st) {
    priority_queue<PCI, vector<PCI>, greater<PCI>> q;
    dis[st] = 0;
    q.push({"", 1});
    int cur = 1;
    while (q.size()) {
        int u = q.top().second;
        string s = q.top().first;
        dis[u] = cur++;
        q.pop();
        for (auto &i : adj[u]) {
            q.push({s+i.first, i.second});
        }
    }
}

void solve(){
    int n;cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        dis[i] = LNF;
    }
    for (int i = 2; i <= n; i++) {
        int x;cin >> x;
        char c;cin >> c;
        adj[x].push_back({c, i});
    }
    dijkstra(1);
    // for (int i = 1; i <= n; i++) cout << dis[i] << " \n"[i == n];
    vector<PII> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = {dis[i], i};
    }
    ranges::sort(ans.begin(), ans.end());
    for (int i = 1; i <= n; i++) cout << ans[i].second << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
