#include<bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
constexpr int N = 100005;
using vl = vector<ll>;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        --a[i];
    }

    ll res = n, l = 0, r = 1e15;
    auto check = [&](ll q) -> bool {
        ll rem = q, remk = k;
        ll maxcnt = (rem + 1) / 2;

        // b, rem, remk
        for (int i = 1; i <= n; ++i) {
            ll need = q;
            if (need <= a[i]) continue;
            need -= a[i];
            if (need) {
                ll t = min({need, rem, maxcnt});
                need -= t;
                rem -= t;
            }
            if (need) {
                ll t = min(need, remk);
                need -= t;
                remk -= t;
            }
            if (need) return 0;
        }
        res = max(res, n + q * (n - 1));

        rem = q + 1, remk = k;
        maxcnt = (rem + 1) / 2;

        vector<ll> b = a;
        vector<ll> used(n + 1); ll maxuse = 0;
        // b, rem, remk
        for (int i = 1; i <= n; ++i) {
            ll need = q;
            if (need) {
                ll t = min(need, b[i]);
                need -= t;
                b[i] -= t;
            }
            if (need) {
                ll t = min({need, rem, maxcnt});
                need -= t;
                rem -= t;
                used[i] += t;
                maxuse = max(maxuse, used[i]);
            }
            if (need) {
                ll t = min(need, remk);
                need -= t;
                remk -= t;
            }
            if (need) return 0;
        }
        
        ll ans = n + q * (n - 1);
        ll tot = 0;
        bool f = remk > 0 || rem > 0;
        for (int i = 1; i <= n; ++i) {
            if (b[i]) ++tot;
            if (b[i] && (  (q + q + 1) / 2 == used[i] || (q + q + 1) / 2 != maxuse ) ) {
                f = 1;
            }
        }

        // if (q == 1) {
        //     cout << maxuse << ' ' << (q + q + 1) / 2 << '\n';
        //     for (int i = 1; i <= n; ++i) cout << used[i] << " \n"[ i == n ];
        //     for (int i = 1; i <= n; ++i) cout << b[i] << " \n"[ i == n ];
        // }
        // if (q == 1) cout << " ???  " << f << " " << tot << '\n';
        // if (q == 1) cout << tot << ' ' << remk << ' ' << rem << '\n';
        if (f && tot >= rem) res = max(res, ans + min(tot - rem + remk, n));

        res = max(res, ans);

        return 1;
    };
    
    while (l + 1 < r) {
        ll m = l + r >> 1;
        if (check(m)) l = m;
        else r = m;
    }







    {
        bool ok = 1;
        ll q = 0;
        ll rem = q + 1, remk = k;
        ll maxcnt = (rem + 1) / 2;

        vector<ll> b = a;
        vector<ll> used(n + 1); ll maxuse = 0;
        // b, rem, remk
        for (int i = 1; i <= n && ok; ++i) {
            ll need = q;
            if (need) {
                ll t = min(need, b[i]);
                need -= t;
                b[i] -= t;
            }
            if (need) {
                ll t = min({need, rem, maxcnt});
                need -= t;
                rem -= t;
                used[i] += t;
                maxuse = max(maxuse, used[i]);
            }
            if (need) {
                ll t = min(need, remk);
                need -= t;
                remk -= t;
            }
            if (need) ok = 0;
        }
        
        if (ok) {
            ll ans = n + q * (n - 1);
            ll tot = 0;
            bool f = remk > 0 || rem > 0;
            for (int i = 1; i <= n; ++i) {
                if (b[i]) ++tot;
                if (b[i] && (  (q + q + 1) / 2 == used[i] || (q + q + 1) / 2 != maxuse ) ) {
                    f = 1;
                }
            }
    
            if (f && tot >= rem) res = max(res, ans + min(tot - rem + remk, n));
    
            res = max(res, ans);
        }
    }

    cout << res << '\n';
}

signed main() {
    int T = 1; cin >> T;
    while (T--) solve();
}