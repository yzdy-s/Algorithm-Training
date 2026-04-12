#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>


const int maxN = 1e5 + 7;
vector<int> fa(maxN);

int find(int x) {
    if (x == fa[x]) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

void solve(){
    int n, m;cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v;cin >> u >> v;
        int u_fa = find(u);
        int v_fa = find(v);
        if (u_fa != v_fa) fa[u_fa] = v_fa;
    }
    vector<int> siz(n + 1);
    for (int i = 1; i <= n; i++) {
        int root = find(i);
        siz[root]++;
    }
    int cnt1 = 0;
    int cnt2 = 0;
    int res = 0;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (siz[i] == 0) continue;

        if (siz[i] == 1) cnt1++;
        else {
            res += siz[i];
            cnt2++;
        }
        tot++;
    }
    if (tot == 1) {
        cout << "0 0" << endl;
        return;
    }
    res = res - (cnt2 - 1) * 2;
    cout << tot - 1 << ' ';
    if (res >= cnt1) cout << 1;
    else cout << 2;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
