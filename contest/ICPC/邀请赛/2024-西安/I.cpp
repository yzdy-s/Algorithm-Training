#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

void solve() {
    int n, k, m;cin >> n >> k >> m;
    map<PII, int> cnt;
    for (int i = 1; i <= m; i++) {
        int l, r;cin >> l >> r;
        cnt[{l, r}]++;
    }
    vector<int> c(n + 1), form(n + 1);
    for (auto &[PI, num] : cnt) {
        for (int i = PI.first; i <= PI.second; i++) {
            c[i] += num;
            form[i] += (PI.second - PI.first + 1);
        }
    }
    vector<bool> flag(n + 1);
    vector<int> ans(n + 1);
    for (int cur = k; cur >= 1; cur--) {
        vector<array<int, 3>> choose;
        for (int i = 1; i <= n; i++) {
            if (flag[i]) continue;
            choose.push_back({c[i], form[i], i});
        }
        sort(choose.begin(), choose.end(), greater<PII>());
        int aid = choose[0][2];
        ans[aid] = cur;
        for (auto &[PI, num] : cnt) {
            if (PI.first <= aid && aid <= PI.second) {
                num = 0;
                
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;// cin >> T;
    while (T--) solve();
}