#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    string s;cin >> s;
    s = "#" + s;
    int ans = 0;
    int t = k;
    int f = 0;
    for (int r = 1; r <= n ; r++) {
        if (s[r] == '(') ans++;
        else {
            if (t == 0) break;
            else t--;
        }
    }
    // cout << ans << endl;
    int p = 1, q = 0, z = 0;
    while (p <= n) {
        while (p <= n && s[p] == '(') {
            p++;
            q++;
        }
        
        if (z <= k) ans = max(ans, min(q + (k - z), n / 2));

        while (p <= n && s[p] == ')') {
            p++;
            z++;
        }
    }

    int l = 1, r = 1;
    int a = 0, b = 0;
    while (l <= n) {
        while (l <= n && s[l] == '(') {
            l++;
            a--;
        }
        while (l <= n && s[l] == ')') {
            l++;
            b--;
        }
        if (l >= r) {
            r = l;
            a = 0, b = 0;
        }

        while (r <= n) {
            if (s[r] == '(') a++;
            else {
                b++;
                if (b > k) break;
            }
            ans = max(ans, a - b);
            r++;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}