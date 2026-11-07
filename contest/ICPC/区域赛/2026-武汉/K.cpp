#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inv(x) ksm(x, MOD - 2)
const int MOD = 998244353;
const int MAXN = 2e5 + 7;

using vi = vector<int>;
using vvi = vector<vi>;

vector<int> fr[MAXN], adj[MAXN];
vector<int> cnt(MAXN), dp(MAXN);
vector<int> A(MAXN);
int ru[MAXN];
int ksm(int a, int b) {
    int res = 1;
    a %= MOD;
    while(b) {
        if(b &1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int t = 1;
void dfs(int x, int fa) {
    for (auto &son : adj[x]) {
        if (son == fa) continue;
        dfs(son, x);
        cnt[x] += cnt[son];
    }

    int cur = 1;
    dp[x] = (dp[x] * A[cnt[x] - 1]) % MOD;
    for (auto &son : adj[x]) {
        if (son == fa) continue;
        dp[x] = (dp[x] * dp[son]) % MOD;
        dp[x] = (dp[x] * inv(A[cnt[son]])) % MOD;
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i <= n; i++) {
        fr[i].clear();
        adj[i].clear();
        dp[i] = 1;
        cnt[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        int fa; cin >> fa;
        fr[fa].push_back(i);
    }

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vi ind(n + 1), outd(n + 1);
    for (int u = 1; u <= n; ++u) {
        for (int v : fr[u]) {            
            if      (b[u] < a[v]) {
                adj[v].emplace_back(u);
                ++outd[v];
                ++ind[u];

                adj[u].emplace_back(v);
            }
            else if (a[u] < b[v]) {
                adj[u].emplace_back(v);
                ++outd[u];
                ++ind[v];
                
                adj[v].emplace_back(u);
            }
        }
    }

    vi vis(n + 1), tempfa(n + 1);
    int in0 = -1, out0 = -1, sz = 0, cntin0 = 0, cntout0 = 0;
    auto dfszz = [&](auto &&self, int u) -> void {
        vis[u] = 1; ++sz;
        if (ind[u] == 0) { in0 = u; ++cntin0; }
        if (outd[u] == 0) { out0 = u; ++cntout0; }

        for (int v : adj[u]) {
            if (v == tempfa[u]) continue;
            tempfa[v] = u;
            self(self, v);      
        }
    };

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            in0 = -1; out0 = -1; sz = 0; cntin0 = 0; cntout0 = 0;
            dfszz(dfszz, i);
            if (cntin0 == 1) adj[0].emplace_back(in0);
            else             adj[0].emplace_back(out0);
        }
    }

    dfs(0, -1);
    // cout << "+++++++++" << endl;
    // for (int i = 0; i <= n; i++) {
    //     cout << i << ':';
    //     for (auto &j : adj[i]) cout << j << ' ';
    //     cout << endl;
    // }
    // cout << "+++++++++" << endl;
    // for (int i = 0; i <= n; i++) cout << cnt[i] << " \n"[i == n];
    cout << dp[0] << '\n';
}

signed main() {
    A[0] = 1;
    for (int i = 1; i <= 2e5 + 5; i++) A[i] = A[i - 1] * i % MOD;
    int T_ = 1;
    cin >> T_;
    while (T_--) solve();
}