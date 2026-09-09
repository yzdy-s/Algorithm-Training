#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, q;cin >> n >> q;
    string s;cin >> s;
    s = "#" + s;
    int cnt[n + 1][2][2] = {0};
    for (int i = 2; i <= n; i++) {
        for (int a = 0; a <= 1; a++) {
            for (int b = 0; b <= 1; b++) cnt[i][a][b] = cnt[i - 1][a][b];
        }
        cnt[i][s[i - 1] - '0'][s[i] - '0']++;
    }
    while (q--) {
        int l, r;cin >> l >> r;
        int c00 = cnt[r][0][0] - cnt[l][0][0];
        int c11 = cnt[r][1][1] - cnt[l][1][1];
        int c01 = cnt[r][0][1] - cnt[l][0][1];
        int c10 = cnt[r][1][0] - cnt[l][1][0];
        if (s[r] == '1') {
            if (s[l] == '0') c10++;
            else c11++;
        } else {
            if (s[l] == '0') c00++;
            else c01++;
        }
        int c0 = c00 + c01;
        int c1 = c10 + c11;
        // cout << c00 << ' ' << c11 << ' ' << c10 << ' ' << c01 << endl;
        // cout << c0 << ' ' << c1 << endl;
        int L = 0, R = 1e9;
        int res;
        int C00 = c00, C01 = c01, C11 = c11, C10 = c10;
        while (L + 1 < R) {
            int mid = L + R >> 1;
            c00 = C00; c01 = C01; c10 = C10; c11 = C11;
            int f = 1;
            if (mid < c01 || mid < c10) f = 0;
            if (c00 > mid) {
                c01 += c00 - mid;
                c10 += c00 - mid;
            }
            if (c11 > mid) {
                c01 += c11 - mid;
                c10 += c11 - mid;
            }
            if (c10 == c01 && c10 <= mid) f = 1;
            else f = 0;
            if (f) {
                R = mid;
                res = mid;
            } else L = mid;
        }
        cout << res * 4 - c0 - c1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
