/*
4
1 aaa 1
2 aa
1 ab 2
2 bb

*/




#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int inf32 = 0x3f3f'3f3f;
constexpr int N = 14349907;
int mp[N];

void solve() {
    int q; cin >> q;

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            string s; int x; cin >> s >> x;
            int n = s.length();
            for (int i = 0; i < (1 << n); ++i) {
                int t = 0;
                for (int j = 4; j >= 0; --j) {
                    if (i >> j & 1) t = t * 27 + s[j] - 'a' + 1;
                    else            t = t * 27;
                }
                if (mp[t] != inf32) mp[t] = min(mp[t], x);
                else                mp[t] = x;
            }
        }
        else if (op == 2) {
            string s; cin >> s;
            int res = inf32, maxx = -1;
            int n = s.length();
            for (int i = 0; i < (1 << n); ++i) {
                int pp = __builtin_popcount(i);
                if (pp < maxx) continue;

                int t = 0;
                for (int j = 4; j >= 0; --j) {
                    if (i >> j & 1) t = t * 27 + s[j] - 'a' + 1;
                    else            t = t * 27;
                }

                if (mp[t] != inf32) {
                    if (pp == maxx) {
                        res = min(res, mp[t]);
                    }
                    else {
                        maxx = pp;
                        res = mp[t];
                    }
                }
            }
            cout << res << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T_ = 1;
    memset(mp, 0x3f, sizeof mp);
    // cin >> T_;
    while (T_--) solve();
}