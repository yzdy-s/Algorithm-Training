#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define PPP pair<PII, PII> // {{w, col}, {u, v}}
const int maxN = 5e4 + 7;
vector<int> fa(maxN);
vector<PPP> e;
int n, m, k;
int sum = 0;
int find(int x) {
    if (x == fa[x]) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

int check(int x) {
    for (int i = 0; i <= n; i++) fa[i] = i;
    vector<PPP> E;
    for (auto [a, edg] : e) {
        if (a.second == 0) a.first += x;
        E.push_back({a, edg});
    }
    sort(E.begin(), E.end());
    int cnt = 0;
    for (auto [a, edg] : E) {
        int u = edg.first;
        int v = edg.second;
        int u_fa = find(u);
        int v_fa = find(v);
        if (u_fa != v_fa) {
            cnt += (a.second == 0);
            fa[u_fa] = v_fa;
            sum += a.first;
        }
    }
    return cnt;
}

void solve(){
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w, col;cin >> u >> v >> w >> col;
        e.push_back({{w, col}, {u, v}});
    }

    int l = -1e12, r = 1e12;
    int ans = LNF;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        sum = 0;
        int cnt = check(mid);
        if (cnt >= k) {
            ans = sum - k * mid;
            l = mid;
        } else r = mid;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
