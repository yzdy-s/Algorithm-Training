#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k, u, v;cin >> n >> k >> u >> v;
    int l = k - 1;
    int r = n - k;
    int res = l * u + r * v;

    if (1) {
        int cnt = r / 2;
        r %= 2;
        l += cnt;
        res = min(res, l * u + r * v);
        if (r && l >= 2) {
            r--;
            l--;
            res = min(res, l * u + r * v);
        }
    }


    
    l = k - 1;
    r = n - k;
    if (1) {
        int cnt = l / 2;
        l %= 2;
        r += cnt;
        res = min(res, l * u + r * v);
        if (l && r >= 2) {
            r--;
            l--;
            res = min(res, l * u + r * v);
        }
    }


    l = k - 1;
    r = n - k;
    while (l > 1 || r > 1) {
        if (l > 1) {
            int cnt = l / 2;

            l %= 2;
            r += cnt;
            res = min(res, l * u + r * v);

            if (l && r >= 2) {
                r--;
                l--;
                res = min(res, l * u + r * v);
                r++; l++;
            }
        }
        if (r > 1) {
            int cnt = r / 2;
            r %= 2;
            l += cnt;
            res = min(res, l * u + r * v);
            if (r && l >= 2) {
                r--;
                l--;
                res = min(res, l * u + r * v);
                r++; l++;
            }
        }
    }

    l = k - 1;
    r = n - k;
    while (l > 1 || r > 1) {
        if (r > 1) {
            int cnt = r / 2;
            r %= 2;
            l += cnt;
            res = min(res, l * u + r * v);
            if (r && l >= 2) {
                r--;
                l--;
                res = min(res, l * u + r * v);
                r++; l++;
            }
        }
        if (l > 1) {
            int cnt = l / 2;
            l %= 2;
            r += cnt;
            res = min(res, l * u + r * v);
            if (l && r >= 2) {
                r--;
                l--;
                res = min(res, l * u + r * v);
                r++; l++;
            }
        }
    }

    // cout << l << ' ' << r << endl;
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}