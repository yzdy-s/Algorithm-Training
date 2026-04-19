#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e5 + 7;
vector<int> fa(maxN);

int find(int x) {
    if (x == fa[x]) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int u, int v) {
    int u_fa = find(u);
    int v_fa = find(v);
    if (u_fa != v_fa) {
        fa[v_fa] = fa[u_fa];
    }
}

void solve(){
    int n, x, y;cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) {
        if (i + x <= n) merge(i, i + x);
        if (i + y <= n) merge(i, i + y);
    }
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        int num = arr[i];
        if (find(num) != find(i)) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
