#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define PIP pair<int, PII>
int n;
const int maxN = 500 + 7;
vector<PII> arr(maxN);
int dis[1007][1007];
int vis[1007][1007];


void dijkstra() {
    queue<PIP> pq;
    for (int i = 1; i <= n; i++) {
        int x = arr[i].first + 500;
        int y = arr[i].second + 500;
        dis[x][y] = 1;
        pq.push({1, {x, y}});
    }

    while (pq.size()) {
        int ops = pq.front().first;
        auto [x, y] = pq.front().second;
        if (x == 500 && y == 500) {
            cout << ops << endl;
            return;
        }
        pq.pop();
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        for (int i = 1; i <= n; i++) {
            int nx = x + arr[i].first;
            int ny = y + arr[i].second;
            if (nx >= 1000 || nx <= 0 || ny >= 1000 || ny <= 0) continue;
            if (ops + 1 < dis[nx][ny]) {
                dis[nx][ny] = ops + 1;
                pq.push({dis[nx][ny], {nx, ny}});
            }
        }
    }
    cout << -1 << endl;
}

void solve(){
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            dis[i][j] = INF;
            vis[i][j] = 0;
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;
    dijkstra();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
