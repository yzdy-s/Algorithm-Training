#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

vector<int> fa(2e5 + 7);

int find(int x) {
    if (x == fa[x]) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

void solve(){
    int n, k;cin >> n >> k;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> pos(k + 1);
    for (int i = 1; i <= k; i++) cin >> pos[i];
    
    for (int i = 1; i <= k; i++) fa[i] = i;
    for (int i = 1; i <= k; i++) {
        int cur = pos[i];
        int nx = pos[i + 1];
        int f = 1;
        for (int j = cur+1; j < nx; j++) {
            if (arr[j] == arr[cur]) {
                f = 0;
                break;
            }
        }
        if (f) {
            int c_fa = find(cur);
            int n_fa = find(nx);
            fa[n_fa] = c_fa;
            for (int j = cur; j <= nx; j++) arr[j] = arr[cur];
        }
    }
    vector<int> siz(k + 1);
    for (int i = 1; i <= n; i++) siz[find(i)]++;
    vector<int> vis(k + 1);

    int res = 0;
    int t = arr[pos[1]];
    vector<int> L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++) {
        if (arr[i] != t) {
            t ^= 1;
            res++;
        }
        L[i] = res;
    }
    t = arr[pos[1]]; res = 0;
    for (int i = n; i >= 1; i--) {
        if (arr[i] != t) {
            t ^= 1;
            res++;
        }
        R[i] = res;
    }
    // for (int i = 1; i <= n; i++) cout << L[i] << " \n"[i == n];
    // for (int i = 1; i <= n; i++) cout << R[i] << " \n"[i == n];

    for (int i = 1; i <= k; i++) {
        
    }
    int ans = LNF;
    
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}