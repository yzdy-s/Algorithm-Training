#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k, t;cin >> n >> k >> t;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<int> vis(n + 1, 0);
    vector<int> L(n + 1, 0), R(n + 1, 0);
    vector<int> A(n + 1, 0);
    vector<int> RR(n + 1), LL(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int cur = i;
        vis[cur] = 1;
        cur = p[i];
        int mx = i, mn = i;
        while (1) {
            if (vis[cur]) break;
            vis[cur] = 1;
            mx = max(mx, cur);
            mn = min(mn, cur);
            cur = p[cur];
        }

        L[mn] = 1;
        R[mx] = 1;
        
        A[mn]++;
        A[mx]--;
        LL[mx] = mn;
        RR[mn] = mx;
    }
    for (int i = 1; i <= n; i++) A[i] += A[i - 1];
    //for (int i = 1; i <= n; i++) cout << A[i] << " \n"[i == n];

    int i = 1;
    int B = 0;
    int ans = 0;
    map<int, int> fr;
    
    int j = 1;
    for (; B < t&&j<=n; j++) {
        if (R[j] && i <= LL[j]) {
            B++;
        }
    }
    fr[A[i]]++;
    ans += fr[k - A[j]];
    for (; j <= n; j++) {
        if (R[j] && i <= LL[j]) {
            B++;
        }
        while (B >= t) {
            if (L[i] && j >= RR[i]) {
                if (B - 1 < t) break;
                B--;
            }
            i++;
            fr[A[i]]++;
            // cout << i << ' ' << j << endl;
        }
        if (B >= t) ans += fr[k - A[j]];
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}