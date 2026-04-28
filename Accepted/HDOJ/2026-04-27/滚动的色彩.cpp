#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define PPP pair<PII, PII>
#define PIP pair<int, PPP>
const int maxN = 307;
vector<int> arr(maxN);
int adj[maxN][maxN][7][7];
int n, m;

vector<map<PII, PII>> a(4);
vector<PII> d = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}}; // 下  右  上  左

void pre() {
    map<PII, PII> LL, RR, UU, DD;
    map<PII, int> L, R, U, D;

    L[{1, 2}] = 3; L[{1, 3}] = 5; L[{1, 5}] = 4; L[{1, 4}] = 2;
    L[{6, 2}] = 4; L[{6, 3}] = 2; L[{6, 5}] = 3; L[{6, 4}] = 5;
    L[{2, 1}] = 4; L[{2, 4}] = 6; L[{2, 6}] = 3; L[{2, 3}] = 1;
    L[{5, 1}] = 3; L[{5, 4}] = 1; L[{5, 6}] = 4; L[{5, 3}] = 6;
    L[{3, 1}] = 2; L[{3, 2}] = 6; L[{3, 6}] = 5; L[{3, 5}] = 1;
    L[{4, 1}] = 5; L[{4, 2}] = 1; L[{4, 6}] = 2; L[{4, 5}] = 6;
 
    for (auto& it : L) {
        int down = it.first.first;
        int front = it.first.second;
        int left = it.second;
        
        int up = 7 - down;
        int right = 7 - left;
        int back = 7 - front;
        
        LL[{down, front}] = {left, front};
        RR[{down, front}] = {right, front};
        UU[{down, front}] = {back, down};
        DD[{down, front}] = {front, up};
    }

    a[0] = DD;
    a[1] = RR;
    a[2] = UU;
    a[3] = LL;
    // cout << DD[{6, 2}].second << endl;
}

void solve(){
    cin >> n >> m;
    vector<int> c(7);
    for (int i = 1; i <= 6; i++) cin >> c[i];
    int sx, sy, ex, ey, aid;cin >> sx >> sy >> ex >> ey >> aid;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= 6; k++) {
                for (int l = 1; l <= 6; l++) adj[i][j][k][l] = LNF;
            }
        }
    }

    adj[sx][sy][6][2] = 0;
    priority_queue<PIP, vector<PIP>, greater<PIP>> pq;
    pq.push({0, {{sx, sy}, {6, 2}}});
    while (pq.size()) {
        auto t = pq.top();pq.pop();
        int w = t.first;
        auto [cx, cy] = t.second.first;
        auto st = t.second.second;
        // 下  右  上  左
        for (int i = 0; i < 4; i++) {
            int nx = cx + d[i].first;
            int ny = cy + d[i].second;
            if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            int nw = w + 1;
            PII nSt = a[i][st];
            if (adj[nx][ny][nSt.first][nSt.second] > nw) {
                adj[nx][ny][nSt.first][nSt.second] = nw;
                pq.push({nw, {{nx, ny}, nSt}});
            }
        }
    }

    int res = LNF;
    for (int i = 1; i <= 6; i++) {
        if (c[i] == aid) {
            for (int j = 1; j <= 6; j++) {
                res = min(res, adj[ex][ey][i][j]);
            }
        }
    }
    cout << (res == LNF ? -1 : res) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    pre();
    int T = 1;cin >> T;
    while (T--) solve();
}
